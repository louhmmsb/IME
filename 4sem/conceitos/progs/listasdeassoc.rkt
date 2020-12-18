;listasdessoc.rkt
(require scheme)

(define (achaassoc chave lista)
  (if (null? lista) '()
      (if (equal? chave (caar lista))
          (cadar lista)
          (achaassoc chave (cdr lista)))))

(define (mkassoc chave valor lista)
  (if (null? lista) (list (list chave valor))
      (if (equal? chave (caar lista))
          (cons (list chave valor) (cdr lista))
          (cons (car lista) (mkassoc chave valor (cdr lista))))))
                          
