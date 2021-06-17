{
Name: Gagan Gupta 
Date: 10/06/20
Title: COEN 171 - HW 1
Description: BST in Pascal, Translated from C
	Reads a list of integers from standard input and inserts them into
	a binary search tree.  Then, reads a list of integers from standard
	input and checks if each integer is present in the tree.  Both
	lists are terminated by -1.
}

program pascalBST(input, output);
	//Define the node structure
	type tree=^node;
		node=record
			info:integer;
			left:tree;
			right:tree;
	end;

	//Insert is a procedure that changes the tree by reference
	procedure insert(var root:tree;value:integer);
	begin
		if root=nil then 
		begin
			new(root);
			root^.left:=nil;
			root^.right:=nil;
			root^.info:=value
		end
		else if root^.info<value then 
			insert(root^.right,value)
		else if root^.info>value then
			insert(root^.left,value);
	end;
	
	//Member is  a function as it returns an integer which represents a boolean
	function member(var root:tree;value:integer):integer;
	begin
		if root=nil then
			exit(0)
		else if root^.info=value then
			exit(1)
		else if root^.info<value then
			exit(member(root^.right,value))
		else 
			exit(member(root^.left,value))
	end;

	//Define the tree and the integer outside and before the main
	var t:tree; 
	x:integer;
	
begin
	//Input values into the tree using insert
	t := nil;
	readln(x);
	while x<>-1 do begin
		insert(t, x);
		readln(x);
	end;
	readln(x);
	//Test if values are in the tree with member
	while x<>-1 do begin
		if member(t,x)=1 then
			writeln('true')
		else
			writeln('false');
		readln(x);
	end;
end.   