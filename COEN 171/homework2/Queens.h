//File: Queens.h
//Name: Gagan Gupta
//Date: 10/25/20
//Assignment: COEN 171 Homework 2 Part 2

# ifndef QUEENS_H
# define QUEENS_H
# include <cstdlib>

// An abstract chess piece that cannot be instantiated.
class Piece {
protected:
    int _row, _column;

public:
    int row() const {
	return _row;
    }

    int column() const {
	return _column;
    }

    void place(int row, int column) {
	_row = row;
	_column = column;
    }

    virtual bool menaces(const Piece *p) const = 0;
};

class Rook : virtual public Piece{   
public:
    virtual bool menaces(const Piece *p) const{
		if(p->row()==_row || p->column()==_column){
			return true;
		}
		return false;
	}
};

class Bishop : virtual public Piece{
public:
    virtual bool menaces(const Piece *p) const{
		int rows = abs(_row-p->row());
		int cols = abs(_column-p->column());
		return ((rows-cols)==0);
	}
};

class Queen : virtual public Rook, virtual public Bishop{
public:
    virtual bool menaces(const Piece *p) const{
		return Rook::menaces(p) || Bishop::menaces(p);
	}
};

class Knight : virtual public Piece{
public:
    virtual bool menaces(const Piece *p) const{
		int rows = abs(_row-p->row());
		int cols = abs(_column-p->column());
		return (rows==2 && cols==1) || (rows==1 && cols==2);
	}
};

class Amazon : virtual public Knight, virtual public Queen{ 
public:
    virtual bool menaces(const Piece *p) const{
		return Knight::menaces(p) || Queen::menaces(p);
	}
};

# endif /* QUEENS_H */
