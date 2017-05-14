(define populationTest '((homme 20) (femme 35) (homme 40) (femme 15) (homme 50)))

(define (compte population sexe)
  (cond ((null? population) 0)
        ((equal? (caar population) sexe)(+ 1 (compte (cdr population) sexe)))
        (else (+ 0 (compte (cdr population) sexe)))
        )
  )



(define (compteAge population sexe)
  (cond ((null? population) 0)
        ((equal? (caar population) sexe)(+ (cadar population) (compteAge (cdr population) sexe)))
        (else (+ 0 (compteAge (cdr population) sexe)))
        )
  )

(define (somme-age population)
  (list (compteAge population 'homme) (compteAge population 'femme))
  )

(define (age-moyen population)
  (list(list 'homme (/ (compteAge population 'homme) (compte population 'homme)))(list 'femme (/ (compteAge population 'femme) (compte population 'femme))))
  )
;(caar populationTest)
(car (cdr (car populationTest)))

;(compte populationTest 'homme)
(compteAge populationTest 'homme)
(somme-age populationTest)
(age-moyen populationTest)
;(list 'a 'b '())
;(list 'a 'b (list 'd 'e))
;(cons 'a (cons 'b (cons '()'())))
;(cons 'a (cons 'b (cons '(d e) '())))