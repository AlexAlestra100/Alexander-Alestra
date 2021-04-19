#lang racket
(require "match.rkt")
(require "next.rkt")
(provide parseS)
; do not change any code above this line. Write your code below it.

(define (parseS toks)
    (cond ((not (list? toks)) false)
        ((empty? toks) toks)
        ((equal? (first toks) "a") (match (parseS (match toks "a")) "z"))
        ((equal? (first toks) "b") (match (parseS (match toks "b")) "y"))
        ((equal? (first toks) "z") toks)
        ((equal? (first toks) "y") toks)
        (else false)))

; First(S') = {a,b,$}. On any of these three, (parseS toks) and verify result is end-of-input.
(define (parseSprime toks)
  (cond ((not (list? toks)) false)
        ((empty? toks) (equal? (parseS toks) empty))             ; $ predicts S' -> S$
        ((equal? (next toks) "a") (equal? (parseS toks) empty))  ; a predicts S' -> S$
        ((equal? (next toks) "b") (equal? (parseS toks) empty))  ; b predicts S' -> S$
        (else false)))
