//
// Created by lunng on 1/26/20.
//

#ifndef TELEREADERPROJ_TELEMKALMANVOLTAGE_H
#define TELEREADERPROJ_TELEMKALMANVOLTAGE_H

#define MODE_KV 0x09

#include <stdint.h>
#include "../TelemString.h"

class TelemKalmanVoltage : public TelemString {
private:
    uint8_t state{};
    int16_t v_batt{};
    int16_t v_pyro{};
    int32_t ground_pres{};
    int16_t ground_accel{};
    int16_t accel_plus_g{};
    int16_t accel_minus_g{};
    int16_t acceleration{};
    int16_t speed{};
    int16_t height{};
    int8_t  sense[6]{};

public:
    explicit TelemKalmanVoltage(std::string);
    void update_values() override;
    void dump_string_data() override;

    uint8_t get_state();
    int16_t get_v_batt();
    int16_t get_v_pyro();
    int8_t  get_sense(int);
    int32_t get_ground_pres();
    int16_t get_ground_accel();
    int16_t get_accel_plus_g();
    int16_t get_accel_minus_g();
    int16_t get_acceleration();
    int16_t get_speed();
    int16_t get_height();
};


#endif //TELEREADERPROJ_TELEMKALMANVOLTAGE_H
