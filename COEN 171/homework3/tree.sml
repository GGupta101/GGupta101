(* File: tree.sml *)
(* Name: Gagan Gupta *)
(* Date: 11/09/20 *)
(* Assignment: COEN 171 Homework 3 Part 2 *)

(* a tree is either empty or is a node consisting of
   an integer, a left subtree, and a right subtree *)
   
datatype tree = empty | node of (int * tree * tree)

fun member a empty = false | member a (node(b, l, r)) =
		if a < b then
			member a l
		else if a > b then
			member a r
		else
			true

fun insert a empty = node(a, empty, empty) | insert a (node(b, l, r)) =
        if a < b then
            node(b, insert a l, r)
        else 
            node(b, l, insert a r)

(* build = fn : int list -> tree
   Returns a tree that is result of inserting all integers in the given list *)
val build = foldl (fn (v,t) => insert t v) empty;

(* inorder = fn : tree -> int list
   Returns a list that is contains all integers in the tree in order *)
fun inorder empty = [] | inorder (node(d, l, r)) = inorder l @ d :: inorder r;


