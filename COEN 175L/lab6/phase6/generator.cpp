/*
 * File:	generator.cpp
 *
 * Description:	This file contains the public and member function
 *		definitions for the code generator for Simple C.
 *
 *		Extra functionality:
 *		- putting all the global declarations at the end
 */

# include <cassert>
# include <iostream>
# include <sstream>
# include "generator.h"
# include "machine.h"
# include "Tree.h"
# include "Label.h"

using namespace std;

static int offset;
static Label* returnLabel;
static vector<string> strs;
static string funcname;
static ostream &operator <<(ostream &ostr, Expression *expr);

static Register *eax = new Register("%eax", "%al");
static Register *ecx = new Register("%ecx", "%cl");
static Register *edx = new Register("%edx", "%dl");

static vector<Register *> registers = {eax, ecx, edx};


/* These will be replaced with functions in the next phase.  They are here
   as placeholders so that Call::generate() is finished. 

# define assign(node,reg)
# define load(node,reg) */

void assign(Expression *expr, Register *reg){
	if (expr != nullptr) {
		if (expr->_register != nullptr)
			expr->_register->_node = nullptr;
		expr->_register = reg;
	}
	if (reg!= nullptr) {
		if (reg->_node != nullptr)
			reg->_node->_register = nullptr;
		reg->_node = expr;
	}
}

void load(Expression *expr, Register *reg){
	if (reg->_node != expr) {
		if (reg->_node != nullptr) {
			offset -= reg->_node->type().size();
			reg->_node->_offset = offset;
			if (reg->_node->type().size() == 1){
				cout<< "\tmovb\t" << reg << ", ";
				cout<< offset << "(%ebp)" << endl;
			}
			else{
				cout<< "\tmovl\t" << reg << ", ";
				cout<< offset << "(%ebp)" << endl;
			}
		}
		if (expr != nullptr) {
			cout<< (expr->type().size() == 1 ? "\tmovsbl\t" : "\tmovl\t") << expr << ", " << reg<< endl;
		}
		assign(expr, reg);
	}
}

Register *getreg(){
	for (auto reg: registers)
		if (reg->_node == nullptr)
			return reg;
	load(nullptr, registers[0]);
	return registers[0];
}

/*
 * Function:	align (private)
 *
 * Description:	Return the number of bytes necessary to align the given
 *		offset on the stack.
 */

static int align(int offset)
{
    if (offset % STACK_ALIGNMENT == 0)
	return 0;

    return STACK_ALIGNMENT - (abs(offset) % STACK_ALIGNMENT);
}


/*
 * Function:	operator << (private)
 *
 * Description:	Convenience function for writing the operand of an
 *		expression using the output stream operator.
 */

static ostream &operator <<(ostream &ostr, Expression *expr)
{
    if (expr->_register != nullptr)
	return ostr << expr->_register;

    expr->operand(ostr);
    return ostr;
}


/*
 * Function:	Expression::operand
 *
 * Description:	Write an expression as an operand to the specified stream.
 */

void Expression::operand(ostream &ostr) const
{
    //assert(_offset != 0);
    ostr << _offset << "(%ebp)";
}


/*
 * Function:	Identifier::operand
 *
 * Description:	Write an identifier as an operand to the specified stream.
 */

void Identifier::operand(ostream &ostr) const
{
    if (_symbol->_offset == 0)
	ostr << global_prefix << _symbol->name();
    else
	ostr << _symbol->_offset << "(%ebp)";
}


/*
 * Function:	Number::operand
 *
 * Description:	Write a number as an operand to the specified stream.
 */

void Number::operand(ostream &ostr) const
{
    ostr << "$" << _value;
}


void String::operand(ostream& ostr) const{
	Label lbl;
	stringstream s;
	ostr << lbl;
	s << lbl << ":\n\t.string \"" << _value << "\"" << endl;
    strs.push_back(s.str());
}


/*
 * Function:	Call::generate
 *
 * Description:	Generate code for a function call expression.
 *
 * 		On a 32-bit Linux platform, the stack needs to be aligned
 * 		on a 4-byte boundary.  (Online documentation seems to
 * 		suggest that 16 bytes are required, but 4 bytes seems to
 * 		work and is much easier.)  Since all arguments are 4-bytes
 *		wide, the stack will always be aligned.
 *
 *		On a 32-bit OS X platform, the stack needs to aligned on a
 *		16-byte boundary.  So, if the stack will not be aligned
 *		after pushing the arguments, we first adjust the stack
 *		pointer.  However, this trick only works if none of the
 *		arguments are themselves function calls.
 *
 *		To handle nested function calls, we need to generate code
 *		for the nested calls first, which requires us to save their
 *		results and then push them on the stack later.  For
 *		efficiency, we only first generate code for the nested
 *		calls, but generate code for ordinary arguments in place.
 */

void Call::generate()
{
    unsigned numBytes;


    /* Generate code for any nested function calls first. */

    numBytes = 0;

    for (int i = _args.size() - 1; i >= 0; i --) {
	numBytes += _args[i]->type().size();

	if (STACK_ALIGNMENT != SIZEOF_ARG && _args[i]->_hasCall)
	    _args[i]->generate();
    }


    /* Align the stack if necessary. */

    if (align(numBytes) != 0) {
	cout << "\tsubl\t$" << align(numBytes) << ", %esp" << endl;
	numBytes += align(numBytes);
    }


    /* Generate code for any remaining arguments and push them on the stack. */

    for (int i = _args.size() - 1; i >= 0; i --) {
	if (STACK_ALIGNMENT == SIZEOF_ARG || !_args[i]->_hasCall)
	    _args[i]->generate();

	cout << "\tpushl\t" << _args[i] << endl;
	assign(_args[i], nullptr);
    }


    /* Call the function and then reclaim the stack space. */

    load(nullptr, eax);
    load(nullptr, ecx);
    load(nullptr, edx);

    cout << "\tcall\t" << global_prefix << _id->name() << endl;

    if (numBytes > 0)
	cout << "\taddl\t$" << numBytes << ", %esp" << endl;

    assign(this, eax);
}


/*
 * Function:	Block::generate
 *
 * Description:	Generate code for this block, which simply means we
 *		generate code for each statement within the block.
 */

void Block::generate()
{
    for (auto stmt : _stmts) {
		stmt->generate();

		// for (auto reg : registers){
			// cerr<<reg<<endl;
			// assert(reg->_node == nullptr);
		// }
    }
}


/*
 * Function:	Simple::generate
 *
 * Description:	Generate code for a simple (expression) statement, which
 *		means simply generating code for the expression.
 */

void Simple::generate()
{
    _expr->generate();
    assign(_expr, nullptr);
}


/*
 * Function:	Function::generate
 *
 * Description:	Generate code for this function, which entails allocating
 *		space for local variables, then emitting our prologue, the
 *		body of the function, and the epilogue.
 */

void Function::generate()
{
    int param_offset;
	returnLabel = new Label();

    /* Assign offsets to the parameters and local variables. */

    param_offset = 2 * SIZEOF_REG;
    offset = param_offset;
    allocate(offset);


    /* Generate our prologue. */

    funcname = _id->name();
    cout << global_prefix << funcname << ":" << endl;
    cout << "\tpushl\t%ebp" << endl;
    cout << "\tmovl\t%esp, %ebp" << endl;
    cout << "\tsubl\t$" << funcname << ".size, %esp" << endl;


    /* Generate the body of this function. */

    _body->generate();


    /* Generate our epilogue. */
	
	cout << *returnLabel << ":" << endl;
    cout << endl << global_prefix << funcname << ".exit:" << endl;
    cout << "\tmovl\t%ebp, %esp" << endl;
    cout << "\tpopl\t%ebp" << endl;
    cout << "\tret" << endl << endl;

    offset -= align(offset - param_offset);
    cout << "\t.set\t" << funcname << ".size, " << -offset << endl;
    cout << "\t.globl\t" << global_prefix << funcname << endl << endl;
}


/*
 * Function:	generateGlobals
 *
 * Description:	Generate code for any global variable declarations.
 */

void generateGlobals(Scope *scope)
{
    const Symbols &symbols = scope->symbols();
	
	for (auto str : strs)
		cout << str << endl;
	
    for (auto symbol : symbols)
		if (!symbol->type().isFunction()) {
			cout << "\t.comm\t" << global_prefix << symbol->name() << ", ";
			cout << symbol->type().size() << endl;
		}
}


/*
 * Function:	Assignment::generate
 *
 * Description:	Generate code for an assignment statement.
 *
 *		NOT FINISHED: Only works if the right-hand side is an
 *		integer literal and the left-hand side is an integer
 *		scalar.
 */

void Assignment::generate(){
    Expression *pointer;
	_right->generate();
	cout << "\tmovl\t" << _right << ", %eax" << endl;
	if(_left->isDereference(pointer)){
		pointer->generate();
		load(pointer, getreg());
		load(_right, getreg());
		cout << "\tmovl\t" << pointer << ",%ecx" << endl; 
		if (_right->type().size() == 1) 
			cout << "\tmovb\t%al,(%ecx)" << endl;
	    else 
			cout << "\tmovl\t%eax,(%ecx)" << endl; 	
	}
	else{
		_left->generate();
		load(_right, getreg());
		if (_right->type().size() == 1)
   			cout << "\tmovsbl\t%al," << _left << endl; 
		else 
			cout << "\tmovl\t%eax, " << _left << endl;
	}
}

void Cast::generate(){
	_expr->generate();
    if (_expr->_register == nullptr)
        load(_expr, getreg());
    if (_type.size() <= _expr->type().size())
        assign(this, _expr->_register);
}

void Add::generate(){
	_left->generate();
	_right->generate();
	if (_left->_register == nullptr)
		load(_left, getreg());
	cout<< "\taddl\t" << _right << ", " << _left << endl;
	assign(_right, nullptr);
	assign(this, _left->_register);
}

void Subtract::generate(){
	_left->generate();
	_right->generate();
	if (_left->_register == nullptr)
		load(_left, getreg());
	cout<< "\tsubl\t" << _right << ", " << _left << endl;
	assign(_right, nullptr);
	assign(this, _left->_register);
}

void Multiply::generate(){
	_left->generate();
	_right->generate();
	if (_left->_register == nullptr)
		load(_left, getreg());
	cout<< "\timul\t" << _right << ", " << _left << endl;
	assign(_right, nullptr);
	assign(this, _left->_register);
}

void Divide::generate(){
	_left->generate();
	_right->generate();
	if (_left->_register == nullptr)
		load(_left, eax);
	cout << "\tcltd" << endl;
    cout << "\tidivl\t" << _right << endl;
	assign(this, eax);
}

void Remainder::generate(){
	_left->generate();
	_right->generate();
	if (_left->_register == nullptr)
		load(_left, eax);
	cout << "\tcltd" << endl;
    cout << "\tidivl\t" << _right << endl;
	assign(this, edx);
}

void Negate::generate(){
	_expr->generate();
    if (_expr->_register == nullptr)
		load(_expr, getreg());
    cout << "\tneg\t" << _expr << endl;
    assign(this, _expr->_register);
    assign(_expr, nullptr);
}

void Dereference::generate(){
	_expr->generate();
	if(_expr->_register==nullptr)
		load(_expr, getreg());
	if (_expr->type().size() == 1)
		cout << "\tmovsbl\t(" << _expr << "), " << _expr << endl;
	else
		cout << "\tmovl\t(" << _expr << "), " << _expr << endl;
	assign(this, _expr->_register);
}

void Address::generate(){
	Expression *pointer;
	if(_expr->isDereference(pointer)){
		pointer->generate();
		if(pointer->_register==nullptr)
			load(pointer, getreg());
		assign(this, pointer->_register);
	}
	else{
		assign(this, getreg());
		cout << "\tleal\t" << _expr << ", %eax" << endl;
		cout << "\tmovl\t%eax, " << this << endl;
	}
}

void Not::generate(){
	_expr->generate();
    if (_expr->_register == nullptr){
        load(_expr, getreg());
	}
	
	if (_expr->type().size() == 1){
		cout << "\tcmpb\t$0, " << _expr << endl;
	}
	else if (_expr->type().size() == 4){
		cout << "\tcmpl\t$0, " << _expr << endl;
	}
	else{
		cout << "\tcmpq\t$0, " << _expr << endl;
	}
	
    cout << "\tsete\t" << _expr->_register->byte() << endl;
    cout << "\tmovzbl\t" << _expr->_register->byte() << ", " << _expr << endl;
    assign(this, _expr->_register);
    assign(_expr, nullptr);
}

void Expression::test(const Label& lbl, bool isTrue){
    generate();
    if (_register == nullptr){
        load(this, getreg());
	}
	
	if (this->type().size() == 1){
		cout << "\tcmpb\t" << "$0, " << this << endl;
	}
	else if (this->type().size() == 4){
		cout << "\tcmpl\t" << "$0, " << this << endl;
	}
	else{
		cout << "\tcmpq\t" << "$0, " << this << endl;
	}
	
	if(isTrue){
		cout << "\tjne\t" << lbl << endl;
	}
	else{
		cout << "\tje\t" << lbl << endl;
	}
    assign(this, nullptr);
}

void LessThan::test(const Label& lbl, bool isTrue){
	_left->generate();
    _right->generate();
    if (_left->_register == nullptr){
        load(_left, getreg());
	}
	
	if (_left->type().size() == 1){
		cout << "\tcmpb\t" << _right << ", " << _left << endl;
	}
	else if (_left->type().size() == 4){
		cout << "\tcmpl\t" << _right << ", " << _left << endl;
	}
	else{
		cout << "\tcmpq\t" << _right << ", " << _left << endl;
	}
	
	if(isTrue){
		cout << "\tjl\t" << lbl << endl;
	}
	else{
		cout << "\tjge\t" << lbl << endl;
	}
	
    assign(_left, nullptr);
    assign(_right, nullptr);
}

void GreaterThan::test(const Label& lbl, bool isTrue){
	_left->generate();
    _right->generate();
    if (_left->_register == nullptr){
        load(_left, getreg());
	}
	
    if (_left->type().size() == 1){
		cout << "\tcmpb\t" << _right << ", " << _left << endl;
	}
	else if (_left->type().size() == 4){
		cout << "\tcmpl\t" << _right << ", " << _left << endl;
	}
	else{
		cout << "\tcmpq\t" << _right << ", " << _left << endl;
	}
	
	if(isTrue){
		cout << "\tjg\t" << lbl << endl;
	}
	else{
		cout << "\tjle\t" << lbl << endl;
	}
    assign(_left, nullptr);
    assign(_right, nullptr);
}

void LessOrEqual::test(const Label& lbl, bool isTrue){
	_left->generate();
    _right->generate();
    if (_left->_register == nullptr){
        load(_left, getreg());
	}
	
	if (_left->type().size() == 1){
		cout << "\tcmpb\t" << _right << ", " << _left << endl;
	}
	else if (_left->type().size() == 4){
		cout << "\tcmpl\t" << _right << ", " << _left << endl;
	}
	else{
		cout << "\tcmpq\t" << _right << ", " << _left << endl;
	}
	
	if(isTrue){
		cout << "\tjle\t" << lbl << endl;
	}
	else{
		cout << "\tjg\t" << lbl << endl;
	}
	
    assign(_left, nullptr);
    assign(_right, nullptr);
}

void GreaterOrEqual::test(const Label& lbl, bool isTrue){
	_left->generate();
    _right->generate();
    if (_left->_register == nullptr){
        load(_left, getreg());
	}
	
    if (_left->type().size() == 1){
		cout << "\tcmpb\t" << _right << ", " << _left << endl;
	}
	else if (_left->type().size() == 4){
		cout << "\tcmpl\t" << _right << ", " << _left << endl;
	}
	else{
		cout << "\tcmpq\t" << _right << ", " << _left << endl;
	}
	
	if(isTrue){
		cout << "\tjge\t" << lbl << endl;
	}
	else{
		cout << "\tjl\t" << lbl << endl;
	}
	
    assign(_left, nullptr);
    assign(_right, nullptr);
}

void Equal::test(const Label& lbl, bool isTrue){
	_left->generate();
    _right->generate();
    if (_left->_register == nullptr){
        load(_left, getreg());
	}
	
    if (_left->type().size() == 1){
		cout << "\tcmpb\t" << _right << ", " << _left << endl;
	}
	else if (_left->type().size() == 4){
		cout << "\tcmpl\t" << _right << ", " << _left << endl;
	}
	else{
		cout << "\tcmpq\t" << _right << ", " << _left << endl;
	}
	
	if(isTrue){
		cout << "\tje\t" << lbl << endl;
	}
	else{
		cout << "\tjne\t" << lbl << endl;
	}
	
    assign(_left, nullptr);
    assign(_right, nullptr);
}

void NotEqual::test(const Label& lbl, bool isTrue){
	_left->generate();
    _right->generate();
    if (_left->_register == nullptr){
        load(_left, getreg());
	}
	
    if (_left->type().size() == 1){
		cout << "\tcmpb\t" << _right << ", " << _left << endl;
	}
	else if (_left->type().size() == 4){
		cout << "\tcmpl\t" << _right << ", " << _left << endl;
	}
	else{
		cout << "\tcmpq\t" << _right << ", " << _left << endl;
	}
	
	if(isTrue){
		cout << "\tjne\t" << lbl << endl;
	}
	else{
		cout << "\tje\t" << lbl << endl;
	}
	
    assign(_left, nullptr);
    assign(_right, nullptr);
}

void LogicalAnd::test(const Label& lbl, bool isTrue){
	_left->test(lbl, false);
    _right->test(lbl, false);
}

void LogicalOr::test(const Label& lbl, bool isTrue){
	Label temp;
    _left->test(temp, true);
    _right->test(lbl, false);
    cout << temp << ":" << endl;
    cout << "\tmovl\t$1, %eax" << endl;
}

void Return::generate(){
	_expr->generate();
	if (_expr->type().size() == 1)
		cout << "\tmovb\t" << _expr << ", %eax" << endl;
	else if (_expr->type().size() == 4)
		cout << "\tmovl\t" << _expr << ", %eax" << endl;
	else
		cout << "\tmovq\t" << _expr << ", %eax" << endl;
	
    cout << "\tjmp\t" << *returnLabel << endl;
	assign(_expr, nullptr);
}

void While::generate(){
	Label loop, exit;
    cout << loop << ":" << endl;
    _expr->test(exit, false);
    _stmt->generate();
    cout << "\tjmp\t" << loop << endl;
    cout << exit << ":" << endl;
}

void For::generate(){
	Label loop, exit;
	_init->generate();
    cout << loop << ":" << endl;
    _expr->test(exit, false);
    cout << "\tmovl\t" << _expr << ", %eax" << endl;
    cout << "\tcmpl\t$0, %eax" << endl;
    cout << "\tje\t" << exit << endl;
    _stmt->generate();
    _incr->generate();
    cout << "\tjmp\t" << loop << endl;
    cout << exit << ":" << endl;
}

void If::generate(){
	Label temp, exit;
    _expr->test(temp, true);
    _thenStmt->generate();
    if(_elseStmt!=nullptr){
        cout << "\tjmp\t" << exit << endl;
        cout << temp << ":" << endl;
        _elseStmt->generate();
        cout << exit << ":" << endl;
    }
    else
        cout << temp << ":" << endl;
}
