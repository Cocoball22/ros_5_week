
(cl:in-package :asdf)

(defsystem "cv_pkg-srv"
  :depends-on (:roslisp-msg-protocol :roslisp-utils )
  :components ((:file "_package")
    (:file "ImageClassify" :depends-on ("_package_ImageClassify"))
    (:file "_package_ImageClassify" :depends-on ("_package"))
  ))