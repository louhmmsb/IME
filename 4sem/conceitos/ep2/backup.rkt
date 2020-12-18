#lang plai-typed
; este interpretador aumenta o closureTyped para incluir
; cons, car, cdr, valor nulo (descrito como  ())
; e display
; display imprime o valor passado seguido de um ";". Nao mudamos de linha 

; Basic expressions
(define-type ExprC
  [numC  (n : number)]
  [idC   (s : symbol)]
  [plusC (l : ExprC) (r : ExprC)]
  [multC (l : ExprC) (r : ExprC)]
  [lamC  (arg : symbol) (body : ExprC)]
  [appC  (fun : ExprC) (arg : ExprC)]
  [ifC   (c : ExprC) (y : ExprC) (n : ExprC)]
  [seqC  (e1 : ExprC) (e2 : ExprC)]
  ;[setC  (var : symbol) (arg : ExprC)]
  [letC  (name : symbol) (arg : ExprC) (body : ExprC)]
  [consC (car : ExprC) (cdr : ExprC)]
  [carC  (cell : ExprC) ]
  [cdrC (cell : ExprC)]
  [displayC (exp : ExprC)]
  [quoteC  (sym : symbol)]
  [equalC (l : ExprC) (r : ExprC)]
  [let*C (s1 : symbol) (exp1 : ExprC) (s2 : symbol) (exp2 : ExprC) (body : ExprC)]
  [letrecC  (name : symbol) (arg : ExprC) (body : ExprC)]
  [nullC  ]
  )


; Sugared expressions
(define-type ExprS
  [numS    (n : number)]
  [idS     (s : symbol)]
  [lamS    (arg : symbol) (body : ExprS)]
  [appS    (fun : ExprS) (arg : ExprS)]
  [plusS   (l : ExprS) (r : ExprS)]
  [bminusS (l : ExprS) (r : ExprS)]
  [uminusS (e : ExprS)]
  [multS   (l : ExprS) (r : ExprS)]
  [ifS     (c : ExprS) (y : ExprS) (n : ExprS)]
  [seqS    (e1 : ExprS) (e2 : ExprS)]
  ;[setS    (var : symbol) (arg : ExprS)]
  [letS    (name : symbol) (arg : ExprS) (body : ExprS)]
  [consS (car : ExprS) (cdr : ExprS)]
  [carS (cell : ExprS) ]
  [cdrS (cell : ExprS)]
  [displayS (exp : ExprS)]
  [quoteS  (sym : symbol)]
  [equalS (l : ExprS) (r : ExprS)]
  [let*S (s1 : symbol) (exp1 : ExprS) (s2 : symbol) (exp2 : ExprS) (body : ExprS)]
  [letrecS  (name : symbol) (arg : ExprS) (body : ExprS)]
  [nullS ]
 )


; Removing the sugar
(define (desugar [as : ExprS]) : ExprC
  (type-case ExprS as
    [numS    (n)        (numC n)]
    [idS     (s)        (idC s)]
    [lamS    (a b)      (lamC a (desugar b))]
    [appS    (fun arg)  (appC (desugar fun) (desugar arg))]
    [plusS   (l r)      (plusC (desugar l) (desugar r))]
    [multS   (l r)      (multC (desugar l) (desugar r))]
    [bminusS (l r)      (plusC (desugar l) (multC (numC -1) (desugar r)))]
    [uminusS (e)        (multC (numC -1) (desugar e))]
    [ifS     (c s n)    (ifC (desugar c) (desugar s) (desugar n))]
    [seqS    (e1 e2)    (seqC (desugar e1) (desugar e2))]
    ;[setS    (var expr) (setC  var (desugar expr))]
    [letS    (n a b)    (letC n (desugar a) (desugar b))]
    [consS   (car cdr) (consC (desugar car) (desugar cdr))]
    [carS    (exp)     (carC (desugar  exp)) ]
    [cdrS    (exp)     (cdrC (desugar  exp)) ]
    [displayS (exp)    (displayC (desugar exp))]
    [quoteS (sym) (quoteC sym)]
    [equalS (l r) (equalC (desugar l) (desugar r))]
    [let*S (s1 e1 s2 e2 b) (let*C s1 (desugar e1) s2 (desugar e2) (desugar b))]
    [letrecS    (n a b)    (letrecC n (desugar a) (desugar b))]
    [nullS  () (nullC)]
    ))


; We need a new value for the box
(define-type Value
  [numV  (n : number)]
  [nullV ]
  [quoteV (symb : symbol)]
  [closV (arg : symbol) (body : ExprC) (env : Env)]
  [cellV (first : Value) (second : Value)]
  [suspV (e : ExprC) (env : Env)]
  )


; Bindings associate symbol with location
(define-type Binding
        [bind (name : symbol) (val : (boxof Value))])

; Env remains the same, we only change the Binding
(define-type-alias Env (listof Binding))
(define mt-env empty)
(define extend-env cons)


; Find the name of a variable
(define (lookup [for : symbol] [env : Env]) : (boxof Value)
       (cond
            [(empty? env) (error 'lookup (string-append (symbol->string for) " was not found"))] ; variable is undefined
            [else (cond
                  [(symbol=? for (bind-name (first env)))   ; found it!
                                 (bind-val (first env))]
                  [else (lookup for (rest env))])]))        ; check in the rest

; function to unsuspend a suspV
(define (strict [val : Value]) : Value
  (type-case Value val
             ;[suspV (e env)
             ;       (begin (display "-->")
             ;              (strict (interp e env)))]
             [suspV (e env) (strict (interp e env))]
             [else val]))

; Auxiliary operators
(define (num+ [l : Value] [r : Value]) : Value
    (cond
        [(and (numV? l) (numV? r))
             (numV (+ (numV-n l) (numV-n r)))]
        [else
             (error 'num+ "One of the arguments is not a number")]))

(define (num* [l : Value] [r : Value]) : Value
    (cond
        [(and (numV? l) (numV? r))
             (numV (* (numV-n l) (numV-n r)))]
        [else
             (error 'num* "One of the arguments is not a number")]))

(define (equal* [l : Value] [r : Value]) : Value
  (cond
    [(or (closV? l) (closV? r)) (numV 0)]
    [(or (suspV? l) (suspV? r)) (equal* (strict l) (strict r))]
    [(and (cellV? l) (cellV? r)) (if (equal? (equal* (cellV-first l) (cellV-first r)) (numV 1)) (equal* (cellV-second l) (cellV-second r)) (numV 0))]
    [else (if (equal? l r) (numV 1) (numV 0))]))
    
; Interpreter
(define (interp [a : ExprC] [env : Env]) : Value
  (type-case ExprC a
    ; Numbers just evaluta to their equivalent Value
    [numC (n) (numV n)]

    ; IDs are retrieved from the Env and unboxed
    [idC (n) (let ([b (lookup n env)])
               (begin (set-box! b (strict (unbox b)))
                      (unbox b)))]

    ; Lambdas evaluate to closures, which save the environment
    [lamC (a b) (closV a b env)]

    ; Application of function
    [appC (f a)
          (let ([f-value (strict (interp f env))])
            (interp (closV-body f-value)
                    (extend-env
                        (bind (closV-arg f-value) (box (suspV a env)))
                        (closV-env f-value)
                    )))]

    ; Sum two numbers using auxiliary function
    [plusC (l r) (num+ (interp l env) (interp r env))]

    ; Multiplies two numbers using auxiliary function
    [multC (l r) (num* (interp l env) (interp r env))]

    ; Conditional operator
    [ifC (c s n) (if (zero? (numV-n (interp c env))) (interp n env) (interp s env))]

    ; Sequence of operations
    [seqC (b1 b2) (begin (interp b1 env) (interp b2 env))] ; No side effect between expressions!

    ; Attribution of variables
    ;[setC (var val) (let ([b (lookup var env)])
                      ;(begin (set-box! b (interp val env)) (unbox b)))]

    ; Declaration of variable
    [letC (name arg body)
          (let* ([new-bind (bind name (box (suspV arg env)))]
                 [new-env (extend-env new-bind env)])
            (interp body new-env))]
    ; Cell operations
    [consC (car cdr)
           (cellV (suspV car env) (suspV cdr env))]
    [carC  (exp) (strict (cellV-first (strict (interp exp env))))]
    [cdrC  (exp) (cellV-second (strict (interp exp env)))]
    ;Display values
    [displayC (exp) (let ((value (interp exp env)))
                      (begin (print-value (interp exp env))
                             (display ";") ; no newline in plai-typed, we use ";" 
                             value))]
    ;Symbol
    [quoteC (sym) (quoteV sym)]
    ;Equal
    [equalC (l r) (equal* (interp l env) (interp r env))]
    [let*C (s1 e1 s2 e2 b)
           (let ([new-env (extend-env (bind s1 (box (suspV e1 env))) env)])
             (let ([new2-env (extend-env (bind s2 (box (suspV e2 new-env))) new-env)])
               (interp b new2-env)))]
    [letrecC (name arg body)
             (let* ([xaica (box (nullV))]
                    [new-env (extend-env (bind name xaica) env)])
               (begin (set-box! xaica (suspV arg new-env)) (interp body new-env)))]
    ;Null
    [nullC  () (nullV)]
    
    ))


; Parser
(define (parse [s : s-expression]) : ExprS
  (cond
    [(s-exp-number? s) (numS (s-exp->number s))]
    [(s-exp-symbol? s) (idS (s-exp->symbol s))]
    [(s-exp-list? s)
     (let ([sl (s-exp->list s)])
       (if (empty? sl)
           (nullS)
           (case (s-exp->symbol (first sl))
             [(+) (plusS (parse (second sl)) (parse (third sl)))]
             [(*) (multS (parse (second sl)) (parse (third sl)))]
             [(-) (bminusS (parse (second sl)) (parse (third sl)))]
             [(~) (uminusS (parse (second sl)))]
             [(lambda) (lamS (s-exp->symbol (second sl)) (parse (third sl)))] ; definição
             [(call) (appS (parse (second sl)) (parse (third sl)))]
             [(if) (ifS (parse (second sl)) (parse (third sl)) (parse (fourth sl)))]
             [(seq) (seqS (parse (second sl)) (parse (third sl)))]
             ;[(:=) (setS (s-exp->symbol (second sl)) (parse (third sl)))]
             [(let) (letS (s-exp->symbol (first (s-exp->list (first (s-exp->list (second sl))))))
                          (parse (second (s-exp->list (first (s-exp->list (second sl))))))
                          (parse (third sl)))]
             [(cons) (consS (parse (second sl)) (parse (third sl)))]
             [(car) (carS (parse (second sl)))]
             [(cdr) (cdrS (parse (second sl)))]
             [(display)(displayS (parse (second sl)))]
             [(quote) (quoteS (s-exp->symbol (second sl)))]
             [(equal?) (equalS (parse (second sl)) (parse (third sl)))]
             [(let*)  (let*S  (s-exp->symbol (first (s-exp->list (first (s-exp->list (second sl))))))
                          (parse (second (s-exp->list (first (s-exp->list (second sl))))))
                          (s-exp->symbol (first (s-exp->list (second (s-exp->list (second sl))))))
                          (parse (second (s-exp->list (second (s-exp->list (second sl))))))
                          (parse (third sl)))]
             [(letrec) (letrecS (s-exp->symbol (first (s-exp->list (first (s-exp->list (second sl))))))
                          (parse (second (s-exp->list (first (s-exp->list (second sl))))))
                          (parse (third sl)))]
             [else (error 'parse "invalid list input")])))]
    [else (error 'parse "invalid input")]))


; Facilitator
(define (interpS [s : s-expression]) (interp (desugar (parse s)) mt-env))

; Printing
(define (print-value [value : Value ] ) : void
                      
                      (type-case Value value
                        [numV  (n) (display n)]
                        [quoteV (symb) (display symb)]
                        [closV (arg body env)
                               (begin (display "<<")
                                      (display "lambda(")
                                      (display arg)
                                      (display ")")
                                      (display body)
                                      (display ";")
                                      (display env)
                                      (display ">>"))]
                        
                        [cellV (first second)
                               (begin (display "(")
                                      (print-list value)
                                      (display ")")
                                      )
                               ]
                        [suspV (expr env)
                               (display "suspV")]
                        [nullV ()
                               (display '())]))
(define (print-list cell) : void
  (begin 
         (print-value (cellV-first cell))
         (display " ")
         (let ([rest (cellV-second cell)])
           (type-case Value rest 
             [nullV () (display "") ]; null at the end of the list is not printed
             [cellV (first second) (print-list rest)]
             [else (begin (display ".")
                        (print-value (cellV-second cell)))]))
         )
  )

; Exemplos

;Esta cria uma funcao recursiva fun e imprime o valor do parametro a cada chamada.
 ;; (interpS '(let ((fun ()))
 ;;              (seq (:= fun (lambda x (if x (seq (display x)
 ;;                                                (call fun (- x 1)))
 ;;                                         x)))
 ;;                   (call fun 8))))

;(interpS '(cons 1 (cons 2 ())))
;(interpS '(car (cons 1 (cons 2 ()))))
;(interpS '(+ (car (cons 1 (cons 2 ()))) 2))
;(interpS '(let ([x (+ 3 3)]) (display x)))
;(interpS '(let ([x (+ 3 3)]) (seq (+ x x) x)))
;(interpS '(let ([x (+ 3 3)]) (call (lambda x (+ x x)) x)))
;(interpS '(let ([x (lambda y (+ y y))]) (+ (call x 2)  (call x 2))))
;(interpS '(let* ((x (+ 3 3)) (y x)) (seq (display y) (seq (display x) x))))
;(interpS '(let* ((x (+ 3 3)) (y x)) (seq (display x) (seq (display y) x))))
;(interpS '(call (car (cdr (cons 1 (cons (lambda x (+ x x)) ())))) 2))
;(interpS '(let ((y (call (lambda x (+ x x)) 6))) (call (lambda x (+ x x)) y)))
;(interpS '(let ((y (call (lambda x (+ x x)) 6))) (call (lambda x (+ x x)) 5)))
;(interpS '(let ((y (call (lambda x (+ x x)) 6))) (call (lambda x (cons 1 ())) 1)))
;(interpS '(let ((y (call (lambda x (+ x x)) 6))) (call (lambda x 5) y)))
;(interpS '(call (lambda x (+ x x)) 1))

(interpS '(letrec ((displayn (lambda n (lambda l
                                     (if (equal? l ())
                                         ()
                                         (if (equal? 0 n)
                                             ()
                                             (seq (display (car l))
                                             (call (call displayn (- n 1)) (cdr l)))))))))
            (letrec ([mapmeu (lambda f
                             (lambda l
                               (if (equal? l ())
                                   ()
                                   (cons (call f (car l)) (call (call mapmeu f) (cdr l))))))])
            (letrec ((ones (cons 1 ones)))
              (call (call displayn 2) (call (call mapmeu (lambda x (+ 1 x))) ones))
                  ))))