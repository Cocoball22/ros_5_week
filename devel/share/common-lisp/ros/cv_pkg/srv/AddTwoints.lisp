; Auto-generated. Do not edit!


(cl:in-package cv_pkg-srv)


;//! \htmlinclude AddTwoints-request.msg.html

(cl:defclass <AddTwoints-request> (roslisp-msg-protocol:ros-message)
  ((num
    :reader num
    :initarg :num
    :type cl:integer
    :initform 0))
)

(cl:defclass AddTwoints-request (<AddTwoints-request>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <AddTwoints-request>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'AddTwoints-request)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name cv_pkg-srv:<AddTwoints-request> is deprecated: use cv_pkg-srv:AddTwoints-request instead.")))

(cl:ensure-generic-function 'num-val :lambda-list '(m))
(cl:defmethod num-val ((m <AddTwoints-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader cv_pkg-srv:num-val is deprecated.  Use cv_pkg-srv:num instead.")
  (num m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <AddTwoints-request>) ostream)
  "Serializes a message object of type '<AddTwoints-request>"
  (cl:let* ((signed (cl:slot-value msg 'num)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 4294967296) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    )
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <AddTwoints-request>) istream)
  "Deserializes a message object of type '<AddTwoints-request>"
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'num) (cl:if (cl:< unsigned 2147483648) unsigned (cl:- unsigned 4294967296))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<AddTwoints-request>)))
  "Returns string type for a service object of type '<AddTwoints-request>"
  "cv_pkg/AddTwointsRequest")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'AddTwoints-request)))
  "Returns string type for a service object of type 'AddTwoints-request"
  "cv_pkg/AddTwointsRequest")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<AddTwoints-request>)))
  "Returns md5sum for a message object of type '<AddTwoints-request>"
  "563505b24ec7ec919ab1d0c28096de40")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'AddTwoints-request)))
  "Returns md5sum for a message object of type 'AddTwoints-request"
  "563505b24ec7ec919ab1d0c28096de40")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<AddTwoints-request>)))
  "Returns full string definition for message of type '<AddTwoints-request>"
  (cl:format cl:nil "int32 num~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'AddTwoints-request)))
  "Returns full string definition for message of type 'AddTwoints-request"
  (cl:format cl:nil "int32 num~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <AddTwoints-request>))
  (cl:+ 0
     4
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <AddTwoints-request>))
  "Converts a ROS message object to a list"
  (cl:list 'AddTwoints-request
    (cl:cons ':num (num msg))
))
;//! \htmlinclude AddTwoints-response.msg.html

(cl:defclass <AddTwoints-response> (roslisp-msg-protocol:ros-message)
  ((name
    :reader name
    :initarg :name
    :type cl:string
    :initform ""))
)

(cl:defclass AddTwoints-response (<AddTwoints-response>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <AddTwoints-response>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'AddTwoints-response)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name cv_pkg-srv:<AddTwoints-response> is deprecated: use cv_pkg-srv:AddTwoints-response instead.")))

(cl:ensure-generic-function 'name-val :lambda-list '(m))
(cl:defmethod name-val ((m <AddTwoints-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader cv_pkg-srv:name-val is deprecated.  Use cv_pkg-srv:name instead.")
  (name m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <AddTwoints-response>) ostream)
  "Serializes a message object of type '<AddTwoints-response>"
  (cl:let ((__ros_str_len (cl:length (cl:slot-value msg 'name))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_str_len) ostream))
  (cl:map cl:nil #'(cl:lambda (c) (cl:write-byte (cl:char-code c) ostream)) (cl:slot-value msg 'name))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <AddTwoints-response>) istream)
  "Deserializes a message object of type '<AddTwoints-response>"
    (cl:let ((__ros_str_len 0))
      (cl:setf (cl:ldb (cl:byte 8 0) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'name) (cl:make-string __ros_str_len))
      (cl:dotimes (__ros_str_idx __ros_str_len msg)
        (cl:setf (cl:char (cl:slot-value msg 'name) __ros_str_idx) (cl:code-char (cl:read-byte istream)))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<AddTwoints-response>)))
  "Returns string type for a service object of type '<AddTwoints-response>"
  "cv_pkg/AddTwointsResponse")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'AddTwoints-response)))
  "Returns string type for a service object of type 'AddTwoints-response"
  "cv_pkg/AddTwointsResponse")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<AddTwoints-response>)))
  "Returns md5sum for a message object of type '<AddTwoints-response>"
  "563505b24ec7ec919ab1d0c28096de40")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'AddTwoints-response)))
  "Returns md5sum for a message object of type 'AddTwoints-response"
  "563505b24ec7ec919ab1d0c28096de40")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<AddTwoints-response>)))
  "Returns full string definition for message of type '<AddTwoints-response>"
  (cl:format cl:nil "string name~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'AddTwoints-response)))
  "Returns full string definition for message of type 'AddTwoints-response"
  (cl:format cl:nil "string name~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <AddTwoints-response>))
  (cl:+ 0
     4 (cl:length (cl:slot-value msg 'name))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <AddTwoints-response>))
  "Converts a ROS message object to a list"
  (cl:list 'AddTwoints-response
    (cl:cons ':name (name msg))
))
(cl:defmethod roslisp-msg-protocol:service-request-type ((msg (cl:eql 'AddTwoints)))
  'AddTwoints-request)
(cl:defmethod roslisp-msg-protocol:service-response-type ((msg (cl:eql 'AddTwoints)))
  'AddTwoints-response)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'AddTwoints)))
  "Returns string type for a service object of type '<AddTwoints>"
  "cv_pkg/AddTwoints")