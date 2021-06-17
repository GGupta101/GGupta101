% runs forever (until stack overflow) when asking for a second response

fact(0,1).
fact(N,M) :- N1 is N - 1, fact(N1, M1), M is N * M1.


% better version that only returns a single response
% this is a red cut since it changes the behavior

fact2(0,1) :- !.
fact2(N,M) :- N1 is N - 1, fact2(N1, M1), M is N * M1.


% even better version that protects against factorial of a negative number

fact3(0,1) :- !.
fact3(N,M) :- N > 0, N1 is N - 1, fact3(N1, M1), M is N * M1.
