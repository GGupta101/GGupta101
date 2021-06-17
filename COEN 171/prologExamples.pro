append([],Y,Y).
append([H|X],Y,[H|Z]):- append(X,Y,Z).

prefix(X,Z):- append(X,_,Z).
suffix(Y,Z):- append(_,Y,Z).
sublist(S,Z):- prefix(X,Z), suffix(S,X).

member(X,[X|_]).
member(X,[_|T]):- member(X,T).

length([],0).
length([_|T], N):- length(T,M), N is M + 1.

range(L,U,L):- U>=L.
range(L,U,X):- U>L, N is L + 1, range(N,U,X).

insert(X,[],[X]), !.
insert(X,[H|T],[X,H|T]):- X<H, !.
insert(X,[H|T],[H|L]):- insert(X,T,L).

map(_,[],[]).
map(P,[X|XS],[Y|YS]):- call(P,X,Y), map(P,XS,YS).
inc(X,Y):- Y is X + 1.

sublist([],[]).
sublist(L,[_|T]):- sublist(L,T).
sublist([H|L],[H|T]):- sublist(L,T).
% setof(X, sublist(X,[a,b,a]), L)
L=[[],[a],[a,a],[a,b],[a,b,a],[b],[b,a]]

count(empty,0).
count(node(L,_,R),N):- count(L,LN), count(R,RN), N is 1 + LN + RN.
inorder(node(L,_,_), X) :- inorder(L, X).
inorder(node(_,X,_), X).
inorder(node(_,_,R), X) :- inorder(R, X).

% Green cut
max(X,Y,X):- X>=Y, !.
max(X,Y,Y):- X<Y.
% Red Cut
max(X,Y,X):- X>=Y, !.
max(_,Y,Y).

add(X,L,L):- member(X,L), !.
add(X,L,[X|L]).

len([],0).
len([_|T],N):- len(T,M), N is M + 1.
length(L,N):- len(L,N), !.

not(X):- X, !, fail.
not(_).

add(X, L, L) :- member(X, L).
add(X, L, [X|L]) :- not(member(X, L)).

%trying to make uniform
uniform([]).
uniform([_]).
uniform([H,H|T]):- uniform([H|T]).