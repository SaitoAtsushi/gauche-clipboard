;;;
;;; coding: utf-8
;;; Test clipboard
;;;

(use gauche.test)

(test-start "clipboard")
(use clipboard)
(test-module 'clipboard)

(write-clipboard "abc")

(test* "read clipboard latain alphabet" "abc"
       (read-clipboard))

(write-clipboard "日本語文字列")

(test* "read clipboard kanji" "日本語文字列"
       (read-clipboard))

(test-end :exit-on-failure #t)
