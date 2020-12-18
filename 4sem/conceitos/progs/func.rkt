;mapc.rkt
(require scheme)

(define mapc
  (lambda (f l)
    (if (null? l) l
        (cons (f (car l)) (mapc f (cdr l))))))

(define filterc
  (lambda (con l)
    (if (null? l) l
        (if (con (car l))
            (cons (car l) (filterc con (cdr l)))
            (filterc con (cdr l))))))

(define curryc
  (lambda (f) (lambda (x) (lambda (y) (f x y)))))
