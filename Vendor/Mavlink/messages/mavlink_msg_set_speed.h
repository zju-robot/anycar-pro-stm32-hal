#pragma once
// MESSAGE SET_SPEED PACKING

#define MAVLINK_MSG_ID_SET_SPEED 10


typedef struct __mavlink_set_speed_t {
 float xVel; /*< [m/s] */
 float yawRate; /*< [rad/s] */
} mavlink_set_speed_t;

#define MAVLINK_MSG_ID_SET_SPEED_LEN 8
#define MAVLINK_MSG_ID_SET_SPEED_MIN_LEN 8
#define MAVLINK_MSG_ID_10_LEN 8
#define MAVLINK_MSG_ID_10_MIN_LEN 8

#define MAVLINK_MSG_ID_SET_SPEED_CRC 70
#define MAVLINK_MSG_ID_10_CRC 70



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_SET_SPEED { \
    10, \
    "SET_SPEED", \
    2, \
    {  { "xVel", NULL, MAVLINK_TYPE_FLOAT, 0, 0, offsetof(mavlink_set_speed_t, xVel) }, \
         { "yawRate", NULL, MAVLINK_TYPE_FLOAT, 0, 4, offsetof(mavlink_set_speed_t, yawRate) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_SET_SPEED { \
    "SET_SPEED", \
    2, \
    {  { "xVel", NULL, MAVLINK_TYPE_FLOAT, 0, 0, offsetof(mavlink_set_speed_t, xVel) }, \
         { "yawRate", NULL, MAVLINK_TYPE_FLOAT, 0, 4, offsetof(mavlink_set_speed_t, yawRate) }, \
         } \
}
#endif

/**
 * @brief Pack a set_speed message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param xVel [m/s] 
 * @param yawRate [rad/s] 
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_set_speed_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               float xVel, float yawRate)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_SET_SPEED_LEN];
    _mav_put_float(buf, 0, xVel);
    _mav_put_float(buf, 4, yawRate);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_SET_SPEED_LEN);
#else
    mavlink_set_speed_t packet;
    packet.xVel = xVel;
    packet.yawRate = yawRate;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_SET_SPEED_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_SET_SPEED;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_SET_SPEED_MIN_LEN, MAVLINK_MSG_ID_SET_SPEED_LEN, MAVLINK_MSG_ID_SET_SPEED_CRC);
}

/**
 * @brief Pack a set_speed message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param xVel [m/s] 
 * @param yawRate [rad/s] 
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_set_speed_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   float xVel,float yawRate)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_SET_SPEED_LEN];
    _mav_put_float(buf, 0, xVel);
    _mav_put_float(buf, 4, yawRate);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_SET_SPEED_LEN);
#else
    mavlink_set_speed_t packet;
    packet.xVel = xVel;
    packet.yawRate = yawRate;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_SET_SPEED_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_SET_SPEED;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_SET_SPEED_MIN_LEN, MAVLINK_MSG_ID_SET_SPEED_LEN, MAVLINK_MSG_ID_SET_SPEED_CRC);
}

/**
 * @brief Encode a set_speed struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param set_speed C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_set_speed_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_set_speed_t* set_speed)
{
    return mavlink_msg_set_speed_pack(system_id, component_id, msg, set_speed->xVel, set_speed->yawRate);
}

/**
 * @brief Encode a set_speed struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param set_speed C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_set_speed_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_set_speed_t* set_speed)
{
    return mavlink_msg_set_speed_pack_chan(system_id, component_id, chan, msg, set_speed->xVel, set_speed->yawRate);
}

/**
 * @brief Send a set_speed message
 * @param chan MAVLink channel to send the message
 *
 * @param xVel [m/s] 
 * @param yawRate [rad/s] 
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_set_speed_send(mavlink_channel_t chan, float xVel, float yawRate)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_SET_SPEED_LEN];
    _mav_put_float(buf, 0, xVel);
    _mav_put_float(buf, 4, yawRate);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SET_SPEED, buf, MAVLINK_MSG_ID_SET_SPEED_MIN_LEN, MAVLINK_MSG_ID_SET_SPEED_LEN, MAVLINK_MSG_ID_SET_SPEED_CRC);
#else
    mavlink_set_speed_t packet;
    packet.xVel = xVel;
    packet.yawRate = yawRate;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SET_SPEED, (const char *)&packet, MAVLINK_MSG_ID_SET_SPEED_MIN_LEN, MAVLINK_MSG_ID_SET_SPEED_LEN, MAVLINK_MSG_ID_SET_SPEED_CRC);
#endif
}

/**
 * @brief Send a set_speed message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_set_speed_send_struct(mavlink_channel_t chan, const mavlink_set_speed_t* set_speed)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_set_speed_send(chan, set_speed->xVel, set_speed->yawRate);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SET_SPEED, (const char *)set_speed, MAVLINK_MSG_ID_SET_SPEED_MIN_LEN, MAVLINK_MSG_ID_SET_SPEED_LEN, MAVLINK_MSG_ID_SET_SPEED_CRC);
#endif
}

#if MAVLINK_MSG_ID_SET_SPEED_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This variant of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_set_speed_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  float xVel, float yawRate)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_float(buf, 0, xVel);
    _mav_put_float(buf, 4, yawRate);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SET_SPEED, buf, MAVLINK_MSG_ID_SET_SPEED_MIN_LEN, MAVLINK_MSG_ID_SET_SPEED_LEN, MAVLINK_MSG_ID_SET_SPEED_CRC);
#else
    mavlink_set_speed_t *packet = (mavlink_set_speed_t *)msgbuf;
    packet->xVel = xVel;
    packet->yawRate = yawRate;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SET_SPEED, (const char *)packet, MAVLINK_MSG_ID_SET_SPEED_MIN_LEN, MAVLINK_MSG_ID_SET_SPEED_LEN, MAVLINK_MSG_ID_SET_SPEED_CRC);
#endif
}
#endif

#endif

// MESSAGE SET_SPEED UNPACKING


/**
 * @brief Get field xVel from set_speed message
 *
 * @return [m/s] 
 */
static inline float mavlink_msg_set_speed_get_xVel(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  0);
}

/**
 * @brief Get field yawRate from set_speed message
 *
 * @return [rad/s] 
 */
static inline float mavlink_msg_set_speed_get_yawRate(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  4);
}

/**
 * @brief Decode a set_speed message into a struct
 *
 * @param msg The message to decode
 * @param set_speed C-struct to decode the message contents into
 */
static inline void mavlink_msg_set_speed_decode(const mavlink_message_t* msg, mavlink_set_speed_t* set_speed)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    set_speed->xVel = mavlink_msg_set_speed_get_xVel(msg);
    set_speed->yawRate = mavlink_msg_set_speed_get_yawRate(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_SET_SPEED_LEN? msg->len : MAVLINK_MSG_ID_SET_SPEED_LEN;
        memset(set_speed, 0, MAVLINK_MSG_ID_SET_SPEED_LEN);
    memcpy(set_speed, _MAV_PAYLOAD(msg), len);
#endif
}
