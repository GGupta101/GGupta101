% which cut is red and which cut is green?

add(X,[],[X]) :- !.
add(X,[X|T],[X|T]) :- !.
add(X,[H|Y],[H|Z]) :- add(X,Y,Z).
