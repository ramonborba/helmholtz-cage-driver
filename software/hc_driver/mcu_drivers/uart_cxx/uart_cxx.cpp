/**
 * Author: Ramon de Araujo Borba < ramonborba97@gmail.com >
 * Institution: UFSC
 * Date: 15/03/2022
 * File: UART_cxx.cpp
 * 
 * Implementations for the UART C++ API are based
 * in the GPIO C++ API provided in ESP-IDF examples.
 * 
 */


#include "uart_cxx.hpp"
#include "esp_log.h"

static const char* UART_TAG = "UART_CPP";

namespace idf
{
UARTException::UARTException(esp_err_t error) : ESPException(error) { }


UARTPort::UARTPort(uart_port_t portnum,
                    int rx_buffer_size,
                    int tx_buffer_size,
                    QueueHandle_t* uart_queue,
                    int queue_size) : port_num_{portnum}, config_{}
{
    ESP_LOGD(UART_TAG, "Constructing UART%d", port_num_);
    // Check for valid port number   
    if (!(portnum > (UART_NUM_MAX-1)))
    {
        ESP_LOGD(UART_TAG, "Port num %d is valid", port_num_);
        // Check if driver is already installed
        if (!uart_is_driver_installed(port_num_))
        {
            // Install UART driver
            uart_driver_install(portnum, BUFFER_SIZE * 2, BUFFER_SIZE * 2, queue_size, uart_queue, 0);
            ESP_LOGD(UART_TAG, "Installed UART%d driver", port_num_);
            uart_set_pin(port_num_, 17, 16, UART_PIN_NO_CHANGE, UART_PIN_NO_CHANGE);
            
            // Store default configuration in config_
            uart_get_baudrate(port_num_, (uint32_t*)&config_.baud_rate );
            uart_get_word_length(port_num_, &config_.data_bits);
            uart_get_parity(port_num_, &config_.parity);
            uart_get_stop_bits(port_num_, &config_.stop_bits);
            uart_get_hw_flow_ctrl(port_num_, &config_.flow_ctrl);
        }

    }
}

UARTPort::~UARTPort()
{
    // Delete UART driver to free allocated resources
    uart_driver_delete(port_num_);
    ESP_LOGD(UART_TAG, "Deleted UART%d driver", port_num_);
}


void UARTPort::set_config(const uart_config_t& cfg)
{
    // Call uart parameter configuration function
    config_ = cfg;
    uart_param_config(port_num_, &config_);
    ESP_LOGD(UART_TAG, "Configured UART%d parameters", port_num_);
}


void UARTPort::get_config(uart_config_t& cfg)
{
    cfg = config_;
    ESP_LOGD(UART_TAG, "Retrieving UART%d parameters", port_num_);
}

void UARTPort::write(const void* buffer, size_t size){
    if (uart_write_bytes(port_num_, buffer, size))
    {
        uart_wait_tx_done(port_num_, 200/portTICK_PERIOD_MS);
        ESP_LOGD(UART_TAG, "Sent %d bytes through UART%d", size, port_num_);
    }
}

void UARTPort::read(void* buffer, size_t size, uint32_t timeout){
    int rb = uart_read_bytes(port_num_, buffer, size, timeout/portTICK_PERIOD_MS);
    ESP_LOGD(UART_TAG, "Read %d bytes from UART%d", rb, port_num_);
    
}

void UARTPort::set_pins(int tx_pin, int rx_pin, int rts_pin, int cts_pin){
    uart_set_pin(port_num_, rx_pin, tx_pin, rts_pin, cts_pin);    
}


void UARTPort::enable_pattern(char pattern_chr, uint8_t chr_num, int chr_tout, int post_idle, int pre_idle){
    uart_enable_pattern_det_baud_intr(port_num_, pattern_chr, chr_num, chr_tout, post_idle, pre_idle);
}

void UARTPort::disable_pattern(){
    uart_disable_pattern_det_intr(port_num_);
}




} // namespace idf
