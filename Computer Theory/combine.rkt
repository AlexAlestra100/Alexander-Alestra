#lang racket
(provide combine)
; do not change any code above this line. Write your code below it.

(define (combine f g)
  (lambda (s) (g (f s))))
