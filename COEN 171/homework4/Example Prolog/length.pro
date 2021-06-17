% len will run forever when looking for a second response to len(X,3)
% as it keeps building longer and longer lists, they will never have length 3

len([],0).
len([_|T],N) :- len(T,M), N is M + 1.


% the cut ensures that mylen only generates one response

mylen(X,Y) :- len(X,Y), !.
