#lang racket
(provide double-filter)
; do not change any code above this line. Write your code below it.

; return xs, keeping only elems making f and g true
(define (double-filter f g xs)
  (cond
    [(empty? xs) empty]
    [(and (g (first xs)) (f (first xs))) (cons (first xs) (double-filter f g (rest xs)))]
    [else (double-filter f g (rest xs))]))
