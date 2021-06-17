% Gagan Gupta
% 12/01/20
% COEN 171 Homework 4 - Quicksort

% If empty list then sorted list is empty
quicksort([],[]):- !.
% Recurrsively call quicksort with partition
quicksort([H|X],Y):- partition(X,L,R,H), quicksort(L,LS), quicksort(R,RS), append(LS,[H|RS],Y).

% If empty then partition is done
partition([],[],[],_):- !.
% If H is less than left pivot then partition left else partition right
partition([H|X],[H|Y],Z,P):- H<P, partition(X,Y,Z,P), !.
partition([H|X],Y,[H|Z],P):- partition(X,Y,Z,P).