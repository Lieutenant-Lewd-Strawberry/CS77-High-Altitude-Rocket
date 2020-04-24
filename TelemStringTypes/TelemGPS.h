//
// Created by lunng on 1/26/20.
//

#ifndef TELEREADERPROJ_TELEMGPS_H
#define TELEREADERPROJ_TELEMGPS_H

#define MODE_GPS 0x05

#include "../TelemString.h"

class TelemGPS : public TelemString{
private:
    uint8_t flags{};
    int16_t altitude{};
    int32_t latitude{};
    int32_t longitude{};
    uint8_t year{};
    uint8_t month{};
    uint8_t day{};
    uint8_t hour{};
    uint8_t minute{};
    uint8_t second{};
    uint8_t pdop{};
    uint8_t hdop{};
    uint8_t vdop{};
    uint8_t mode{};
    uint16_t ground_speed{};
    int16_t climb_rate{};
    uint8_t course{};

public:
    explicit TelemGPS(std::string);
    TelemGPS() = delete;

    void update_values() override;
    void dump_string_data() override;

    uint8_t get_flags();
    int16_t get_altitude();
    int32_t get_latitude();
    int32_t get_longitude();
    uint8_t get_year();
    uint8_t get_month();
    uint8_t get_day();
    uint8_t get_hour();
    uint8_t get_minute();
    uint8_t get_second();
    uint8_t get_pdop();
    uint8_t get_hdop();
    uint8_t get_vdop();
    uint8_t get_gps_mode();
    uint16_t get_ground_speed();
    int16_t get_climb_rate();
    uint8_t get_course();

};


#endif //TELEREADERPROJ_TELEMGPS_H
