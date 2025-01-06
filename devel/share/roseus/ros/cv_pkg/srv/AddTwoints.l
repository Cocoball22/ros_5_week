;; Auto-generated. Do not edit!


(when (boundp 'cv_pkg::AddTwoints)
  (if (not (find-package "CV_PKG"))
    (make-package "CV_PKG"))
  (shadow 'AddTwoints (find-package "CV_PKG")))
(unless (find-package "CV_PKG::ADDTWOINTS")
  (make-package "CV_PKG::ADDTWOINTS"))
(unless (find-package "CV_PKG::ADDTWOINTSREQUEST")
  (make-package "CV_PKG::ADDTWOINTSREQUEST"))
(unless (find-package "CV_PKG::ADDTWOINTSRESPONSE")
  (make-package "CV_PKG::ADDTWOINTSRESPONSE"))

(in-package "ROS")





(defclass cv_pkg::AddTwointsRequest
  :super ros::object
  :slots (_num ))

(defmethod cv_pkg::AddTwointsRequest
  (:init
   (&key
    ((:num __num) 0)
    )
   (send-super :init)
   (setq _num (round __num))
   self)
  (:num
   (&optional __num)
   (if __num (setq _num __num)) _num)
  (:serialization-length
   ()
   (+
    ;; int32 _num
    4
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; int32 _num
       (write-long _num s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; int32 _num
     (setq _num (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;;
   self)
  )

(defclass cv_pkg::AddTwointsResponse
  :super ros::object
  :slots (_name ))

(defmethod cv_pkg::AddTwointsResponse
  (:init
   (&key
    ((:name __name) "")
    )
   (send-super :init)
   (setq _name (string __name))
   self)
  (:name
   (&optional __name)
   (if __name (setq _name __name)) _name)
  (:serialization-length
   ()
   (+
    ;; string _name
    4 (length _name)
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; string _name
       (write-long (length _name) s) (princ _name s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; string _name
     (let (n) (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4) (setq _name (subseq buf ptr- (+ ptr- n))) (incf ptr- n))
   ;;
   self)
  )

(defclass cv_pkg::AddTwoints
  :super ros::object
  :slots ())

(setf (get cv_pkg::AddTwoints :md5sum-) "563505b24ec7ec919ab1d0c28096de40")
(setf (get cv_pkg::AddTwoints :datatype-) "cv_pkg/AddTwoints")
(setf (get cv_pkg::AddTwoints :request) cv_pkg::AddTwointsRequest)
(setf (get cv_pkg::AddTwoints :response) cv_pkg::AddTwointsResponse)

(defmethod cv_pkg::AddTwointsRequest
  (:response () (instance cv_pkg::AddTwointsResponse :init)))

(setf (get cv_pkg::AddTwointsRequest :md5sum-) "563505b24ec7ec919ab1d0c28096de40")
(setf (get cv_pkg::AddTwointsRequest :datatype-) "cv_pkg/AddTwointsRequest")
(setf (get cv_pkg::AddTwointsRequest :definition-)
      "int32 num
---
string name

")

(setf (get cv_pkg::AddTwointsResponse :md5sum-) "563505b24ec7ec919ab1d0c28096de40")
(setf (get cv_pkg::AddTwointsResponse :datatype-) "cv_pkg/AddTwointsResponse")
(setf (get cv_pkg::AddTwointsResponse :definition-)
      "int32 num
---
string name

")



(provide :cv_pkg/AddTwoints "563505b24ec7ec919ab1d0c28096de40")


