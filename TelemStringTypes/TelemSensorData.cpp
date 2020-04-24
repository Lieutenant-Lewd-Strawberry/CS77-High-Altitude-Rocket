//
// Created by lunng on 1/22/20.
//

#include "TelemSensorData.h"

#include <utility>
#include <cassert>
#include <iostream>

TelemSensorData::TelemSensorData(std::string input_val) : TelemString(std::move(input_val)){
    update_values();
}

uint8_t TelemSensorData::get_orient(){
    return this->orient;
}
int16_t TelemSensorData::get_accel(){
    return this->accel;
}
int32_t TelemSensorData::get_pres(){
    return this->pres;
}
int16_t TelemSensorData::get_temp(){
    return this->temp;
}
int16_t TelemSensorData::get_accel_x(){
    return this->accel_x;
}
int16_t TelemSensorData::get_accel_y(){
    return this->accel_y;
}
int16_t TelemSensorData::get_accel_z(){
    return this->accel_z;
}
int16_t TelemSensorData::get_gyro_x(){
    return this->gyro_x;
}
int16_t TelemSensorData::get_gyro_y(){
    return this->gyro_y;
}
int16_t TelemSensorData::get_gyro_z(){
    return this->gyro_z;
}
int16_t TelemSensorData::get_mag_x(){
    return this->mag_x;
}
int16_t TelemSensorData::get_mag_y(){
    return this->mag_y;
}
int16_t TelemSensorData::get_mag_z(){
    return this->mag_z;
}

void TelemSensorData::update_values() {
    assert(this->get_mode() == MODE_SD);
    this->orient = get_uint8_val(6);
    this->accel = get_int16_val(7);
    this->pres = get_int32_val(9);
    this->temp = get_int16_val(13);
    this->accel_x = get_int16_val(15);
    this->accel_y = get_int16_val(17);
    this->accel_z = get_int16_val(19);
    this->gyro_x = get_int16_val(21);
    this->gyro_y = get_int16_val(23);
    this->gyro_z = get_int16_val(25);
    this->mag_x = get_int16_val(27);
    this->mag_y = get_int16_val(29);
    this->mag_z = get_int16_val(31);
}

void TelemSensorData::dump_string_data() {
    dump_string_info();
    std::cout << "\n====== Sensor Data ======" << std::endl;
    std::cout <<
              "\t" << "orient: " << (unsigned) get_orient() << std::endl <<
              "\t" << "accel: " << get_accel() << std::endl <<
              "\t" << "pres: " << get_pres() << std::endl <<
              "\t" << "temp: " << get_temp() << std::endl <<
              "\t" << "accel_x: " << get_accel_x() << std::endl <<
              "\t" << "accel_y: " << get_accel_y() << std::endl <<
              "\t" << "accel_z: " << get_accel_z() << std::endl <<
              "\t" << "gyro_x: " << get_gyro_x() << std::endl <<
              "\t" << "gyro_y: " << get_gyro_y() << std::endl <<
              "\t" << "gyro_z: " << get_gyro_z() << std::endl <<
              "\t" << "mag_x: " << get_mag_x() << std::endl <<
              "\t" << "mag_y: " << get_mag_y() << std::endl <<
              "\t" << "mag_z: " << get_mag_z() << std::endl;
}
