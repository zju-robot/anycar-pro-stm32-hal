#pragma once

#define HEARTBEAT_PERIOD 200
#define HEARTBEAT_TIMEOUT 700

/**
 * @brief 启动连接维护功能
 * 
 */
void StartConnection();

/**
 * @brief 停止连接维护功能
 * 
 */
void StopConnection();
