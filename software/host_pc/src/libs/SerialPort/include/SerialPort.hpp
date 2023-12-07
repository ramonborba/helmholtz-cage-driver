/**
 * \file SerialPort.hpp
 * 
 * \brief Class SerialPort designed to handle the basic operations with serial ports
 * 
 * \author Ramon de Araujo Borba <ramonborba97@gmail.com>
 * 
 * \version 0.1
 * 
 * \date 21-11-2023
 */

#pragma once

#include <cstddef>
#include <termios.h>

class SerialPort
{
public:
    SerialPort(const char* t_device);
    SerialPort();
    ~SerialPort();

    int Open();
    int Close();

    int Write(void* t_msg, size_t t_size);
    int Read(void* t_buf, size_t t_size);

private:
    void Configure();

    int m_port;
    const char* m_device;
    termios m_tty;
};