/**
 * \file HostPC.hpp
 * 
 * \brief HostPC class header file
 * 
 * This class represents the host pc and handles communication with it
 * 
 * \author Ramon de Araujo Borba <ramonborba97@gmail.com>
 * 
 * \version 0.1
 * 
 * \date 18-11-2023
 */

#ifndef _HOST_PC_
#define _HOST_PC_

#include "Host.hpp"
#include "uart_cxx.hpp"

class HostPC : public Host
{
public:
    ~HostPC() = default;

    static HostPC& GetInstance();

    void SendLog() override;

    const TaskParameters_t GetEventHandlerTaskParams() override;
    TaskHandle_t* GetEventHandlerTaskHandle() override;

private:
    HostPC();

    static void xUartEventHandlerTask(void* pvParameters);
    
    static TaskHandle_t m_TaskHandle;
    static const TaskParameters_t m_TaskParams;

    uart_port_t m_UartPortNum = UART_NUM_2;
    int m_RxPin = 16;
    int m_TxPin = 17;
    uart_config_t m_UartConfig {
        .baud_rate  = 115200,
        .data_bits  = UART_DATA_8_BITS,
        .parity     = UART_PARITY_DISABLE,
        .stop_bits  = UART_STOP_BITS_1,
        .flow_ctrl  = UART_HW_FLOWCTRL_DISABLE
    };
    QueueHandle_t m_UartEventQueue;
    idf::UARTPort m_Uart;

};

#endif /* _HOST_PC_ */