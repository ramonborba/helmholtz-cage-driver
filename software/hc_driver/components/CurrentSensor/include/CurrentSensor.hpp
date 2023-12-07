/**
 * \file CurrentSensor.hpp
 * 
 * \brief CurrentSensor class header
 * 
 * \author Ramon de Araujo Borba <ramonborba97@gmail.com>
 * 
 * \version 0.1
 * 
 * \date 06-12-2023
 */

#ifndef _CURRENT_SENSOR_HPP_
#define _CURRENT_SENSOR_HPP_

#include <cstdint>

#include "i2c_cxx.hpp"

class CurrentSensor
{
public:
    CurrentSensor(idf::I2CNumber t_num, idf::SCL_GPIO t_scl,idf::SDA_GPIO t_sda,  idf::Frequency t_freq);
    ~CurrentSensor();

    uint32_t Read();
private:
    idf::I2CMaster m_i2c;
};

#endif /* _CURRENT_SENSOR_HPP_ */
