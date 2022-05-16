/** @file
 *  @brief MAVLink comm protocol generated from messages.xml
 *  @see http://mavlink.org
 */
#pragma once
#ifndef MAVLINK_MESSAGES_H
#define MAVLINK_MESSAGES_H

#ifndef MAVLINK_H
    #error Wrong include order: MAVLINK_MESSAGES.H MUST NOT BE DIRECTLY USED. Include mavlink.h from the same directory instead or set ALL AND EVERY defines from MAVLINK.H manually accordingly, including the #define MAVLINK_H call.
#endif

#undef MAVLINK_THIS_XML_HASH
#define MAVLINK_THIS_XML_HASH 893402548662970140

#ifdef __cplusplus
extern "C" {
#endif

// MESSAGE LENGTHS AND CRCS

#ifndef MAVLINK_MESSAGE_LENGTHS
#define MAVLINK_MESSAGE_LENGTHS {}
#endif

#ifndef MAVLINK_MESSAGE_CRCS
#define MAVLINK_MESSAGE_CRCS {{0, 34, 8, 8, 0, 0, 0}, {10, 70, 8, 8, 0, 0, 0}, {11, 51, 8, 8, 0, 0, 0}, {12, 12, 12, 12, 0, 0, 0}, {20, 160, 20, 20, 0, 0, 0}}
#endif

#include "../protocol.h"

#define MAVLINK_ENABLED_MESSAGES

// ENUM DEFINITIONS



// MAVLINK VERSION

#ifndef MAVLINK_VERSION
#define MAVLINK_VERSION 3
#endif

#if (MAVLINK_VERSION == 0)
#undef MAVLINK_VERSION
#define MAVLINK_VERSION 3
#endif

// MESSAGE DEFINITIONS
#include "./mavlink_msg_heartbeat.h"
#include "./mavlink_msg_set_speed.h"
#include "./mavlink_msg_set_motors_rate.h"
#include "./mavlink_msg_set_odometry.h"
#include "./mavlink_msg_motion_state.h"

// base include


#undef MAVLINK_THIS_XML_HASH
#define MAVLINK_THIS_XML_HASH 893402548662970140

#if MAVLINK_THIS_XML_HASH == MAVLINK_PRIMARY_XML_HASH
# define MAVLINK_MESSAGE_INFO {MAVLINK_MESSAGE_INFO_HEARTBEAT, MAVLINK_MESSAGE_INFO_SET_SPEED, MAVLINK_MESSAGE_INFO_SET_MOTORS_RATE, MAVLINK_MESSAGE_INFO_SET_ODOMETRY, MAVLINK_MESSAGE_INFO_MOTION_STATE}
# define MAVLINK_MESSAGE_NAMES {{ "HEARTBEAT", 0 }, { "MOTION_STATE", 20 }, { "SET_MOTORS_RATE", 11 }, { "SET_ODOMETRY", 12 }, { "SET_SPEED", 10 }}
# if MAVLINK_COMMAND_24BIT
#  include "../mavlink_get_info.h"
# endif
#endif

#ifdef __cplusplus
}
#endif // __cplusplus
#endif // MAVLINK_MESSAGES_H
