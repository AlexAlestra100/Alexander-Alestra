#lang racket
(provide great-divide)
; do not change any code above this line. Write your code below it.

(define (great-divide x y)
    (cond 
          [(= y 1) 1]
          [(= (remainder x y) 0) y]
          [else (great-divide x (- y 1))]))
