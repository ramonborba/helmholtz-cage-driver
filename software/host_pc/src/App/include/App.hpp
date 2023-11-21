#pragma once

class HostPC
{
public:
    static void Start();
private:
    HostPC()  = default;

    static HostPC m_Host;
};