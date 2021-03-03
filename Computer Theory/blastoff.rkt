#lang racket
(provide blastoff)
; do not change any code above this line. Write your code below it.

(define (blastoff x)
    (if(< x 2)
        (number->string x)
        (string-append (string-append (number->string x) " ") (blastoff (sub1 x)))))
