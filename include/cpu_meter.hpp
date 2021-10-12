#pragma once

class cpu_meter_t {
public:
    cpu_meter_t();
    float read();
private:
    unsigned long long lastTotalUser;
    unsigned long long lastTotalUserLow;
    unsigned long long lastTotalSys;
    unsigned long long lastTotalIdle;
};