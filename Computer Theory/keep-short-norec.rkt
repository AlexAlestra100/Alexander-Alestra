#lang racket
(provide keep-short-norec)
; do not change any code above this line. Write your code below it.

(define (keep-short-norec x xs)
    (filter (lambda (s) (> x (string-length s))) xs))
