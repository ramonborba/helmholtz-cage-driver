/**
 * \file SerialPort.cpp
 * 
 * \brief Class SerialPort implementation
 * 
 * \author Ramon de Araujo Borba <ramonborba97@gmail.com>
 * 
 * \version 0.1
 * 
 * \date 21-11-2023
 */

#include <iostream>

#include <unistd.h>
#include <errno.h>
#include <fcntl.h>
#include <termios.h>

#include "SerialPort.hpp"

SerialPort::SerialPort() : m_port {-1}, m_device{nullptr} {
}

SerialPort::SerialPort(const char* t_device) : m_port {-1} , m_device { t_device } {

    try {
        Open();
    }
    catch(const char * e) {
        std::cerr << e << '\n';
    }
    

    Configure();


    std::cout << "Built SerialPort\n";
}

SerialPort::~SerialPort() {
    Close();
}

int SerialPort::Open() {
    std::cout << "Opening " << m_device << "\n";
    m_port = open(m_device, O_RDWR|O_NOCTTY|O_NDELAY);
    if (m_port <= 0 ) {
        throw "Failed to open serial port!";
    }
    fcntl(m_port, F_SETFL, 0);
    return m_port;
}

void SerialPort::Configure() {
    // Get current settings
    tcgetattr(m_port, &m_tty);

    // --- Control Modes ---
    // Disable parity
    m_tty.c_cflag &= ~PARENB;

    // One stop bit
    m_tty.c_cflag &= ~CSTOPB;

    // 8 data bits
    m_tty.c_cflag &= ~CSIZE;
    m_tty.c_cflag |= CS8;

    // Disable hardware flow ctrl
    m_tty.c_cflag &= ~CRTSCTS;

    // Turn on read
    m_tty.c_cflag |= CREAD;

    // Ignore ctrl lines (CLOCAL=1)
    m_tty.c_cflag |= CLOCAL;

    // --- Local Modes ---
    // Disable canonical mode
    m_tty.c_lflag &= ~ICANON;

    // Disable echo
    m_tty.c_lflag &= ~ECHO; // Disable echo
    m_tty.c_lflag &= ~ECHOE; // Disable erasure
    m_tty.c_lflag &= ~ECHONL; // Disable new-line echo

    // Disable interpretation of INTR, QUIT and SUSP
    m_tty.c_lflag &= ~(ISIG | IEXTEN);

    // --- Input Modes ---
    // Turn off software flow ctrl
    m_tty.c_iflag &= ~(IXON);

    // Disable any special handling of received bytes
    m_tty.c_iflag &= ~(IGNBRK|BRKINT|PARMRK|ISTRIP|INLCR|IGNCR|ICRNL);

    // --- Output Modes ---
    // Prevent special interpretation of output bytes (e.g. newline chars)
    m_tty.c_oflag &= ~OPOST;

    // Prevent conversion of newline to carriage return/line feed
    m_tty.c_oflag &= ~ONLCR;

    // VMIM (number of bytes to receive (blobking)) VTIME (timeout)
    m_tty.c_cc[VTIME] = 0;    // Wait for up to 1s (10 deciseconds), returning as soon as any data is received.
    m_tty.c_cc[VMIN] = 0;

    // --- Baud Rate ---
    cfsetispeed(&m_tty, B115200);
    cfsetospeed(&m_tty, B115200);

    // --- Save Settings ---
    tcsetattr(m_port, TCSANOW, &m_tty);
}

int SerialPort::Close() {
    std::cout << "Closing " << m_device << "\n";
    return close(m_port);
}

int SerialPort::Write(void* t_msg, size_t t_size) {
    if (m_port <= 0) {
        std::cerr << "Problem with serial port!";
    }
    return write(m_port, t_msg, t_size);
}

int SerialPort::Read(void* t_buf, size_t t_size) {
    if (m_port <= 0) {
        std::cerr << "Problem with serial port!";
    }
    int ret = read(m_port, t_buf, t_size);
    return ret;
}
