(define (carre x)(* x x))
(define (cube x)(* x x x))                      

(define (f x y)(+ 
                  (/ (- x 3) 
                       (+ (carre y) 1)) 
                    (/ 1 
                       (+ (cube x) 3))))

(display (f 10 10))

(define (cel->far c)(+ (* (/ 9 5) c) 32))

(newline)
(display(cel->far 15))

(define (distance Xa Xb Ya Yb)(sqrt (
                                     + (carre (- Xb Xa))
                                       (carre( - Yb Ya)))))

(newline)
(display(distance 2 5 0 0))


(define (m->s m)(* 60 m))
(define (h->m h)(* 60 h))

(define(h->s h m s)(+ (m->s(h->m h)) (m->s m) s)) 

(newline)
(display (h->s 1 1 1))

(define (moy-pond n1 n2 c1 c2)
  (/ (+ (* n1 c1) (* n2 c2)) (+ c1 c2))
)

(newline)
(display ( moy-pond 10 10 1 1))
                       