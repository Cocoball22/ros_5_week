;; Auto-generated. Do not edit!


(when (boundp 'cv_pkg::AddTwoInts)
  (if (not (find-package "CV_PKG"))
    (make-package "CV_PKG"))
  (shadow 'AddTwoInts (find-package "CV_PKG")))
(unless (find-package "CV_PKG::ADDTWOINTS")
  (make-package "CV_PKG::ADDTWOINTS"))
(unless (find-package "CV_PKG::ADDTWOINTSREQUEST")
  (make-package "CV_PKG::ADDTWOINTSREQUEST"))
(unless (find-package "CV_PKG::ADDTWOINTSRESPONSE")
  (make-package "CV_PKG::ADDTWOINTSRESPONSE"))

(in-package "ROS")





(defclass cv_pkg::AddTwoIntsRequest
  :super ros::object
  :slots (_image_path ))

(defmethod cv_pkg::AddTwoIntsRequest
  (:init
   (&key
    ((:image_path __image_path) "")
    )
   (send-super :init)
   (setq _image_path (string __image_path))
   self)
  (:image_path
   (&optional __image_path)
   (if __image_path (setq _image_path __image_path)) _image_path)
  (:serialization-length
   ()
   (+
    ;; string _image_path
    4 (length _image_path)
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; string _image_path
       (write-long (length _image_path) s) (princ _image_path s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; string _image_path
     (let (n) (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4) (setq _image_path (subseq buf ptr- (+ ptr- n))) (incf ptr- n))
   ;;
   self)
  )

(defclass cv_pkg::AddTwoIntsResponse
  :super ros::object
  :slots (_fruit_type ))

(defmethod cv_pkg::AddTwoIntsResponse
  (:init
   (&key
    ((:fruit_type __fruit_type) "")
    )
   (send-super :init)
   (setq _fruit_type (string __fruit_type))
   self)
  (:fruit_type
   (&optional __fruit_type)
   (if __fruit_type (setq _fruit_type __fruit_type)) _fruit_type)
  (:serialization-length
   ()
   (+
    ;; string _fruit_type
    4 (length _fruit_type)
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; string _fruit_type
       (write-long (length _fruit_type) s) (princ _fruit_type s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; string _fruit_type
     (let (n) (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4) (setq _fruit_type (subseq buf ptr- (+ ptr- n))) (incf ptr- n))
   ;;
   self)
  )

(defclass cv_pkg::AddTwoInts
  :super ros::object
  :slots ())

(setf (get cv_pkg::AddTwoInts :md5sum-) "4a399bc94c653d283002e008e813f40e")
(setf (get cv_pkg::AddTwoInts :datatype-) "cv_pkg/AddTwoInts")
(setf (get cv_pkg::AddTwoInts :request) cv_pkg::AddTwoIntsRequest)
(setf (get cv_pkg::AddTwoInts :response) cv_pkg::AddTwoIntsResponse)

(defmethod cv_pkg::AddTwoIntsRequest
  (:response () (instance cv_pkg::AddTwoIntsResponse :init)))

(setf (get cv_pkg::AddTwoIntsRequest :md5sum-) "4a399bc94c653d283002e008e813f40e")
(setf (get cv_pkg::AddTwoIntsRequest :datatype-) "cv_pkg/AddTwoIntsRequest")
(setf (get cv_pkg::AddTwoIntsRequest :definition-)
      "string image_path
---
string fruit_type

")

(setf (get cv_pkg::AddTwoIntsResponse :md5sum-) "4a399bc94c653d283002e008e813f40e")
(setf (get cv_pkg::AddTwoIntsResponse :datatype-) "cv_pkg/AddTwoIntsResponse")
(setf (get cv_pkg::AddTwoIntsResponse :definition-)
      "string image_path
---
string fruit_type

")



(provide :cv_pkg/AddTwoInts "4a399bc94c653d283002e008e813f40e")


