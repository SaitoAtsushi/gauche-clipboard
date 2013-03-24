;;;
;;; gauche_clipboard
;;;

(define-module clipboard
  (use gauche.charconv)
  (export write-clipboard
          read-clipboard)
  )
(select-module clipboard)

(dynamic-load "gauche_clipboard")

(define write-clipboard
  (cond-expand
   ((not gauche.ces.utf8)
    (lambda(s)
      (write-clipboard-internal
       (ces-convert s (gauche-character-encoding) 'utf-8))))
   (else write-clipboard-internal)))

(define read-clipboard
  (cond-expand
   ((not gauche.ces.utf8)
    (lambda()
      (ces-convert (read-clipboard-internal)
                   'utf-8
                   (gauche-character-encoding))))
   (else read-clipboard-internal)))

