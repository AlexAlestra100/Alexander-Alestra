#lang racket
(provide update-if)
; do not change any code above this line. Write your code below it.

(define (update-if f g xs)
  (map (lambda (s) (g s)) (filter f xs)))
