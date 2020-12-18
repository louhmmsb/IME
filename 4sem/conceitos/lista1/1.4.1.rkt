;1.4.1.rkt
(require scheme)

(define (sigma m n)
  (if (> m n) 0
      (+ m (sigma (+ m 1) n))))

(define (exp* m n)
  (if (= n 0) 1
      (* m (exp* m (- n 1)))))

(define (log* m n)
  (if (= n 1) 0
      (+ 1 (log* m (quotient n m)))))

(define (choose n k)
  (cond [(= n k) 1]
        [(= 0 k) 1]
        [else (+ (choose (- n 1) k) (choose (- n 1) (- k 1)))]))

(define (fib m)
  (cond [(= m 0) 0]
        [(= m 1) 1]
        [else (+ (fib (- m 2)) (fib (- m 1)))]))

(define (primeaux n d1)
  (if (> d1 (sqrt n)) #true
      (if (= (modulo n d1) 0) #false
          (primeaux2 n (+ 1 d1)))))

(define (prime n)
  (if (= n 1) #false
      (primeaux n 2)))

(define (nthprimeaux n wanted it)
  (if (and (= wanted it) (prime n)) n
      (if (prime n) (nthprimeaux (+ n 1) wanted (+ it 1))
          (nthprimeaux (+ n 1) wanted it))))

(define (nthprime n)
  (nthprimeaux 2 n 1))

(define (sumprimes n)
  (if (= n 0) 0
      (+ (nthprime n) (sumprimes (- n 1)))))

(define (relprimeaux big small now)
  (if (> now small) #true
      (if (and (= (modulo now small) 0) (= (modulo big now) 0)) #false
          (relprimeaux big small (+ now 1)))))

(define (relprime m n)
  (if (= m n) #false
      (if (> m n) (relprimeaux m n 2)
          (relprimeaux n m 2))))



