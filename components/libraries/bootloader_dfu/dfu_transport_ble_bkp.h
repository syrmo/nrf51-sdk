#ifndef DFU_TRANSPORT_BLE_H_
#define DFU_TRANSPORT_BLE_H_

#define DFU_REV_MAJOR                        0x00                                                    /** DFU Major revision number to be exposed. */
#define DFU_REV_MINOR                        0x06                                                    /** DFU Minor revision number to be exposed. */
#define DFU_REVISION                         ((DFU_REV_MAJOR << 8) | DFU_REV_MINOR)                  /** DFU Revision number to be exposed. Combined of major and minor versions. */
#define ADVERTISING_LED_PIN_NO               BSP_LED_0                                               /**< Is on when device is advertising. */
#define CONNECTED_LED_PIN_NO                 BSP_LED_1                                               /**< Is on when device has connected. */
#define DFU_SERVICE_HANDLE                   0x000C                                                  /**< Handle of DFU service when DFU service is first service initialized. */
#define BLE_HANDLE_MAX                       0xFFFF                                                  /**< Max handle value is BLE. */

#define DEVICE_NAME                          "DfuTarg"                                               /**< Name of device. Will be included in the advertising data. */
#define MANUFACTURER_NAME                    "NordicSemiconductor"                                   /**< Manufacturer. Will be passed to Device Information Service. */

#define MIN_CONN_INTERVAL                    (uint16_t)(MSEC_TO_UNITS(15, UNIT_1_25_MS))             /**< Minimum acceptable connection interval (11.25 milliseconds). */
#define MAX_CONN_INTERVAL                    (uint16_t)(MSEC_TO_UNITS(30, UNIT_1_25_MS))             /**< Maximum acceptable connection interval (15 milliseconds). */
#define SLAVE_LATENCY                        0                                                       /**< Slave latency. */
#define CONN_SUP_TIMEOUT                     (4 * 100)                                               /**< Connection supervisory timeout (4 seconds). */

#define APP_TIMER_PRESCALER                  0                                                       /**< Value of the RTC1 PRESCALER register. */

#define FIRST_CONN_PARAMS_UPDATE_DELAY       APP_TIMER_TICKS(100, APP_TIMER_PRESCALER)               /**< Time from the Connected event to first time sd_ble_gap_conn_param_update is called (100 milliseconds). */
#define NEXT_CONN_PARAMS_UPDATE_DELAY        APP_TIMER_TICKS(500, APP_TIMER_PRESCALER)               /**< Time between each call to sd_ble_gap_conn_param_update after the first call (500 milliseconds). */
#define MAX_CONN_PARAMS_UPDATE_COUNT         3                                                       /**< Number of attempts before giving up the connection parameter negotiation. */

#define APP_ADV_INTERVAL                     MSEC_TO_UNITS(25, UNIT_0_625_MS)                        /**< The advertising interval (25 ms.). */
#define APP_ADV_TIMEOUT_IN_SECONDS           BLE_GAP_ADV_TIMEOUT_GENERAL_UNLIMITED                   /**< The advertising timeout in units of seconds. This is set to @ref BLE_GAP_ADV_TIMEOUT_GENERAL_UNLIMITED so that the advertisement is done as long as there there is a call to @ref dfu_transport_close function.*/
#define APP_DIRECTED_ADV_TIMEOUT             50                                                       /**< number of direct advertisement (each lasting 1.28seconds). */
#define PEER_ADDRESS_TYPE_INVALID            0xFF                                                    /**< Value indicating that no valid peer address exists. This will be the case when a private resolvable address is used in which case there is no address available but instead an IRK is present. */
#define PEER_ADDRESS_TYPE_INVALID            0xFF                                                    /**< Value indicating that no valid peer address exists. This will be the case when a private resolvable address is used in which case there is no address available but instead an IRK is present. */

#define SEC_PARAM_TIMEOUT                    30                                                      /**< Timeout for Pairing Request or Security Request (in seconds). */
#define SEC_PARAM_BOND                       0                                                       /**< Perform bonding. */
#define SEC_PARAM_MITM                       0                                                       /**< Man In The Middle protection not required. */
#define SEC_PARAM_IO_CAPABILITIES            BLE_GAP_IO_CAPS_NONE                                    /**< No I/O capabilities. */
#define SEC_PARAM_OOB                        0                                                       /**< Out Of Band data not available. */
#define SEC_PARAM_MIN_KEY_SIZE               7                                                       /**< Minimum encryption key size. */
#define SEC_PARAM_MAX_KEY_SIZE               16                                                      /**< Maximum encryption key size. */

#define MAX_SIZE_OF_BLE_STACK_EVT            (sizeof(ble_evt_t) + BLE_L2CAP_MTU_DEF)                 /**< Maximum size (in bytes) of the event received from S110 SoftDevice.*/
#define NUM_WORDS_RESERVED_FOR_BLE_EVENTS    CEIL_DIV(MAX_SIZE_OF_BLE_STACK_EVT, sizeof(uint32_t))   /**< Size of the memory (in words) reserved for receiving S110 SoftDevice events. */

#define IS_CONNECTED()                       (m_conn_handle != BLE_CONN_HANDLE_INVALID)              /**< Macro to determine if the device is in connected state. */

#define APP_FEATURE_NOT_SUPPORTED            BLE_GATT_STATUS_ATTERR_APP_BEGIN + 2                    /**< Reply when unsupported features are requested. */
#define SD_IMAGE_SIZE_OFFSET                 0                                                       /**< Offset in start packet for the size information for SoftDevice. */
#define BL_IMAGE_SIZE_OFFSET                 4                                                       /**< Offset in start packet for the size information for bootloader. */
#define APP_IMAGE_SIZE_OFFSET                8                                                       /**< Offset in start packet for the size information for application. */

#endif //DFU_TRANSPORT_BLE_H_
