% farmer-wolf-goat-cabbage problem

not(X) :- X, !, fail.
not(_).

flipped(west,east).
flipped(east,west).

move([X,W,G,C],[Y,W,G,C]) :- flipped(X,Y).
move([X,X,G,C],[Y,Y,G,C]) :- flipped(X,Y).
move([X,W,X,C],[Y,W,Y,C]) :- flipped(X,Y).
move([X,W,G,X],[Y,W,G,Y]) :- flipped(X,Y).

unsafe([X,Y,Y,_]) :- flipped(X,Y).
unsafe([X,_,Y,Y]) :- flipped(X,Y).

s(X,Y) :- move(X,Y), not(unsafe(Y)).

goal([east,east,east,east]).


solve(Node, Solution) :-
    depthfirst([], Node, Solution).

depthfirst(Path, Node, [Node|Path]) :-
    goal(Node).

depthfirst(Path, Node, Sol) :-
    s(Node, Node1),
    not(member(Node1, Path)),
    depthfirst([Node|Path], Node1, Sol).


limited_depthfirst(Node, [Node], _) :-
    goal(Node).

limited_depthfirst(Node, [Node|Sol], Maxdepth) :-
    Maxdepth > 0,
    s(Node, Node1),
    Max1 is Maxdepth - 1,
    limited_depthfirst(Node1, Sol, Max1).


depth_first_iterative_deepening(Node, Solution) :-
    path(Node, GoalNode, Solution),
    goal(GoalNode).

path(Node, Node, [Node]).

path(FirstNode, LastNode, [LastNode|Path]) :-
    path(FirstNode, OneButLast, Path),
    s(OneButLast, LastNode),
    not(member(LastNode, Path)).
