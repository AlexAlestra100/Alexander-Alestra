#lang racket
(provide count-char)
; do not change any code above this line. Write your code below it.

(define (count-char s c)
    (cond
        [(string=? s "") 0]
        [(equal? c (substring s 0 1)) (+ 1 (count-char (substring s 1) c))]
        [else (count-char (substring s 1) c)]))
