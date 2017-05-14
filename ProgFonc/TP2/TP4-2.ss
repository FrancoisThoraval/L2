(load "libpile.ss")

(define (calcpost)
  (let ((elem (read)))
    (cond (number? elem)(empiler elem)
          (symbol? elem)(
                          (let ((x 0)
                                (y 0))
                                
                            (set! x (sommet))
                            (depiler)
                            (set! y (sommet))
                            (depiler)
                            (empiler (elem x y))
                          )
                          
                          (calcpost)
                          )))
                          
)

(calcpost)