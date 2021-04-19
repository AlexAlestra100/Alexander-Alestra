#lang racket
(provide next)
; do not change any code above this line. Write your code below it.

; next : list -> string or false
; if list not empty and first item a string, eval to first item, else false
; Examples:
;   (next '("a" "b" "c"))   -> "a"   Done
;   (next '("a" 2 3))       -> "a"   Done
;   (next '(1 "b" "c"))     -> false Done
;   (next "a")              -> false Done
;   (next '())              -> false Done
(define (next toks)
    (cond ((empty? toks) false)
          ((not (list? toks)) false)
          ((not (string? (first toks))) false)
          (else (first toks))))
