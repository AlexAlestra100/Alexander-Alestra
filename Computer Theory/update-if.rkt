#lang racket
(provide update-if)
; do not change any code above this line. Write your code below it.

(define (update-if f g xs)
  (if (empty? xs)
      empty
      (if (f (first xs))
          (cons (g (first xs)) (update-if f g (rest xs)))
          (update-if f g (rest xs)))))
