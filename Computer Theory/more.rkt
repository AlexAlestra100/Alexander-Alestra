#lang racket
(provide more)
; do not change any code above this line. Write your code below it.

; return true iff xs has more elements than ys
(define (more xs ys)
    (cond
        [(empty? xs) false]
        [(empty? ys) true]
        [else (more (rest xs) (rest ys))]))
