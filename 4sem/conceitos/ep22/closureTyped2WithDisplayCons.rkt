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
  [let*C   (n1 : symbol) (s1 : ExprC) (n2 : symbol) (s2 : ExprC) (b : ExprC)]
  [consC (car : ExprC) (cdr : ExprC)]
  [carC  (cell : ExprC) ]
  [cdrC (cell : ExprC)]
  [displayC (exp : ExprC)]
  [quoteC  (sym : symbol)]
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
  [let*S   (n1 : symbol) (s1 : ExprS) (n2 : symbol) (s2 : ExprS) (b : ExprS)]
  [consS (car : ExprS) (cdr : ExprS)]
  [carS (cell : ExprS) ]
  [cdrS (cell : ExprS)]
  [displayS (exp : ExprS)]
  [quoteS  (sym : symbol)]
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
    [let*S   (n1 s1 n2 s2 b) (let*C n1 (desugar s1) n2 (desugar s2) (desugar b))]
    [consS   (car cdr) (consC (desugar car) (desugar cdr))]
    [carS    (exp)     (carC (desugar  exp)) ]
    [cdrS    (exp)     (cdrC (desugar  exp)) ]
    [displayS (exp)    (displayC (desugar exp))]
    [quoteS (sym) (quoteC sym)]
    [nullS  () (nullC)]
    ))


; We need a new value for the box
(define-type Value
  [numV  (n : number)]
  [nullV ]
  [quoteV (symb : symbol)]
  [closV (arg : symbol) (body : ExprC) (env : Env)]
  [cellV (first : Value) (second : Value)]
  )


; Bindings associate symbol with location
(define-type Binding
        [bind (name : symbol) (val : Location)])

; Env remains the same, we only change the Binding
(define-type-alias Env (listof Binding))
(define mt-env empty)
(define extend-env cons)

; Storages associate location with value
(define-type-alias Location number)
(define-type Storage
  [cell (location : Location) (val : Value)])

(define-type-alias Store (listof Storage))
(define mt-store empty)
(define override-store cons)

(define-type Result
  [v*s (v : Value) (s : Store)])

; Find the name of a variable
(define (lookup [for : symbol] [env : Env]) : Location
       (cond
            [(empty? env) (error 'lookup (string-append (symbol->string for) " was not found"))] ; variable is undefined
            [else (cond
                  [(symbol=? for (bind-name (first env)))   ; found it!
                                 (bind-val (first env))]
                  [else (lookup for (rest env))])]))        ; check in the rest

; Find value on storage
(define (fetch [loc : Location] [sto : Store]) : Value
       (cond
            [(empty? sto) (error 'lookup (string-append (to-string loc) " was not found"))] ; variable is undefined
            [else (cond
                  [(equal? loc (cell-location (first sto)))   ; found it!
                                 (cell-val (first sto))]
                  [else (fetch loc (rest sto))])]))        ; check in the rest

(define new-loc
  (let ([n (box 0)])
  (lambda ()
    (begin
      (set-box! n (+ 1 (unbox n)))
      (unbox n)))))


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

; Interpreter
(define (interp [a : ExprC] [env : Env] [sto : Store]) : Result
  (type-case ExprC a
    ; Numbers just evaluta to their equivalent Value
    [numC (n) (v*s (numV n) sto)]

    ; IDs are retrieved from the Env and unboxed
    [idC (n) (v*s (fetch (lookup n env) sto) sto)]

    ; Lambdas evaluate to closures, which save the environment
    [lamC (a b) (v*s (closV a b env) sto)]

    ; Application of function
    [appC (f a)
      (type-case Result (interp f env sto)
        [v*s (v-f s-f)
             (type-case Result (interp a env s-f)
               [v*s (v-a s-a)
                    (let ([where (new-loc)])
  (interp (closV-body v-f)
          (extend-env (bind (closV-arg v-f)
                            where)
                      (closV-env v-f))
          (override-store (cell where v-a) s-a)))])])]

    ; Sum two numbers using auxiliary function
    [plusC (l r)
           (type-case Result (interp l env sto)
                      [v*s (vl sl) (type-case Result (interp r env sl)
                                              [v*s (vr sr) (v*s (num+ vl vr) sr)])])]

    ; Multiplies two numbers using auxiliary function
    [multC (l r)
           (type-case Result (interp l env sto)
                      [v*s (vl sl) (type-case Result (interp r env sl)
                                     [v*s (vr sr) (v*s (num* vl vr) sr)])])]

    ; Conditional operator
    [ifC (c s n)
         (type-case Result (interp c env sto)
                    [v*s (vc sc) (if (zero? (numV-n vc)) (interp n env sc) (interp s env sc))])]

    ; Sequence of operations
    [seqC (b1 b2)
          (type-case Result (interp b1 env sto)
                     [v*s (vb1 sb1) (interp b2 env sb1)])]

    ; Attribution of variables
    ;[setC (var val) (let ([b (lookup var env)])
                      ;(begin (set-box! b (interp val env)) (unbox b)))]

    ; Declaration of variable
    [letC (name arg body)
          (type-case Result (interp arg env sto)
            [v*s (varg sarg) (let* ([where (new-loc)]
                                    [new-bind (bind name where)]
                                    [new-env (extend-env new-bind env)]
                                    [snew (override-store (cell where varg) sarg)])
                               (interp body new-env snew))])]
    [let*C (n1 s1 n2 s2 b)
           (type-case Result (interp s1 env sto)
             [v*s (vs1 ss1) (let* ([where1 (new-loc)]
                                   [new-bind1 (bind n1 where1)]
                                   [new-env1 (extend-env new-bind1 env)]
                                   [snew1 (override-store (cell where1 vs1) ss1)])
                                   (type-case Result (interp s2 new-env1 snew1)
                                     [v*s (vs2 ss2) (let* ([where2 (new-loc)]
                                                           [new-bind2 (bind n2 where2)]
                                                           [new-env2 (extend-env new-bind2 new-env1)]
                                                           [snew2 (override-store (cell where2 vs2) ss2)])
                                                      (interp b new-env2 snew2))]))])]
    ; Cell operations
    [consC (car cdr) (type-case Result (interp car env sto)
                       [v*s (vcar scar) (type-case Result (interp cdr env scar)
                                          [v*s (vcdr scdr) (v*s (cellV vcar vcdr) scdr)])])]
    [carC  (exp) (type-case Result (interp exp env sto)
                   [v*s (vexp sexp) (v*s (cellV-first vexp) sexp)])]
    [cdrC  (exp) (type-case Result (interp exp env sto)
                   [v*s (vexp sexp) (v*s (cellV-second vexp) sexp)])]
    ;Display values
    [displayC (exp) (type-case Result (interp exp env sto)
                               [v*s (vexp sexp) (begin (print-value vexp)
                                                       (display ";")
                                                       (v*s vexp sexp))])]
    ;Symbol
    [quoteC (sym) (v*s (quoteV sym) sto)]
    ;Null
    [nullC  () (v*s (nullV) sto)]
    
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
             [(let*)  (let*S  (s-exp->symbol (first (s-exp->list (first (s-exp->list (second sl))))))
                          (parse (second (s-exp->list (first (s-exp->list (second sl))))))
                          (s-exp->symbol (first (s-exp->list (second (s-exp->list (second sl))))))
                          (parse (second (s-exp->list (second (s-exp->list (second sl))))))
                          (parse (third sl)))]
             [(cons) (consS (parse (second sl)) (parse (third sl)))]
             [(car) (carS (parse (second sl)))]
             [(cdr) (cdrS (parse (second sl)))]
             [(display)(displayS (parse (second sl)))]
             [(quote) (quoteS (s-exp->symbol (second sl)))]
             [else (error 'parse "invalid list input")])))]
    [else (error 'parse "invalid input")]))


; Facilitator
(define (interpS [s : s-expression]) (interp (desugar (parse s)) mt-env mt-store))

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
                      