#lang racket
(provide sum-diff)
; do not change any code above this line. Write your code below it.

(define (sum-diff xs ys)
    (cond
        [(empty? xs) 0]
        [(empty? ys) 0]
        [else (+ (abs (- (first xs) (first ys))) (sum-diff (rest xs) (rest ys)))]))
