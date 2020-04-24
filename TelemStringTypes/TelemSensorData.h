//
// Created by lunng on 1/22/20.
//

#ifndef TELEREADERPROJ_TELEMSENSORDATA_H
#define TELEREADERPROJ_TELEMSENSORDATA_H

#include <string>
#include "../TelemString.h"

#define MODE_SD 0x08

class TelemSensorData : public TelemString {
private:
    uint8_t orient{};
    int16_t accel{};
    int32_t pres{};
    int16_t temp{};
    int16_t accel_x{};
    int16_t accel_y{};
    int16_t accel_z{};
    int16_t gyro_x{};
    int16_t gyro_y{};
    int16_t gyro_z{};
    int16_t mag_x{};
    int16_t mag_y{};
    int16_t mag_z{};

public:
    explicit TelemSensorData(std::string);
    void update_values() override;
    void dump_string_data() override;

    uint8_t get_orient();
    int16_t get_accel();
    int32_t get_pres();
    int16_t get_temp();
    int16_t get_accel_x();
    int16_t get_accel_y();
    int16_t get_accel_z();
    int16_t get_gyro_x();
    int16_t get_gyro_y();
    int16_t get_gyro_z();
    int16_t get_mag_x();
    int16_t get_mag_y();
    int16_t get_mag_z();

};


#endif //TELEREADERPROJ_TELEMSENSORDATA_H
