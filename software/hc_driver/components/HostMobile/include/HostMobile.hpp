/**
 * \file HostMobile.hpp
 * 
 * \brief HostMobile class header file
 * 
 * This class represents the host smartphone and handles communication with it
 * 
 * \author Ramon de Araujo Borba <ramonborba97@gmail.com>
 * 
 * \version 0.1
 * 
 * \date 18-11-2023
 */

#ifndef _HOST_MOBILE_
#define _HOST_MOBILE_

#include "Host.hpp"

class HostMobile : public Host
{
public:
    ~HostMobile() = default;

    static HostMobile& GetInstance();

    void SendLog() override;

    const TaskParameters_t GetEventHandlerTaskParams() override;
    TaskHandle_t* GetEventHandlerTaskHandle() override;

private:
    HostMobile();

    static void xWiFiEventHandlerTask(void* pvParameters);
    
    static TaskHandle_t m_TaskHandle;
    static const TaskParameters_t m_TaskParams;

};
#endif /* _HOST_MOBILE_ */