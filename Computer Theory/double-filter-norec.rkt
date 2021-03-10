#lang racket
(provide double-filter-norec)
; do not change any code above this line. Write your code below it.

; return xs, keeping only elems making f and g true
(define (double-filter-norec f g xs)
    (filter (lambda (x) (and (f x) (g x))) xs))
