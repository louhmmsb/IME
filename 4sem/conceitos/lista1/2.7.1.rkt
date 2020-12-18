;2.7.1.rkt
(require scheme)

(define (count* x l)
  (if (null? l) 0
      (if (equal? x (car l)) (+ 1 (count* x (cdr l)))
          (count* x (cdr l)))))

(define (countall x l)
  (if (null? l) 0
      (if (list? (car l)) (+ (countall x (car l)) (countall x (cdr l)))
          (if (equal? x (car l)) (+ 1 (countall x (cdr l)))
              (countall x (cdr l))))))

(define (reverse* l)
  (if (equal? l null) '()
      (append (reverse* (cdr l)) (cons (car l) '()))))

(define (twist l)
  (if (null? (cdr l))
      (if (list? (car l)) (list (twist (car l)))
          l)
      (if (list? (car l)) (append (twist (cdr l)) (list (twist (car l))))
          (append (twist (cdr l)) (list (car l))))))

(define (flatten* l)
  (if (null? l) '()
      (if (list? (car l)) (append (flatten* (car l)) (flatten* (cdr l)))
          (cons (car l) (flatten* (cdr l))))))

(define (sublist l1 l2)
  (if (null? l1) #true
      (if (null? l2) #false
          (if (equal? (car l1) (car l2)) (sublist (cdr l1) (cdr l2))
              (sublist l1 (cdr l2))))))

(define (seqcomp l1 l2)
  (if (null? l1) #true
      (if (null? l2) #false
          (if (equal? (car l1) (car l2)) (seqcomp (cdr l1) (cdr l2))
              #false))))

(define (contig-sublist l1 l2)
  (if (null? l2) #false
      (if (seqcomp l1 l2) #true
          (contig-sublist l1 (cdr l2)))))
