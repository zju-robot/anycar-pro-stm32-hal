#pragma once
// MESSAGE MOTION_STATE PACKING

#define MAVLINK_MSG_ID_MOTION_STATE 20


typedef struct __mavlink_motion_state_t {
 float x; /*< [m] */
 float y; /*< [m] */
 float yaw; /*< [rad] */
 float xVel; /*< [m/s] */
 float yawRate; /*< [rad/s] */
} mavlink_motion_state_t;

#define MAVLINK_MSG_ID_MOTION_STATE_LEN 20
#define MAVLINK_MSG_ID_MOTION_STATE_MIN_LEN 20
#define MAVLINK_MSG_ID_20_LEN 20
#define MAVLINK_MSG_ID_20_MIN_LEN 20

#define MAVLINK_MSG_ID_MOTION_STATE_CRC 160
#define MAVLINK_MSG_ID_20_CRC 160



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_MOTION_STATE { \
    20, \
    "MOTION_STATE", \
    5, \
    {  { "x", NULL, MAVLINK_TYPE_FLOAT, 0, 0, offsetof(mavlink_motion_state_t, x) }, \
         { "y", NULL, MAVLINK_TYPE_FLOAT, 0, 4, offsetof(mavlink_motion_state_t, y) }, \
         { "yaw", NULL, MAVLINK_TYPE_FLOAT, 0, 8, offsetof(mavlink_motion_state_t, yaw) }, \
         { "xVel", NULL, MAVLINK_TYPE_FLOAT, 0, 12, offsetof(mavlink_motion_state_t, xVel) }, \
         { "yawRate", NULL, MAVLINK_TYPE_FLOAT, 0, 16, offsetof(mavlink_motion_state_t, yawRate) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_MOTION_STATE { \
    "MOTION_STATE", \
    5, \
    {  { "x", NULL, MAVLINK_TYPE_FLOAT, 0, 0, offsetof(mavlink_motion_state_t, x) }, \
         { "y", NULL, MAVLINK_TYPE_FLOAT, 0, 4, offsetof(mavlink_motion_state_t, y) }, \
         { "yaw", NULL, MAVLINK_TYPE_FLOAT, 0, 8, offsetof(mavlink_motion_state_t, yaw) }, \
         { "xVel", NULL, MAVLINK_TYPE_FLOAT, 0, 12, offsetof(mavlink_motion_state_t, xVel) }, \
         { "yawRate", NULL, MAVLINK_TYPE_FLOAT, 0, 16, offsetof(mavlink_motion_state_t, yawRate) }, \
         } \
}
#endif

/**
 * @brief Pack a motion_state message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param x [m] 
 * @param y [m] 
 * @param yaw [rad] 
 * @param xVel [m/s] 
 * @param yawRate [rad/s] 
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_motion_state_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               float x, float y, float yaw, float xVel, float yawRate)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_MOTION_STATE_LEN];
    _mav_put_float(buf, 0, x);
    _mav_put_float(buf, 4, y);
    _mav_put_float(buf, 8, yaw);
    _mav_put_float(buf, 12, xVel);
    _mav_put_float(buf, 16, yawRate);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_MOTION_STATE_LEN);
#else
    mavlink_motion_state_t packet;
    packet.x = x;
    packet.y = y;
    packet.yaw = yaw;
    packet.xVel = xVel;
    packet.yawRate = yawRate;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_MOTION_STATE_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_MOTION_STATE;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_MOTION_STATE_MIN_LEN, MAVLINK_MSG_ID_MOTION_STATE_LEN, MAVLINK_MSG_ID_MOTION_STATE_CRC);
}

/**
 * @brief Pack a motion_state message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param x [m] 
 * @param y [m] 
 * @param yaw [rad] 
 * @param xVel [m/s] 
 * @param yawRate [rad/s] 
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_motion_state_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   float x,float y,float yaw,float xVel,float yawRate)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_MOTION_STATE_LEN];
    _mav_put_float(buf, 0, x);
    _mav_put_float(buf, 4, y);
    _mav_put_float(buf, 8, yaw);
    _mav_put_float(buf, 12, xVel);
    _mav_put_float(buf, 16, yawRate);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_MOTION_STATE_LEN);
#else
    mavlink_motion_state_t packet;
    packet.x = x;
    packet.y = y;
    packet.yaw = yaw;
    packet.xVel = xVel;
    packet.yawRate = yawRate;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_MOTION_STATE_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_MOTION_STATE;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_MOTION_STATE_MIN_LEN, MAVLINK_MSG_ID_MOTION_STATE_LEN, MAVLINK_MSG_ID_MOTION_STATE_CRC);
}

/**
 * @brief Encode a motion_state struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param motion_state C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_motion_state_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_motion_state_t* motion_state)
{
    return mavlink_msg_motion_state_pack(system_id, component_id, msg, motion_state->x, motion_state->y, motion_state->yaw, motion_state->xVel, motion_state->yawRate);
}

/**
 * @brief Encode a motion_state struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param motion_state C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_motion_state_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_motion_state_t* motion_state)
{
    return mavlink_msg_motion_state_pack_chan(system_id, component_id, chan, msg, motion_state->x, motion_state->y, motion_state->yaw, motion_state->xVel, motion_state->yawRate);
}

/**
 * @brief Send a motion_state message
 * @param chan MAVLink channel to send the message
 *
 * @param x [m] 
 * @param y [m] 
 * @param yaw [rad] 
 * @param xVel [m/s] 
 * @param yawRate [rad/s] 
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_motion_state_send(mavlink_channel_t chan, float x, float y, float yaw, float xVel, float yawRate)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_MOTION_STATE_LEN];
    _mav_put_float(buf, 0, x);
    _mav_put_float(buf, 4, y);
    _mav_put_float(buf, 8, yaw);
    _mav_put_float(buf, 12, xVel);
    _mav_put_float(buf, 16, yawRate);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_MOTION_STATE, buf, MAVLINK_MSG_ID_MOTION_STATE_MIN_LEN, MAVLINK_MSG_ID_MOTION_STATE_LEN, MAVLINK_MSG_ID_MOTION_STATE_CRC);
#else
    mavlink_motion_state_t packet;
    packet.x = x;
    packet.y = y;
    packet.yaw = yaw;
    packet.xVel = xVel;
    packet.yawRate = yawRate;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_MOTION_STATE, (const char *)&packet, MAVLINK_MSG_ID_MOTION_STATE_MIN_LEN, MAVLINK_MSG_ID_MOTION_STATE_LEN, MAVLINK_MSG_ID_MOTION_STATE_CRC);
#endif
}

/**
 * @brief Send a motion_state message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_motion_state_send_struct(mavlink_channel_t chan, const mavlink_motion_state_t* motion_state)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_motion_state_send(chan, motion_state->x, motion_state->y, motion_state->yaw, motion_state->xVel, motion_state->yawRate);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_MOTION_STATE, (const char *)motion_state, MAVLINK_MSG_ID_MOTION_STATE_MIN_LEN, MAVLINK_MSG_ID_MOTION_STATE_LEN, MAVLINK_MSG_ID_MOTION_STATE_CRC);
#endif
}

#if MAVLINK_MSG_ID_MOTION_STATE_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This variant of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_motion_state_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  float x, float y, float yaw, float xVel, float yawRate)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_float(buf, 0, x);
    _mav_put_float(buf, 4, y);
    _mav_put_float(buf, 8, yaw);
    _mav_put_float(buf, 12, xVel);
    _mav_put_float(buf, 16, yawRate);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_MOTION_STATE, buf, MAVLINK_MSG_ID_MOTION_STATE_MIN_LEN, MAVLINK_MSG_ID_MOTION_STATE_LEN, MAVLINK_MSG_ID_MOTION_STATE_CRC);
#else
    mavlink_motion_state_t *packet = (mavlink_motion_state_t *)msgbuf;
    packet->x = x;
    packet->y = y;
    packet->yaw = yaw;
    packet->xVel = xVel;
    packet->yawRate = yawRate;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_MOTION_STATE, (const char *)packet, MAVLINK_MSG_ID_MOTION_STATE_MIN_LEN, MAVLINK_MSG_ID_MOTION_STATE_LEN, MAVLINK_MSG_ID_MOTION_STATE_CRC);
#endif
}
#endif

#endif

// MESSAGE MOTION_STATE UNPACKING


/**
 * @brief Get field x from motion_state message
 *
 * @return [m] 
 */
static inline float mavlink_msg_motion_state_get_x(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  0);
}

/**
 * @brief Get field y from motion_state message
 *
 * @return [m] 
 */
static inline float mavlink_msg_motion_state_get_y(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  4);
}

/**
 * @brief Get field yaw from motion_state message
 *
 * @return [rad] 
 */
static inline float mavlink_msg_motion_state_get_yaw(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  8);
}

/**
 * @brief Get field xVel from motion_state message
 *
 * @return [m/s] 
 */
static inline float mavlink_msg_motion_state_get_xVel(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  12);
}

/**
 * @brief Get field yawRate from motion_state message
 *
 * @return [rad/s] 
 */
static inline float mavlink_msg_motion_state_get_yawRate(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  16);
}

/**
 * @brief Decode a motion_state message into a struct
 *
 * @param msg The message to decode
 * @param motion_state C-struct to decode the message contents into
 */
static inline void mavlink_msg_motion_state_decode(const mavlink_message_t* msg, mavlink_motion_state_t* motion_state)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    motion_state->x = mavlink_msg_motion_state_get_x(msg);
    motion_state->y = mavlink_msg_motion_state_get_y(msg);
    motion_state->yaw = mavlink_msg_motion_state_get_yaw(msg);
    motion_state->xVel = mavlink_msg_motion_state_get_xVel(msg);
    motion_state->yawRate = mavlink_msg_motion_state_get_yawRate(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_MOTION_STATE_LEN? msg->len : MAVLINK_MSG_ID_MOTION_STATE_LEN;
        memset(motion_state, 0, MAVLINK_MSG_ID_MOTION_STATE_LEN);
    memcpy(motion_state, _MAV_PAYLOAD(msg), len);
#endif
}
