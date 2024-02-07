;Return the level of a node X in a tree of type (1). The level of the root element is 0.

; pargurg_st(l1l2...ln, nrNoduri, nrMuchii) = 
; = nil, if n = 0
; = nil, if nrNoduri = 1 + nrMuchii
; = {l1} U {l2} U parcurg_st(l3...ln, nrNoduri + 1, l2 + nrMuchii), otherwise

(defun parcurg_st(arb nrNoduri nrMuchii)
  (cond
   ((null arb) nil)
   ((= nrNoduri (+ 1 nrMuchii)) nil)
   (t (cons (car arb)
           (cons (cadr arb)
                 (parcurg_st (cddr arb) 
                             (+ 1 nrNoduri)
                             (+ (cadr arb) nrMuchii)
                 )
           )
      )
   )
  )
)

;stang(l1l2...ln) = 
; = parcurg_st(l3...ln, 0,0)
(defun stang (arb)
  (parcurg_st (cddr arb) 0 0)
)

; parcurg_dr(l1l2...ln, nrNoduri, nrMuchii) =
; = nil, if n = 0
; = l1l2...ln, if nrNoduri = 1 + nrMuchii
; = parcurg_dr(l3...ln, nrNoduri + 1, nrMuchii + l2), otherwise

(defun parcurg_dr (arb nrNoduri nrMuchii)
  (cond
   ((null arb) nil)
   ((= nrNoduri (+ 1 nrMuchii)) arb)
   (t (parcurg_dr (cddr arb) (+ 1 nrNoduri) (+ (cadr arb) nrMuchii)))
  )
)

;drept(l1l2...ln) =
; = parcurg_dr(l3...ln, 0, 0)
(defun drept (arb)
  (parcurg_dr (cddr arb) 0 0)
)

; findLevel(l1l2...ln, elem, level) = 
; = 0, if n = 0
; = level, if l1 = elem
; = findLevel(stang(l), elem, level + 1) + findLevel(drept(l), elem, level + 1)
(defun findLevel(l elem level)
  (cond
    ((null l) 0)
    ((equal (car l) elem) level)
    (t (+ (findLevel (stang l) elem (+ 1 level)) (findLevel (drept l) elem (+ 1 level))))
  )
)

(defun main(l elem)
  (findLevel l elem 0)
)