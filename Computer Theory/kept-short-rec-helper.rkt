#lang racket
(provide kept-short-rec)
; do not change any code above this line. Write your code below it.

(define (kept-short-rec-helper acc n xs)
  (if (empty? xs)
      acc
      (if (< (string-length (first xs)) n)
          (kept-short-rec-helper (add1 acc) n (rest xs))
          (kept-short-rec-helper acc n (rest xs)))))

(define (kept-short-rec n xs)
  (kept-short-rec-helper 0 n xs))
