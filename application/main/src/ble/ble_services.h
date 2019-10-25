#pragma once

#include "ble.h"
#include "main.h"
#include "ble_advertising.h"
#include <stdbool.h>
#include <stdint.h>

extern uint16_t m_conn_handle;


typedef void (*evt_handler) (enum user_ble_event arg);

/**@brief Init basic ble services
 */
void ble_services_init(evt_handler handler);


/**@brief 切换连接设备.
 *
 * @param[in] id  要切换的设备的ID号
 */
void switch_device_select(uint8_t id);

/**@brief 重新绑定当前设备.
 *
 * @param[in] id  要绑定设备的ID号
 */
void switch_device_reset();

/**@brief 清空所有绑定数据.
 */
void delete_bonds(void);

/**@brief 开启蓝牙广播.
 * 
 * @param[in] erase_bonds  是否清空所有绑定数据
 */
void advertising_start(bool erase_bonds);

/**@brief 重新开启蓝牙广播.
 * 
 * @param[in] mode  广播模式
 * @param[in] reset  是否重新绑定
 */
void advertising_restart(ble_adv_mode_t mode, bool reset);

/**@brief Init Bluetooth stack
 */
void ble_stack_init(void);

/**@brief Send passkey.
 */
void ble_passkey_send(uint8_t const * p_key);

void advertising_slow(void);
