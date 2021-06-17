% incorrectly gives two responses if X >= Y.

maximum(X,Y,X) :- X >= Y.
maximum(_,Y,Y).


% fixed version using a red cut

maximum2(X,Y,X) :- X >= Y, !.
maximum2(_,Y,Y).


% fixed version using a green cut

maximum3(X,Y,X) :- X >= Y, !.
maximum3(X,Y,Y) :- X < Y.
