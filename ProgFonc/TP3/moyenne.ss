(define (somme l)
  (cond ((null? (cdr l))(car l))
  (else (+(somme (cdr l)) (car l))))
)
(define (moyenne l)
  (/(somme l) (length l))
)

(define (taux-reussite l moy)    
  (cond ((null? (cdr l))(if(>= (car l) moy) 1 0))
        (else(if(>= (car l) moy) (+ 1 (taux-reussite (cdr l) moy)) (taux-reussite (cdr l) moy)))
  )
)

(define l '(0 4 6 8 10 15 20))

(display "moyenne :")
(moyenne l)
(newline)

(display "taux-réussite: ")

(taux-reussite l (moyenne l))
(newline)

;=====================================================================================================================================
(define produit-Julie '(panier table cuiller voiture))
(define produit-Jules '(table echelle voiture couteau))

(define (produit-Julie? prod produit-Julie)
  (cond ((null? produit-Julie) #f)
        ((equal? prod (car produit-Julie)) #t)
        (else (produit-Julie? prod (cdr produit-Julie)))
  )
)

(define (produit-Jules? prod produit-Jules)
  (cond ((null? produit-Jules) #f)
        ((equal? prod (car produit-Jules)) #t)
        (else (produit-Jules? prod (cdr produit-Jules)))
  )
)

(produit-Julie? 'voiture produit-Julie)

(define (produits-double produit-Julie produit-Jules)
  (cond 
    ((null? produit-Jules) '())
    ((produit-Julie? (car produit-Jules) produit-Julie)(append (list(car produit-Jules)) (produits-double produit-Julie (cdr produit-Jules))))
    (else (append '() (produits-double produit-Julie (cdr produit-Jules)))))
        
)
;       produit-Julie                 produit-Jules                  resultat
;panier table cuiller voiture | table echelle voiture couteau | '(table) -> '(...)
;panier table cuiller voiture | echelle voiture couteau       | '() -> '(...)
;panier table cuiller voiture | voiture couteau               | '(voiture) -> '(...)
;panier table cuiller voiture | couteau                       | '() -> '(...)
;panier table cuiller voiture | null                          | '(...) = '() + '() + '(voiture) + '() +'(table) = '(table voiture)

(produits-double produit-Julie produit-Jules)

;=====================================================================================================================================
 
;sommer la liste (somme liste)

;1 1 3 5 7 10 12 15 | 21
;max<=21 = 15 -> 21 -15 = 6
;res = '(15)

;1 1 3 5 7 10 12 | 6
;max<=6 = 5 -> 6-5 = 1
;res = '(5 15)

;1 1 3 7 10 12 | 1
;max<=1 = 1 -> 1-1 = 0
;res = '(1 5 15)


(define values2test '(1 1 3 5 7 10 12 15))
(define values2test2 '(15 1 3 5 7 10 12 15))
(define total 13)


(define (comptebon s l)
  (cond
    ((= s 0) '())
    ((null? l) #f)
    ((< s 0) #f)
    (else
     (let ((r (comptebon (- s (car l)) (cdr l))))
       (if(list? r)
          (cons (car l) r)
          (comptebon s (cdr l))
       )
     )
    )
  )
)


(comptebon total values2test)
(comptebon total values2test2)