; Auto-generated. Do not edit!


(cl:in-package cv_pkg-srv)


;//! \htmlinclude ImageClassify-request.msg.html

(cl:defclass <ImageClassify-request> (roslisp-msg-protocol:ros-message)
  ((image_path
    :reader image_path
    :initarg :image_path
    :type cl:string
    :initform ""))
)

(cl:defclass ImageClassify-request (<ImageClassify-request>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <ImageClassify-request>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'ImageClassify-request)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name cv_pkg-srv:<ImageClassify-request> is deprecated: use cv_pkg-srv:ImageClassify-request instead.")))

(cl:ensure-generic-function 'image_path-val :lambda-list '(m))
(cl:defmethod image_path-val ((m <ImageClassify-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader cv_pkg-srv:image_path-val is deprecated.  Use cv_pkg-srv:image_path instead.")
  (image_path m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <ImageClassify-request>) ostream)
  "Serializes a message object of type '<ImageClassify-request>"
  (cl:let ((__ros_str_len (cl:length (cl:slot-value msg 'image_path))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_str_len) ostream))
  (cl:map cl:nil #'(cl:lambda (c) (cl:write-byte (cl:char-code c) ostream)) (cl:slot-value msg 'image_path))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <ImageClassify-request>) istream)
  "Deserializes a message object of type '<ImageClassify-request>"
    (cl:let ((__ros_str_len 0))
      (cl:setf (cl:ldb (cl:byte 8 0) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'image_path) (cl:make-string __ros_str_len))
      (cl:dotimes (__ros_str_idx __ros_str_len msg)
        (cl:setf (cl:char (cl:slot-value msg 'image_path) __ros_str_idx) (cl:code-char (cl:read-byte istream)))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<ImageClassify-request>)))
  "Returns string type for a service object of type '<ImageClassify-request>"
  "cv_pkg/ImageClassifyRequest")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'ImageClassify-request)))
  "Returns string type for a service object of type 'ImageClassify-request"
  "cv_pkg/ImageClassifyRequest")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<ImageClassify-request>)))
  "Returns md5sum for a message object of type '<ImageClassify-request>"
  "4a399bc94c653d283002e008e813f40e")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'ImageClassify-request)))
  "Returns md5sum for a message object of type 'ImageClassify-request"
  "4a399bc94c653d283002e008e813f40e")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<ImageClassify-request>)))
  "Returns full string definition for message of type '<ImageClassify-request>"
  (cl:format cl:nil "string image_path~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'ImageClassify-request)))
  "Returns full string definition for message of type 'ImageClassify-request"
  (cl:format cl:nil "string image_path~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <ImageClassify-request>))
  (cl:+ 0
     4 (cl:length (cl:slot-value msg 'image_path))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <ImageClassify-request>))
  "Converts a ROS message object to a list"
  (cl:list 'ImageClassify-request
    (cl:cons ':image_path (image_path msg))
))
;//! \htmlinclude ImageClassify-response.msg.html

(cl:defclass <ImageClassify-response> (roslisp-msg-protocol:ros-message)
  ((fruit_type
    :reader fruit_type
    :initarg :fruit_type
    :type cl:string
    :initform ""))
)

(cl:defclass ImageClassify-response (<ImageClassify-response>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <ImageClassify-response>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'ImageClassify-response)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name cv_pkg-srv:<ImageClassify-response> is deprecated: use cv_pkg-srv:ImageClassify-response instead.")))

(cl:ensure-generic-function 'fruit_type-val :lambda-list '(m))
(cl:defmethod fruit_type-val ((m <ImageClassify-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader cv_pkg-srv:fruit_type-val is deprecated.  Use cv_pkg-srv:fruit_type instead.")
  (fruit_type m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <ImageClassify-response>) ostream)
  "Serializes a message object of type '<ImageClassify-response>"
  (cl:let ((__ros_str_len (cl:length (cl:slot-value msg 'fruit_type))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_str_len) ostream))
  (cl:map cl:nil #'(cl:lambda (c) (cl:write-byte (cl:char-code c) ostream)) (cl:slot-value msg 'fruit_type))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <ImageClassify-response>) istream)
  "Deserializes a message object of type '<ImageClassify-response>"
    (cl:let ((__ros_str_len 0))
      (cl:setf (cl:ldb (cl:byte 8 0) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'fruit_type) (cl:make-string __ros_str_len))
      (cl:dotimes (__ros_str_idx __ros_str_len msg)
        (cl:setf (cl:char (cl:slot-value msg 'fruit_type) __ros_str_idx) (cl:code-char (cl:read-byte istream)))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<ImageClassify-response>)))
  "Returns string type for a service object of type '<ImageClassify-response>"
  "cv_pkg/ImageClassifyResponse")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'ImageClassify-response)))
  "Returns string type for a service object of type 'ImageClassify-response"
  "cv_pkg/ImageClassifyResponse")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<ImageClassify-response>)))
  "Returns md5sum for a message object of type '<ImageClassify-response>"
  "4a399bc94c653d283002e008e813f40e")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'ImageClassify-response)))
  "Returns md5sum for a message object of type 'ImageClassify-response"
  "4a399bc94c653d283002e008e813f40e")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<ImageClassify-response>)))
  "Returns full string definition for message of type '<ImageClassify-response>"
  (cl:format cl:nil "string fruit_type~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'ImageClassify-response)))
  "Returns full string definition for message of type 'ImageClassify-response"
  (cl:format cl:nil "string fruit_type~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <ImageClassify-response>))
  (cl:+ 0
     4 (cl:length (cl:slot-value msg 'fruit_type))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <ImageClassify-response>))
  "Converts a ROS message object to a list"
  (cl:list 'ImageClassify-response
    (cl:cons ':fruit_type (fruit_type msg))
))
(cl:defmethod roslisp-msg-protocol:service-request-type ((msg (cl:eql 'ImageClassify)))
  'ImageClassify-request)
(cl:defmethod roslisp-msg-protocol:service-response-type ((msg (cl:eql 'ImageClassify)))
  'ImageClassify-response)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'ImageClassify)))
  "Returns string type for a service object of type '<ImageClassify>"
  "cv_pkg/ImageClassify")