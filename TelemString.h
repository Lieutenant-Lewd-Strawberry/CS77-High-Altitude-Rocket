//
// Created by lunng on 1/21/20.
//

#ifndef TELEREADERPROJ_TELEMSTRING_H
#define TELEREADERPROJ_TELEMSTRING_H

#include <string>


class TelemString {
private:
    std::string _telem_data;
    unsigned int serial{};
    unsigned int tick{};
    unsigned int mode{};

public:
    explicit TelemString(std::string);
    TelemString() = delete;

    std::string get_bytes(int, int);
    std::string get_ordered_bytes(int, int);

    uint8_t get_uint8_val(int);
    uint16_t get_uint16_val(int);

    int8_t get_int8_val(int);
    int16_t get_int16_val(int);
    int32_t get_int32_val(int);

    unsigned int get_mode();
    static int get_mode(std::string);

    void update_string(std::string);
    virtual void update_values() = 0;

    void dump_string_info();
    virtual void dump_string_data() = 0;

    unsigned int get_tick();
    unsigned int get_serial();
};

#endif //TELEREADERPROJ_TELEMSTRING_H
