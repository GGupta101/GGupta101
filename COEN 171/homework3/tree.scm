#lang scheme
; File: tree.scm
; Name: Gagan Gupta
; Date: 11/09/20
; Assignment: COEN 171 Homework 3 Part 2

; vi:ai:lisp:sm

(define (member t v)
	(cond
		((null? t)
			#f
		)
		((< v (car t))
			(member (cadr t) v)
		)
		((> v (car t))
			(member (caddr t) v)
		)
		(else
			#t
		)
	)
)

(define (insert t v)
	(cond
		((null? t) 
			(list v '() '())
		)
		((< v (car t)) 
			(list (car t) (insert (cadr t) v) (caddr t))
		)
		((>= v (car t)) 
			(list (car t) (cadr t) (insert (caddr t) v))
		)
		(else 
			t
		)
	)
)

(define (fold func val lst)
  (if (null? lst) val (fold func (func val (car lst)) (cdr lst))))

(define (build lst)
  (fold (lambda (t v) (insert t v)) '() lst))

(define t (list 10 '() '()))
(insert t 5)
(insert t 11)
(insert t 123)
(insert t 3)
(insert t 2)
display (member t 5)
display (member t 11)
display (member t 123)
display (member t 3)
display (member t 2)
display t