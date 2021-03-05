#lang racket
(provide keep-short-rec)
; do not change any code above this line. Write your code below it.

(define (keep-short-rec x ks)
    (if (empty? ks)
        empty
        (if (> x (string-length (first ks)))
            (cons (first ks) (keep-short-rec x (rest ks)))
            (keep-short-rec x (rest ks)))))
