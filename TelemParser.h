//
// Created by lunng on 1/21/20.
//

#ifndef TELEREADERPROJ_TELEMPARSER_H
#define TELEREADERPROJ_TELEMPARSER_H

#include <string>
#include <thread>
#include <mutex>

#include "TelemStringTypes/TelemGPS.h"
#include "TelemStringTypes/TelemSensorData.h"
#include "TelemStringTypes/TelemKalmanVoltage.h"


class TelemParser {
private:
    // Variables for reading the data file
    std::string input_file;
    std::streampos reader_location;

    // Data storage variables
    TelemGPS *TGPS;
    TelemSensorData *TSD;
    TelemKalmanVoltage *TKV;

    // Variables for threading
    std::thread file_reader;
    std::mutex iostream_mutex;
    bool running;

public:
    explicit TelemParser(std::string);
    ~TelemParser();

    // Get rid of default class methods that we can't have (because of the threading aspect)
    TelemParser() = delete;
    TelemParser(const TelemParser&) = delete;
    TelemParser& operator=(const TelemParser&) = delete;

    // File handlers
    void fill_data(const std::string&);
    void initialize();
    void do_work();

    // Thread init
    void Start();

    // Utility
    void dump_data();
    static bool telem_string_valid(std::string);

};


#endif //TELEREADERPROJ_TELEMPARSER_H
