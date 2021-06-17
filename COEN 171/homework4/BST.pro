% Gagan Gupta
% 12/01/20
% COEN 171 Homework 4 - Binary Search Tree

% If empty then insert at current position
insert(X, empty, node(X,empty,empty)):- !.
% If X is less than node data then insert left else insert right
insert(X, node(D,L,R), node(D,NL,R)):- X<D, !, insert(X,L,NL).
insert(X, node(D,L,R), node(D,L,NR)):- insert(X,R,NR).

% If X is equal to node data then true
exists(X, node(X,_,_)).
% If X is less than node data then check left else check right
exists(X, node(Y,L,_)):- X<Y, !, exists(X,L).
exists(X, node(Y,_,R)):- exists(X,R).