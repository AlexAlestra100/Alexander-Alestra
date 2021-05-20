#lang racket
(provide summax)
; do not change any code above this line. Write your code below it.

; summax: sum of max(f(x), g(x)) for each x in xs
; f: object --> integer
; g: object --> integer
; xs: list of objects
; (summax add1 abs '(2 -2 -3 3)) evaluates to 12
; (summax add1 abs '()) evaluates to 0
(define (summax f g xs)
    (if (empty? xs)
        0
        (+ (max (f (first xs)) (g (first xs))) (summax f g (rest xs)))))
