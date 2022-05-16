#pragma once
// MESSAGE SET_MOTORS_RATE PACKING

#define MAVLINK_MSG_ID_SET_MOTORS_RATE 11


typedef struct __mavlink_set_motors_rate_t {
 float rateL; /*< [rad/s] */
 float rateR; /*< [rad/s] */
} mavlink_set_motors_rate_t;

#define MAVLINK_MSG_ID_SET_MOTORS_RATE_LEN 8
#define MAVLINK_MSG_ID_SET_MOTORS_RATE_MIN_LEN 8
#define MAVLINK_MSG_ID_11_LEN 8
#define MAVLINK_MSG_ID_11_MIN_LEN 8

#define MAVLINK_MSG_ID_SET_MOTORS_RATE_CRC 51
#define MAVLINK_MSG_ID_11_CRC 51



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_SET_MOTORS_RATE { \
    11, \
    "SET_MOTORS_RATE", \
    2, \
    {  { "rateL", NULL, MAVLINK_TYPE_FLOAT, 0, 0, offsetof(mavlink_set_motors_rate_t, rateL) }, \
         { "rateR", NULL, MAVLINK_TYPE_FLOAT, 0, 4, offsetof(mavlink_set_motors_rate_t, rateR) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_SET_MOTORS_RATE { \
    "SET_MOTORS_RATE", \
    2, \
    {  { "rateL", NULL, MAVLINK_TYPE_FLOAT, 0, 0, offsetof(mavlink_set_motors_rate_t, rateL) }, \
         { "rateR", NULL, MAVLINK_TYPE_FLOAT, 0, 4, offsetof(mavlink_set_motors_rate_t, rateR) }, \
         } \
}
#endif

/**
 * @brief Pack a set_motors_rate message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param rateL [rad/s] 
 * @param rateR [rad/s] 
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_set_motors_rate_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               float rateL, float rateR)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_SET_MOTORS_RATE_LEN];
    _mav_put_float(buf, 0, rateL);
    _mav_put_float(buf, 4, rateR);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_SET_MOTORS_RATE_LEN);
#else
    mavlink_set_motors_rate_t packet;
    packet.rateL = rateL;
    packet.rateR = rateR;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_SET_MOTORS_RATE_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_SET_MOTORS_RATE;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_SET_MOTORS_RATE_MIN_LEN, MAVLINK_MSG_ID_SET_MOTORS_RATE_LEN, MAVLINK_MSG_ID_SET_MOTORS_RATE_CRC);
}

/**
 * @brief Pack a set_motors_rate message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param rateL [rad/s] 
 * @param rateR [rad/s] 
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_set_motors_rate_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   float rateL,float rateR)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_SET_MOTORS_RATE_LEN];
    _mav_put_float(buf, 0, rateL);
    _mav_put_float(buf, 4, rateR);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_SET_MOTORS_RATE_LEN);
#else
    mavlink_set_motors_rate_t packet;
    packet.rateL = rateL;
    packet.rateR = rateR;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_SET_MOTORS_RATE_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_SET_MOTORS_RATE;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_SET_MOTORS_RATE_MIN_LEN, MAVLINK_MSG_ID_SET_MOTORS_RATE_LEN, MAVLINK_MSG_ID_SET_MOTORS_RATE_CRC);
}

/**
 * @brief Encode a set_motors_rate struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param set_motors_rate C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_set_motors_rate_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_set_motors_rate_t* set_motors_rate)
{
    return mavlink_msg_set_motors_rate_pack(system_id, component_id, msg, set_motors_rate->rateL, set_motors_rate->rateR);
}

/**
 * @brief Encode a set_motors_rate struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param set_motors_rate C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_set_motors_rate_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_set_motors_rate_t* set_motors_rate)
{
    return mavlink_msg_set_motors_rate_pack_chan(system_id, component_id, chan, msg, set_motors_rate->rateL, set_motors_rate->rateR);
}

/**
 * @brief Send a set_motors_rate message
 * @param chan MAVLink channel to send the message
 *
 * @param rateL [rad/s] 
 * @param rateR [rad/s] 
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_set_motors_rate_send(mavlink_channel_t chan, float rateL, float rateR)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_SET_MOTORS_RATE_LEN];
    _mav_put_float(buf, 0, rateL);
    _mav_put_float(buf, 4, rateR);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SET_MOTORS_RATE, buf, MAVLINK_MSG_ID_SET_MOTORS_RATE_MIN_LEN, MAVLINK_MSG_ID_SET_MOTORS_RATE_LEN, MAVLINK_MSG_ID_SET_MOTORS_RATE_CRC);
#else
    mavlink_set_motors_rate_t packet;
    packet.rateL = rateL;
    packet.rateR = rateR;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SET_MOTORS_RATE, (const char *)&packet, MAVLINK_MSG_ID_SET_MOTORS_RATE_MIN_LEN, MAVLINK_MSG_ID_SET_MOTORS_RATE_LEN, MAVLINK_MSG_ID_SET_MOTORS_RATE_CRC);
#endif
}

/**
 * @brief Send a set_motors_rate message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_set_motors_rate_send_struct(mavlink_channel_t chan, const mavlink_set_motors_rate_t* set_motors_rate)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_set_motors_rate_send(chan, set_motors_rate->rateL, set_motors_rate->rateR);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SET_MOTORS_RATE, (const char *)set_motors_rate, MAVLINK_MSG_ID_SET_MOTORS_RATE_MIN_LEN, MAVLINK_MSG_ID_SET_MOTORS_RATE_LEN, MAVLINK_MSG_ID_SET_MOTORS_RATE_CRC);
#endif
}

#if MAVLINK_MSG_ID_SET_MOTORS_RATE_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This variant of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_set_motors_rate_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  float rateL, float rateR)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_float(buf, 0, rateL);
    _mav_put_float(buf, 4, rateR);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SET_MOTORS_RATE, buf, MAVLINK_MSG_ID_SET_MOTORS_RATE_MIN_LEN, MAVLINK_MSG_ID_SET_MOTORS_RATE_LEN, MAVLINK_MSG_ID_SET_MOTORS_RATE_CRC);
#else
    mavlink_set_motors_rate_t *packet = (mavlink_set_motors_rate_t *)msgbuf;
    packet->rateL = rateL;
    packet->rateR = rateR;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SET_MOTORS_RATE, (const char *)packet, MAVLINK_MSG_ID_SET_MOTORS_RATE_MIN_LEN, MAVLINK_MSG_ID_SET_MOTORS_RATE_LEN, MAVLINK_MSG_ID_SET_MOTORS_RATE_CRC);
#endif
}
#endif

#endif

// MESSAGE SET_MOTORS_RATE UNPACKING


/**
 * @brief Get field rateL from set_motors_rate message
 *
 * @return [rad/s] 
 */
static inline float mavlink_msg_set_motors_rate_get_rateL(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  0);
}

/**
 * @brief Get field rateR from set_motors_rate message
 *
 * @return [rad/s] 
 */
static inline float mavlink_msg_set_motors_rate_get_rateR(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  4);
}

/**
 * @brief Decode a set_motors_rate message into a struct
 *
 * @param msg The message to decode
 * @param set_motors_rate C-struct to decode the message contents into
 */
static inline void mavlink_msg_set_motors_rate_decode(const mavlink_message_t* msg, mavlink_set_motors_rate_t* set_motors_rate)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    set_motors_rate->rateL = mavlink_msg_set_motors_rate_get_rateL(msg);
    set_motors_rate->rateR = mavlink_msg_set_motors_rate_get_rateR(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_SET_MOTORS_RATE_LEN? msg->len : MAVLINK_MSG_ID_SET_MOTORS_RATE_LEN;
        memset(set_motors_rate, 0, MAVLINK_MSG_ID_SET_MOTORS_RATE_LEN);
    memcpy(set_motors_rate, _MAV_PAYLOAD(msg), len);
#endif
}
