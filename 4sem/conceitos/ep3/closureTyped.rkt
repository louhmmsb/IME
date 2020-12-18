#lang plai-typed


; Basic expressions
(define-type ExprC
  [numC  (n : number)]
  [idC   (s : symbol)]
  [plusC (l : ExprC) (r : ExprC)]
  [multC (l : ExprC) (r : ExprC)]
  [methodC  (name : symbol) (arg : symbol) (body : ExprC)]
  [newC (name : symbol) (v : ExprC)]
  ;[appC  (fun : ExprC) (arg : ExprC)]
  [ifC   (c : ExprC) (y : ExprC) (n : ExprC)]
  [seqC  (e1 : ExprC) (e2 : ExprC)]
  [setC  (var : symbol) (arg : ExprC)]
  [letC  (name : symbol) (arg : ExprC) (body : ExprC)]
  [classC (classid : symbol) (varid : symbol) (method1 : ExprC) (method2 : ExprC)]
  [sendC  (ob : ExprC) (methodName : symbol) (arg : ExprC)]
  )


; Sugared expressions
(define-type ExprS
  [numS    (n : number)]
  [idS     (s : symbol)]
  [methodS    (name : symbol) (arg : symbol) (body : ExprS)]
  [newS (name : symbol) (v : ExprS)]
  ;[appS    (fun : ExprS) (arg : ExprS)]
  [plusS   (l : ExprS) (r : ExprS)]
  [bminusS (l : ExprS) (r : ExprS)]
  [uminusS (e : ExprS)]
  [multS   (l : ExprS) (r : ExprS)]
  [ifS     (c : ExprS) (y : ExprS) (n : ExprS)]
  [seqS    (e1 : ExprS) (e2 : ExprS)]
  [setS    (var : symbol) (arg : ExprS)]
  [letS    (name : symbol) (arg : ExprS) (body : ExprS)]
  [classS (classid : symbol) (varid : symbol) (method1 : ExprS) (method2 : ExprS)]
  [sendS  (ob : ExprS) (methodName : symbol) (arg : ExprS)]
  )


; Removing the sugar
(define (desugar [as : ExprS]) : ExprC
  (type-case ExprS as
    [numS    (n)        (numC n)]
    [idS     (s)        (idC s)]
    [methodS (n a b)      (methodC n a (desugar b))]
    [newS (n v) (newC n (desugar v))]
    ;[appS    (fun arg)  (appC (desugar fun) (desugar arg))]
    [plusS   (l r)      (plusC (desugar l) (desugar r))]
    [multS   (l r)      (multC (desugar l) (desugar r))]
    [bminusS (l r)      (plusC (desugar l) (multC (numC -1) (desugar r)))]
    [uminusS (e)        (multC (numC -1) (desugar e))]
    [ifS     (c s n)    (ifC (desugar c) (desugar s) (desugar n))]
    [seqS    (e1 e2)    (seqC (desugar e1) (desugar e2))]
    [setS    (var expr) (setC  var (desugar expr))]
    [letS    (n a b)    (letC n (desugar a) (desugar b))]
    [classS (cid vid m1 m2) (classC cid vid (desugar m1) (desugar m2))]
    [sendS  (e id arg) (sendC (desugar e) id (desugar arg))]
    ))


; We need a new value for the box
(define-type Value
  [numV  (n : number)]
  [methodV (name : symbol) (arg : symbol) (body : ExprC)]
  [classV (parId : symbol) (varId : symbol) (method1 : Value) (method2 : Value)]
  [objectV (classe : Value) (pai : Value) (var : Binding)]
  )


; Bindings associate symbol with location
(define-type Binding
        [bind (name : symbol) (val : (boxof Value))])

(define ObjectClass
  (classV 'null 'nadapo
          (methodV 'naometodo1 'nada (numC 2345678))
          (methodV 'naometodo2 'nada (numC 2345678))))

(define ObjectObject (objectV ObjectClass (numV 0) (bind 'issoaquinenada (box (numV 2345678)))))

; Env remains the same, we only change the Binding
(define-type-alias Env (listof Binding))

(define mt-env (cons
                (bind 'Object
                      (box ObjectClass))
                empty))

(define extend-env cons)




; Find the name of a variable
(define (lookup [for : symbol] [env : Env]) : (boxof Value)
       (cond
            [(empty? env) (error 'lookup (string-append (symbol->string for) " was not found"))] ; variable is undefined
            [else (cond
                  [(symbol=? for (bind-name (first env)))   ; found it!
                                 (bind-val (first env))]
                  [else (lookup for (rest env))])]))        ; check in the rest

(define (lookupMethod [id : symbol] [ob : Value]) : Value
  (cond
    [(equal? ob ObjectObject) (error 'lookupMethod (string-append (symbol->string id) " mensagem desconhecida"))]
    [(equal? id (methodV-name (classV-method1 (objectV-classe ob)))) (classV-method1 (objectV-classe ob))]
    [(equal? id (methodV-name (classV-method2 (objectV-classe ob)))) (classV-method2 (objectV-classe ob))]
    [else (lookupMethod id (objectV-pai ob))]))

(define (mountEnv [ob : Value]) : Env
  (cond
    [(equal? ob ObjectObject) empty]
    [else (extend-env (objectV-var ob) (mountEnv (objectV-pai ob)))]))

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
(define (interp [a : ExprC] [env : Env]) : Value
  (type-case ExprC a
    ; Numbers just evaluta to their equivalent Value
    [numC (n) (numV n)]

    ; IDs are retrieved from the Env and unboxed
    [idC (n) (unbox (lookup n env))]

    ; Lambdas evaluate to closures, which save the environment
    [methodC (n a b) (methodV n a b)]

    ; Instantiating a object
    [newC (n v)
          (let ([obClass (unbox (lookup n env))])
            (objectV
             obClass
             (if (equal? (classV-parId obClass) (classV-parId ObjectClass))
                 ObjectObject
                 (interp (newC (classV-parId obClass) (numC 0)) env))
             (bind (classV-varId obClass) (box (interp v env)))))]

    ; Sum two numbers using auxiliary function
    [plusC (l r) (num+ (interp l env) (interp r env))]

    ; Multiplies two numbers using auxiliary function
    [multC (l r) (num* (interp l env) (interp r env))]

    ; Conditional operator
    [ifC (c s n) (if (zero? (numV-n (interp c env))) (interp n env) (interp s env))]

    ; Sequence of operations
    [seqC (b1 b2) (begin (interp b1 env) (interp b2 env))] ; No side effect between expressions!

    ; Attribution of variables
    [setC (var val) (let ([b (lookup var env)])
                      (begin (set-box! b (interp val env)) (unbox b)))]

    ; Declaration of variable
    [letC (name arg body)
          (let* ([new-bind (bind name (box (interp arg env)))]
                 [new-env (extend-env new-bind env)])
            (interp body new-env))]

    ; Declaration of a class
    [classC (cid vid m1 m2)
            (classV cid vid (interp m1 env) (interp m2 env))]

    ; Calling a method
    [sendC  (e id a)
            (let* ([ob (interp e env)]
                   [method (lookupMethod id ob)]
                   [methodEnv (mountEnv ob)])
              (interp (methodV-body method) (extend-env (bind (methodV-arg method) (box (interp a env))) methodEnv)))]
    ))


; Parser
(define (parse [s : s-expression]) : ExprS
  (cond
    [(s-exp-number? s) (numS (s-exp->number s))]
    [(s-exp-symbol? s) (idS (s-exp->symbol s))]
    [(s-exp-list? s)
     (let ([sl (s-exp->list s)])
       (case (s-exp->symbol (first sl))
         [(+) (plusS (parse (second sl)) (parse (third sl)))]
         [(*) (multS (parse (second sl)) (parse (third sl)))]
         [(-) (bminusS (parse (second sl)) (parse (third sl)))]
         [(~) (uminusS (parse (second sl)))]
         [(method) (methodS
                    (s-exp->symbol (second sl))
                    (s-exp->symbol (third sl))
                    (parse (third (rest sl))))] ; definição
         ;[(call) (appS (parse (second sl)) (parse (third sl)))]
         [(if) (ifS (parse (second sl)) (parse (third sl)) (parse (fourth sl)))]
         [(seq) (seqS (parse (second sl)) (parse (third sl)))]
         [(:=) (setS (s-exp->symbol (second sl)) (parse (third sl)))]
         [(let) (letS (s-exp->symbol (first (s-exp->list (first (s-exp->list (second sl))))))
                      (parse (second (s-exp->list (first (s-exp->list (second sl))))))
                      (parse (third sl)))]
         [(class) (classS
                   (s-exp->symbol (second sl))
                   (s-exp->symbol (third sl))
                   (parse (third (rest sl)))
                   (parse (third (rest (rest sl)))))]
         [(new)   (newS (s-exp->symbol (second sl)) (parse (third sl)))]
         [(send)  (sendS (parse (second sl)) (s-exp->symbol (third sl)) (parse (third (rest sl))))]
         [else (error 'parse "invalid list input")]))]
    [else (error 'parse "invalid input")]))


; Facilitator
(define (interpS [s : s-expression]) (interp (desugar (parse s)) mt-env))
