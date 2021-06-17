size(empty,0).
size(node(L,_,R),N) :- size(L,LS), size(R,RS), N is 1 + LS + RS.

preorder(node(_,X,_),X).
preorder(node(L,_,_),X) :- preorder(L,X).
preorder(node(_,_,R),X) :- preorder(R,X).

inorder(node(L,_,_),X) :- inorder(L,X).
inorder(node(_,X,_),X).
inorder(node(_,_,R),X) :- inorder(R,X).

postorder(node(L,_,_),X) :- postorder(L,X).
postorder(node(_,_,R),X) :- postorder(R,X).
postorder(node(_,X,_),X).

preorderList(empty,[]).
preorderList(node(L,D,R),[D|T]):- preorderList(L,LP), preorderList(R,RP), append(LP,RP,T).

inorderList(empty,[]).
inorderList(node(L,D,R),X):- inorderList(L,LI), inorderList(R,RI), append(LI,[D|RI],X).

postorderList(empty, []).
postorderList(node(L,D,R),[H|D]):- postorderList(L,LP), postorderList(R,RP), append(LP,RP,H).

mktree(X) :- X = node(node(empty,30,node(empty,40,empty)),50,node(empty,60,node(empty,70,empty))).
