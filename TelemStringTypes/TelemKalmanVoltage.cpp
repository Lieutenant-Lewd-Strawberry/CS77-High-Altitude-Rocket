//
// Created by lunng on 1/26/20.
//

#include <cassert>
#include <iostream>
#include "TelemKalmanVoltage.h"


TelemKalmanVoltage::TelemKalmanVoltage(std::string input_val) : TelemString(std::move(input_val)){
    update_values();
}

uint8_t TelemKalmanVoltage::get_state(){
    return this->state;
}
int16_t TelemKalmanVoltage::get_v_batt(){
    return this->v_batt;
}
int16_t TelemKalmanVoltage::get_v_pyro(){
    return this->v_pyro;
}
int8_t  TelemKalmanVoltage::get_sense(int index){
    assert(index >= 0 && index < 6);
    return this->sense[index];
}
int32_t TelemKalmanVoltage::get_ground_pres(){
    return this->ground_pres;
}
int16_t TelemKalmanVoltage::get_ground_accel(){
    return this->ground_accel;
}
int16_t TelemKalmanVoltage::get_accel_plus_g(){
    return this->accel_plus_g;
}
int16_t TelemKalmanVoltage::get_accel_minus_g(){
    return this->accel_minus_g;
}
int16_t TelemKalmanVoltage::get_acceleration(){
    return this->acceleration;
}
int16_t TelemKalmanVoltage::get_speed(){
    return this->speed;
}
int16_t TelemKalmanVoltage::get_height(){
    return this->height;
}

void TelemKalmanVoltage::update_values() {
    assert(this->get_mode() == MODE_KV);
    this->state = get_uint8_val(6);
    this->v_batt = get_int16_val(7);
    this->v_pyro = get_int16_val(9);
    this->ground_pres = get_int32_val(17);
    this->ground_accel = get_int16_val(21);
    this->accel_plus_g = get_int16_val(23);
    this->accel_minus_g = get_int16_val(25);
    this->acceleration = get_int16_val(27);
    this->speed = get_int16_val(29);
    this->height = get_int16_val(31);
    for(int idx = 0; idx < 6; idx++){
        this->sense[idx] = get_int8_val(11+idx);
    }
}

void TelemKalmanVoltage::dump_string_data() {
    dump_string_info();
    std::cout << "\n====== Kalman + Voltage Data ======" << std::endl;
    std::cout <<
              "\t" << "state: " << (unsigned) get_state() << std::endl <<
              "\t" << "v_batt: " << get_v_batt() << std::endl <<
              "\t" << "v_pyro: " << get_v_pyro() << std::endl <<
              "\t" << "ground_pres: " << get_ground_pres() << std::endl <<
              "\t" << "ground_accel: " << get_ground_accel() << std::endl <<
              "\t" << "accel_plus_g: " << get_accel_plus_g() << std::endl <<
              "\t" << "accel_minus_g: " << get_accel_minus_g() << std::endl <<
              "\t" << "acceleration: " << get_acceleration() << std::endl <<
              "\t" << "speed: " << get_speed() << std::endl <<
              "\t" << "height: " << get_height() << std::endl;
}
