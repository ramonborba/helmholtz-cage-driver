/**
 * \file CoilDriver.hpp
 * 
 * \brief CoilDriver class header
 * 
 * \author Ramon de Araujo Borba <ramonborba97@gmail.com>
 * 
 * \version 0.1
 * 
 * \date 06-12-2023
 */

#ifndef _COIL_DRIVER_HPP_
#define _COIL_DRIVER_HPP_

#include "CurrentSensor.hpp"
#include "CurrentSource.hpp"

class CoilDriver
{
public:
    CoilDriver(idf::GPIONum t_SourcePin, idf::I2CAddress t_addr);
    ~CoilDriver();

    void SetSource(uint32_t t_Value);
    uint32_t ReadCurrent();

private:
    CurrentSource m_Source;
    CurrentSensor m_Sensor;
};

#endif /* _COIL_DRIVER_HPP_ */
