#pragma once
// MESSAGE SET_ODOMETRY PACKING

#define MAVLINK_MSG_ID_SET_ODOMETRY 12


typedef struct __mavlink_set_odometry_t {
 float x; /*< [m] */
 float y; /*< [m] */
 float yaw; /*< [rad] */
} mavlink_set_odometry_t;

#define MAVLINK_MSG_ID_SET_ODOMETRY_LEN 12
#define MAVLINK_MSG_ID_SET_ODOMETRY_MIN_LEN 12
#define MAVLINK_MSG_ID_12_LEN 12
#define MAVLINK_MSG_ID_12_MIN_LEN 12

#define MAVLINK_MSG_ID_SET_ODOMETRY_CRC 12
#define MAVLINK_MSG_ID_12_CRC 12



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_SET_ODOMETRY { \
    12, \
    "SET_ODOMETRY", \
    3, \
    {  { "x", NULL, MAVLINK_TYPE_FLOAT, 0, 0, offsetof(mavlink_set_odometry_t, x) }, \
         { "y", NULL, MAVLINK_TYPE_FLOAT, 0, 4, offsetof(mavlink_set_odometry_t, y) }, \
         { "yaw", NULL, MAVLINK_TYPE_FLOAT, 0, 8, offsetof(mavlink_set_odometry_t, yaw) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_SET_ODOMETRY { \
    "SET_ODOMETRY", \
    3, \
    {  { "x", NULL, MAVLINK_TYPE_FLOAT, 0, 0, offsetof(mavlink_set_odometry_t, x) }, \
         { "y", NULL, MAVLINK_TYPE_FLOAT, 0, 4, offsetof(mavlink_set_odometry_t, y) }, \
         { "yaw", NULL, MAVLINK_TYPE_FLOAT, 0, 8, offsetof(mavlink_set_odometry_t, yaw) }, \
         } \
}
#endif

/**
 * @brief Pack a set_odometry message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param x [m] 
 * @param y [m] 
 * @param yaw [rad] 
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_set_odometry_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               float x, float y, float yaw)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_SET_ODOMETRY_LEN];
    _mav_put_float(buf, 0, x);
    _mav_put_float(buf, 4, y);
    _mav_put_float(buf, 8, yaw);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_SET_ODOMETRY_LEN);
#else
    mavlink_set_odometry_t packet;
    packet.x = x;
    packet.y = y;
    packet.yaw = yaw;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_SET_ODOMETRY_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_SET_ODOMETRY;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_SET_ODOMETRY_MIN_LEN, MAVLINK_MSG_ID_SET_ODOMETRY_LEN, MAVLINK_MSG_ID_SET_ODOMETRY_CRC);
}

/**
 * @brief Pack a set_odometry message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param x [m] 
 * @param y [m] 
 * @param yaw [rad] 
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_set_odometry_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   float x,float y,float yaw)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_SET_ODOMETRY_LEN];
    _mav_put_float(buf, 0, x);
    _mav_put_float(buf, 4, y);
    _mav_put_float(buf, 8, yaw);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_SET_ODOMETRY_LEN);
#else
    mavlink_set_odometry_t packet;
    packet.x = x;
    packet.y = y;
    packet.yaw = yaw;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_SET_ODOMETRY_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_SET_ODOMETRY;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_SET_ODOMETRY_MIN_LEN, MAVLINK_MSG_ID_SET_ODOMETRY_LEN, MAVLINK_MSG_ID_SET_ODOMETRY_CRC);
}

/**
 * @brief Encode a set_odometry struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param set_odometry C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_set_odometry_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_set_odometry_t* set_odometry)
{
    return mavlink_msg_set_odometry_pack(system_id, component_id, msg, set_odometry->x, set_odometry->y, set_odometry->yaw);
}

/**
 * @brief Encode a set_odometry struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param set_odometry C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_set_odometry_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_set_odometry_t* set_odometry)
{
    return mavlink_msg_set_odometry_pack_chan(system_id, component_id, chan, msg, set_odometry->x, set_odometry->y, set_odometry->yaw);
}

/**
 * @brief Send a set_odometry message
 * @param chan MAVLink channel to send the message
 *
 * @param x [m] 
 * @param y [m] 
 * @param yaw [rad] 
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_set_odometry_send(mavlink_channel_t chan, float x, float y, float yaw)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_SET_ODOMETRY_LEN];
    _mav_put_float(buf, 0, x);
    _mav_put_float(buf, 4, y);
    _mav_put_float(buf, 8, yaw);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SET_ODOMETRY, buf, MAVLINK_MSG_ID_SET_ODOMETRY_MIN_LEN, MAVLINK_MSG_ID_SET_ODOMETRY_LEN, MAVLINK_MSG_ID_SET_ODOMETRY_CRC);
#else
    mavlink_set_odometry_t packet;
    packet.x = x;
    packet.y = y;
    packet.yaw = yaw;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SET_ODOMETRY, (const char *)&packet, MAVLINK_MSG_ID_SET_ODOMETRY_MIN_LEN, MAVLINK_MSG_ID_SET_ODOMETRY_LEN, MAVLINK_MSG_ID_SET_ODOMETRY_CRC);
#endif
}

/**
 * @brief Send a set_odometry message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_set_odometry_send_struct(mavlink_channel_t chan, const mavlink_set_odometry_t* set_odometry)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_set_odometry_send(chan, set_odometry->x, set_odometry->y, set_odometry->yaw);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SET_ODOMETRY, (const char *)set_odometry, MAVLINK_MSG_ID_SET_ODOMETRY_MIN_LEN, MAVLINK_MSG_ID_SET_ODOMETRY_LEN, MAVLINK_MSG_ID_SET_ODOMETRY_CRC);
#endif
}

#if MAVLINK_MSG_ID_SET_ODOMETRY_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This variant of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_set_odometry_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  float x, float y, float yaw)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_float(buf, 0, x);
    _mav_put_float(buf, 4, y);
    _mav_put_float(buf, 8, yaw);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SET_ODOMETRY, buf, MAVLINK_MSG_ID_SET_ODOMETRY_MIN_LEN, MAVLINK_MSG_ID_SET_ODOMETRY_LEN, MAVLINK_MSG_ID_SET_ODOMETRY_CRC);
#else
    mavlink_set_odometry_t *packet = (mavlink_set_odometry_t *)msgbuf;
    packet->x = x;
    packet->y = y;
    packet->yaw = yaw;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SET_ODOMETRY, (const char *)packet, MAVLINK_MSG_ID_SET_ODOMETRY_MIN_LEN, MAVLINK_MSG_ID_SET_ODOMETRY_LEN, MAVLINK_MSG_ID_SET_ODOMETRY_CRC);
#endif
}
#endif

#endif

// MESSAGE SET_ODOMETRY UNPACKING


/**
 * @brief Get field x from set_odometry message
 *
 * @return [m] 
 */
static inline float mavlink_msg_set_odometry_get_x(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  0);
}

/**
 * @brief Get field y from set_odometry message
 *
 * @return [m] 
 */
static inline float mavlink_msg_set_odometry_get_y(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  4);
}

/**
 * @brief Get field yaw from set_odometry message
 *
 * @return [rad] 
 */
static inline float mavlink_msg_set_odometry_get_yaw(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  8);
}

/**
 * @brief Decode a set_odometry message into a struct
 *
 * @param msg The message to decode
 * @param set_odometry C-struct to decode the message contents into
 */
static inline void mavlink_msg_set_odometry_decode(const mavlink_message_t* msg, mavlink_set_odometry_t* set_odometry)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    set_odometry->x = mavlink_msg_set_odometry_get_x(msg);
    set_odometry->y = mavlink_msg_set_odometry_get_y(msg);
    set_odometry->yaw = mavlink_msg_set_odometry_get_yaw(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_SET_ODOMETRY_LEN? msg->len : MAVLINK_MSG_ID_SET_ODOMETRY_LEN;
        memset(set_odometry, 0, MAVLINK_MSG_ID_SET_ODOMETRY_LEN);
    memcpy(set_odometry, _MAV_PAYLOAD(msg), len);
#endif
}
