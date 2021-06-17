# include <iostream>
# include "machine.h"
# include "Label.h"

unsigned Label::_counter=0;

Label::Label(){
	_number = _counter++;
}

unsigned Label::number() const{
	return _number;
}

std::ostream& operator << (std::ostream& ostr, const Label& label)
{
    return ostr << label_prefix << label.number();
}
