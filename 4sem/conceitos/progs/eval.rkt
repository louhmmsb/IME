;eval.rkt
(require racket/include)
(require scheme)
(include "listasdeassoc.rkt")

(define (eval-expr expr ambiente)
  (if (number? expr) expr
      (if (symbol? expr) (achaassoc expr ambiente)
          (if (equal? (car expr) 'quote) (cadr expr)
              (applyop (car expr) (eval-expr (cadr expr) ambiente) (eval-expr (caddr expr) ambiente))))))

(define (applyop f arg1 arg2)
  (if (equal? f '+) (+ arg1 arg2)
      (if (equal? f '-) (- arg1 arg2)
          (if (equal? f '*) (* arg1 arg2)
              (if (equal? f '/) (/ arg1 arg2)
                  'ERROR)))))
