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

(define (write-clipboard s)
  (write-clipboard-internal
   (ces-convert s (gauche-character-encoding) 'utf-8)))

(define (read-clipboard)
  (ces-convert (read-clipboard-internal) 'utf-8 (gauche-character-encoding)))

