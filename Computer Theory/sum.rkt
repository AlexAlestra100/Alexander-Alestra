#lang racket
(provide sum)
; do not change any code above this line. Write your code below it.

(define (sum x y)
    (if (< y 1)
        x
        (sum (add1 x) (sub1 y))))