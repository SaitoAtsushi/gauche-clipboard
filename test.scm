;;;
;;; Test clipboard
;;;

(use gauche.test)

(test-start "clipboard")
(use clipboard)
(test-module 'clipboard)

(write-clipboard "abc")

(test* "read_clipboard" "abc"
       (read-clipboard))

(test-end :exit-on-failure #t)


