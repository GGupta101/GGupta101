myappend([],Y,Y).
myappend([H|X],Y,[H|Z]) :- myappend(X,Y,Z).

myprefix(X,Z) :- myappend(X,_,Z).
mysuffix(Y,Z) :- myappend(_,Y,Z).
mysublist(S,Z) :- myprefix(X,Z), mysuffix(S,X).
