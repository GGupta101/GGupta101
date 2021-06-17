% not(X) succeeds if X fails, and fails if X succeeds
%
% suppose X succeeds in the first rule ...
%   we next evaluate the cut (which always succeeds) but limits backtracking
%   then we explicitly fail, but there's no place to backtrack, so not fails
%
% suppose X fails ...
%   we haven't reached the cut yet
%   so we try the next rule, which always succeeds

not(X) :- X, !, fail.
not(X).
