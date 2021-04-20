#lang racket
(require "quizS.rkt")
(provide parseS)
; do not change any code above this line. Write your code below it.

(define (parseS toks)
  (cond ((not (list? toks)) false)
        ((empty? toks) (parseB (parseA toks)))             ; $ predicts S -> AB
        ((equal? (first toks) "a") (parseB (parseA toks))) ; a predicts S -> AB
        ((equal? (first toks) "b") (parseB (parseA toks))) ; b predicts S -> AB
        (else false)))
