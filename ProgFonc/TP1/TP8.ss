(define (nbj-mars annee)
(let
  (
    (a (remainder annee 19))
    (b (remainder annee 4))
    (c (remainder annee 7))
  )
  (let ((d (remainder (+(* 19 a) 24) 30)))
  (let ((e (remainder (+ (* 2 b) (* 4 c) (* 6 d) 5) 7)))
  (let ((res (+ 22 d e)))
  res
  )
  )
  )
  )
)

(define (jour nbj)
  (if (<= nbj 31)(nbj)(- nbj 31))
)

(define (mois nbj)
  (if (<= nbj 31) 'mars 'avril)
)


(define an 2017)
(define (affiche j m a)
  (display "date de pâques: ")
  (display j)
  (display " ")
  (display m)
  (display " ")
  (display a)
)

(affiche (jour (nbj-mars an)) (mois (nbj-mars an)) an)
