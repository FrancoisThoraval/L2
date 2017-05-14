(define valeurPossible '(2 3 4 5 6 7 8 9 10 valet dame roi as))
(define couleurPossible '(pique coeur carreau trefle))

(define (valeur carte)
  (car carte)
)

(define (couleur carte)
  (cadr carte)
)

(define (possible? liste elem)
  (cond((null? liste) #f)
       ((equal? (car liste) elem) #t)
       (else(possible? (cdr liste) elem))
  )
)

(define (carte? carte)
  (cond ((null? (car carte))#f)
        ((and(possible? valeurPossible (car carte))(possible? couleurPossible (cadr carte)))#t)
        (else #f)
        )
)

(define (points carte)
  (cond ((not(carte? carte ))0)
        ((number? (car carte))(car carte))
        ((equal? 'valet (car carte))11)
        ((equal? 'dame (car carte))12)
        ((equal? 'roi (car carte))13)
        ((equal? 'as (car carte))1)
        )
  )

(define (evalue main)
  (cond ((null? main)0)
        (else (+(points (car main))(evalue (cdr main))))
        )
  )

(define carteTest '(5 carreau))
(define mainTest '((as pique)(dame coeur)(8 trefle)(10 pique)(as carreau)))

(valeur carteTest)
(couleur carteTest)

(carte? carteTest)
(points carteTest)

(evalue mainTest)
