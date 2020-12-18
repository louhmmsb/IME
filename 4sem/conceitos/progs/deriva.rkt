;deriva.rkt
(require scheme)

(define deriva
  (lambda (f dx)
    (lambda (x)
      (/ (- (f (+ x dx)) (f x)) dx))))
