;Calculette
(load "libcalc.ss")
(load "grafcalc.ss")

(define (add op1 op2)
  (if (non_zero? op2)
    (add (incrementer op1) (decrementer op2))
    op1
  )
)

(define (sou op1 op2)
  (if (non_zero? op2)
    (if (sup_egal? op1 op2)
      (sou (decrementer op1) (decrementer op2))
      op1
      )
    op1
  )
)

(define (mul op1 op2)
  (if (sup_egal? op2 2)
    (add (mul op1 (decrementer op2)) op1)
    op1
  )
)

(define (div op1 op2)
  (if (non_zero? op1)
    (add 1 (div (sub op1 op2) op2))
    op1
  )
)

;(add 2 3)
;(sou 30 15)
;(mul 6 6)
;(div 15 5)

(define (calculet)
  (let ((operation 'a)
        (nb1 0)
        (nb2 0)
        )
  (display "\n-------------------------\n")
  (display "operateur ? (fin pour arrêter)")
  (set! operation (read))
  (display operation)
  (if (equal? operation 'fin)(display "Adieu !")(begin
    (display "\n opérande 1 : ")
    (set! nb1 (read))
    (display nb1)
    (display "\n opérande 2 : ")
    (set! nb2 (read))
    (display nb2)
    (display "\n\n")
    (display "Evaluation de ")
    (display operation)
    (display " ")
    (display nb1)
    (display " ")
    (display nb2)
    (display ", résultat: ")
    (cond
      ((equal? operation 'add)(display (add nb1 nb2)))
      ((equal? operation 'sou)(display (sou nb1 nb2)))
      ((equal? operation 'mul)(display (mul nb1 nb2)))
      ((equal? operation 'div)(display (div nb1 nb2)))
    )
    (calculet)
  ))
))

(calculet)
