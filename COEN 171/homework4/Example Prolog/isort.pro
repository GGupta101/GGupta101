insert(X,[],[X]).
insert(X,[H|T],[X,H|T]) :- X < H.
insert(X,[H|T],[H|L]) :- X >= H, insert(X,T,L).

isort([],[]).
isort([H|T],X) :- isort(T,Y), insert(H,Y,X).


insert2(X,[],[X]).
insert2(X,[H|T],[X,H|T]) :- X < H, !.			% for correctness
insert2(X,[H|T],[H|L]) :- insert2(X,T,L).

isort2([],[]).
isort2([H|T],X) :- isort2(T,Y), !, insert2(H,Y,X).	% for efficiency
