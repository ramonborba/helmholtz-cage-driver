/**
 * Author: Ramon de Araujo Borba < ramonborba97@gmail.com >
 * Institution: UFSC
 * Date: 15/03/2022
 * File: UART_cxx.hpp
 * 
 * Implementations for the UART C++ API are based
 * in the GPIO C++ API provided in ESP-IDF examples.
 * 
 */

#ifndef UART_CXX_H_
#define UART_CXX_H_

#if __cpp_exceptions    // Check if C++ is enabled for the microcontroller module


#include "driver/uart.h"
#include "esp_exception.hpp"
#include "system_cxx.hpp"

#define BUFFER_SIZE (1024)

namespace idf {



/**
 * @brief Exception thrown for errors in the UART C++ API.
 */
struct UARTException : public ESPException {
    /**
     * @param error The IDF error representing the error class of the error to throw.
     */
    UARTException(esp_err_t error);
};

class UARTPort
{
private:
    uart_port_t port_num_;
    uart_config_t config_;
public:

    /**
     * @brief Construct a new UARTPort object
     * 
     * @param portnum Number of the UART port
     * @param rx_buffer_size Size of RX buffer
     * @param tx_buffer_size Size of TX buffer
     * @param uart_queue Handle to UART event queue
     * @param queue_size Size of UART event queue
     */
    UARTPort(uart_port_t portnum,
                int rx_buffer_size,
                int tx_buffer_size,
                QueueHandle_t* uart_queue,
                int queue_size);
    ~UARTPort();

    /**
     * @brief Set the config struct
     * 
     * @param cfg Reference to struct containig new configuration parameters
     */
    void set_config(const uart_config_t& cfg);

    /**
     * @brief Get the config struct
     * 
     * @param cfg Reference to struct to receive current config parameters
     */
    void get_config(uart_config_t& cfg);

    
    /**
     * @brief Send  anumber of bytes trough uart
     * 
     * @param buffer Buffer containing the data to be sent
     * @param size Amount of bytes to send
     */
    void write(const void* buffer, size_t size);

    /**
     * @brief Read a number of bytes from usrt
     * 
     * @param buffer Buffer to receive the data
     * @param size Amount of bytes to read
     * @param timeout Time in ms to wait
     */
    void read(void* buffer, size_t size, uint32_t timeout);

    /**
     * @brief Set the pins used by the uart, if not using the default ones
     * 
     * @param tx_pin TX pin
     * @param rx_pin RX pin
     * @param rts_pin RTS pin
     * @param cts_pin CTS pin
     */
    void set_pins(int tx_pin, int rx_pin, int rts_pin, int cts_pin);
    
    /**
     * @brief Enable pattern detection event
     * 
     * @param pattern_chr Char to detect
     * @param chr_num Number of chars in the pattern
     * @param chr_tout Timeout between chars in the pattern
     * @param post_idle Post idle timeout
     * @param pre_idle Pre idle timeout
     */
    void enable_pattern(char pattern_chr, uint8_t chr_num, int chr_tout, int post_idle, int pre_idle);
    
    /**
     * @brief Disables pattern detection
     * 
     */
    void disable_pattern();


};

} // namespace idf

#endif /* __cpp_exceptions */
#endif /* UART_CXX_H */