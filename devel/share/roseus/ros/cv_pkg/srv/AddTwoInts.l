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
  :slots (_a _b ))

(defmethod cv_pkg::AddTwoIntsRequest
  (:init
   (&key
    ((:a __a) 0)
    ((:b __b) 0)
    )
   (send-super :init)
   (setq _a (round __a))
   (setq _b (round __b))
   self)
  (:a
   (&optional __a)
   (if __a (setq _a __a)) _a)
  (:b
   (&optional __b)
   (if __b (setq _b __b)) _b)
  (:serialization-length
   ()
   (+
    ;; int32 _a
    4
    ;; int32 _b
    4
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; int32 _a
       (write-long _a s)
     ;; int32 _b
       (write-long _b s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; int32 _a
     (setq _a (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;; int32 _b
     (setq _b (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;;
   self)
  )

(defclass cv_pkg::AddTwoIntsResponse
  :super ros::object
  :slots (_sum ))

(defmethod cv_pkg::AddTwoIntsResponse
  (:init
   (&key
    ((:sum __sum) 0)
    )
   (send-super :init)
   (setq _sum (round __sum))
   self)
  (:sum
   (&optional __sum)
   (if __sum (setq _sum __sum)) _sum)
  (:serialization-length
   ()
   (+
    ;; int32 _sum
    4
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; int32 _sum
       (write-long _sum s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; int32 _sum
     (setq _sum (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;;
   self)
  )

(defclass cv_pkg::AddTwoInts
  :super ros::object
  :slots ())

(setf (get cv_pkg::AddTwoInts :md5sum-) "f0b6d69ea10b0cf210cb349d58d59e8f")
(setf (get cv_pkg::AddTwoInts :datatype-) "cv_pkg/AddTwoInts")
(setf (get cv_pkg::AddTwoInts :request) cv_pkg::AddTwoIntsRequest)
(setf (get cv_pkg::AddTwoInts :response) cv_pkg::AddTwoIntsResponse)

(defmethod cv_pkg::AddTwoIntsRequest
  (:response () (instance cv_pkg::AddTwoIntsResponse :init)))

(setf (get cv_pkg::AddTwoIntsRequest :md5sum-) "f0b6d69ea10b0cf210cb349d58d59e8f")
(setf (get cv_pkg::AddTwoIntsRequest :datatype-) "cv_pkg/AddTwoIntsRequest")
(setf (get cv_pkg::AddTwoIntsRequest :definition-)
      "int32 a
int32 b
---
int32 sum

")

(setf (get cv_pkg::AddTwoIntsResponse :md5sum-) "f0b6d69ea10b0cf210cb349d58d59e8f")
(setf (get cv_pkg::AddTwoIntsResponse :datatype-) "cv_pkg/AddTwoIntsResponse")
(setf (get cv_pkg::AddTwoIntsResponse :definition-)
      "int32 a
int32 b
---
int32 sum

")



(provide :cv_pkg/AddTwoInts "f0b6d69ea10b0cf210cb349d58d59e8f")


