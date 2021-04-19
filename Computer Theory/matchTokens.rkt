#lang racket/base
(require racket/bool)
(require racket/list)
(provide match)
; do not change any code above this line. Write your code below it.

; match : list item -> list or false
; if first item of list equals item return rest of list, else false
; Examples:
;   (match '("a" "b" "c") "a")  -> '("b" "c") Done
;   (match '("a" "b" "c") "b")  -> false      Done
;   (match '("a") "a")          -> '()
;   (match '() "a")             -> false      Done
;   (match false "a")           -> false      Done
(define (match toks tok)
    (cond ((empty? toks) false)
        ((not (list? toks)) false)
        ((not (equal? (first toks) tok)) false)
        ((equal? (first toks) tok) (rest toks))))
