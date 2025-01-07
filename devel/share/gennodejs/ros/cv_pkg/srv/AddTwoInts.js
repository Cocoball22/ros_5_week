// Auto-generated. Do not edit!

// (in-package cv_pkg.srv)


"use strict";

const _serializer = _ros_msg_utils.Serialize;
const _arraySerializer = _serializer.Array;
const _deserializer = _ros_msg_utils.Deserialize;
const _arrayDeserializer = _deserializer.Array;
const _finder = _ros_msg_utils.Find;
const _getByteLength = _ros_msg_utils.getByteLength;

//-----------------------------------------------------------


//-----------------------------------------------------------

class AddTwoIntsRequest {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.image_path = null;
    }
    else {
      if (initObj.hasOwnProperty('image_path')) {
        this.image_path = initObj.image_path
      }
      else {
        this.image_path = '';
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type AddTwoIntsRequest
    // Serialize message field [image_path]
    bufferOffset = _serializer.string(obj.image_path, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type AddTwoIntsRequest
    let len;
    let data = new AddTwoIntsRequest(null);
    // Deserialize message field [image_path]
    data.image_path = _deserializer.string(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    let length = 0;
    length += _getByteLength(object.image_path);
    return length + 4;
  }

  static datatype() {
    // Returns string type for a service object
    return 'cv_pkg/AddTwoIntsRequest';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '65568c775bfbc96c6265c3d13d7e1a07';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    string image_path
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new AddTwoIntsRequest(null);
    if (msg.image_path !== undefined) {
      resolved.image_path = msg.image_path;
    }
    else {
      resolved.image_path = ''
    }

    return resolved;
    }
};

class AddTwoIntsResponse {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.fruit_type = null;
    }
    else {
      if (initObj.hasOwnProperty('fruit_type')) {
        this.fruit_type = initObj.fruit_type
      }
      else {
        this.fruit_type = '';
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type AddTwoIntsResponse
    // Serialize message field [fruit_type]
    bufferOffset = _serializer.string(obj.fruit_type, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type AddTwoIntsResponse
    let len;
    let data = new AddTwoIntsResponse(null);
    // Deserialize message field [fruit_type]
    data.fruit_type = _deserializer.string(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    let length = 0;
    length += _getByteLength(object.fruit_type);
    return length + 4;
  }

  static datatype() {
    // Returns string type for a service object
    return 'cv_pkg/AddTwoIntsResponse';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '99d8fef110621c4aa23a2848c4b7110f';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    string fruit_type
    
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new AddTwoIntsResponse(null);
    if (msg.fruit_type !== undefined) {
      resolved.fruit_type = msg.fruit_type;
    }
    else {
      resolved.fruit_type = ''
    }

    return resolved;
    }
};

module.exports = {
  Request: AddTwoIntsRequest,
  Response: AddTwoIntsResponse,
  md5sum() { return '4a399bc94c653d283002e008e813f40e'; },
  datatype() { return 'cv_pkg/AddTwoInts'; }
};
