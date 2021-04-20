#lang racket
(require "match.rkt")
(provide parseA)
; do not change any code above this line. Write your code below it.

(define (parseA toks)
  (cond ((not (list? toks)) false)
        ((empty? toks) toks)             ; $ predicts A -> λ
        ((equal? (first toks) "a") (parseA (match (rest toks) "a"))) ; a predicts A -> aaA
        ((equal? (first toks) "b") toks) ; b predicts A -> λ
        (else false)))
