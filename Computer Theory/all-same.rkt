#lang racket
(provide all-same)
; do not change any code above this line. Write your code below it.

(define (all-same s)
    (cond
      ((< (string-length s) 2) #t)
      ((equal? (substring s 0 1) (substring s 1 2)) (all-same (substring s 1)))
      (else #f)))
