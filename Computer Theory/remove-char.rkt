#lang racket
(provide remove-char)
; do not change any code above this line. Write your code below it.

(define (remove-char s c)
  (if (= (string-length s) 0)
      s
      (if (equal? (substring s 0 1) c)
          (remove-char (substring s 1) c)
          (string-append (substring s 0 1) (remove-char (substring s 1) c)))))
