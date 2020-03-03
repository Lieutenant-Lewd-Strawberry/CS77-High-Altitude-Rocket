//
// Created by lunng on 1/21/20.
//

#include <string>
#include <iostream>
#include <utility>
#include <fstream>
#include <chrono>
#include "TelemParser.h"


bool TelemParser::telem_string_valid(std::string test_string) {
    std::string s("TELEM ");

    if(test_string.rfind(s, 0) != 0){
        return false;
    }

    test_string.erase(0, s.length());

    std::string lqi = test_string.substr(test_string.length()-4, 2);

    if(!((unsigned short) 0b00000001 & (unsigned short) stoul(lqi, nullptr, 16))){
        std::cerr << "The lqi " << lqi << " is not valid." << std::endl;
        return false;
    }

    ; // Placeholder in case we need to do any more work

    return true;
}

void TelemParser::Start() {
    this->running = true;
    this->file_reader = std::thread(&TelemParser::do_work, this);
}

TelemParser::TelemParser(std::string filename) : file_reader() {
    this->input_file = std::move(filename);
    this->TGPS = nullptr;
    this->TKV = nullptr;
    this->TSD = nullptr;
    this->running = false;
    initialize();
}

TelemParser::~TelemParser(){
    this->running = false;
    if(this->file_reader.joinable()) this->file_reader.join();
}

void TelemParser::do_work() {
    std::ifstream fin;
    std::string lastLastLine;


    while(this->running){
        this->iostream_mutex.lock(); // lock the mutex for file handling

        fin.open(this->input_file);

        if(fin.is_open()) {
            fin.seekg(0,std::ios_base::end);           // go to the EOF

            // Verify new data has been added
            if(fin.tellg() != this->reader_location) {

                // Go to the start of new data
                fin.seekg(this->reader_location);

                // Fill in the updated data members
                while(!fin.eof() && fin.tellg() != -1){
                    std::string data_line;
                    getline(fin, data_line);    // Read the next unread line

                    if(telem_string_valid(data_line)){
                        fill_data(data_line);
                    }
                    if(fin.tellg() != -1){
                        this->reader_location = fin.tellg();
                    }
                }

                fin.close();
            }
        }
        this->iostream_mutex.unlock();
        std::this_thread::sleep_for (std::chrono::milliseconds(100));
    }
}

void TelemParser::fill_data(const std::string& line_in) {
    int mode = TelemString::get_mode(line_in);

    // Update the stored data
    switch(mode) {
        case MODE_GPS:
            if (this->TGPS == nullptr) {
                this->TGPS = new TelemGPS(line_in);
            } else {
                this->TGPS->update_string(line_in);
                this->TGPS->update_values();
            }
            break;

        case MODE_KV:
            if (this->TKV == nullptr) {
                this->TKV = new TelemKalmanVoltage(line_in);
            } else {
                this->TKV->update_string(line_in);
                this->TKV->update_values();
            }
            break;

        case MODE_SD:
            if (this->TSD == nullptr){
                this->TSD = new TelemSensorData(line_in);
            } else {
                this->TSD->update_string(line_in);
                this->TSD->update_values();
            }
            break;

        default:
            std::cerr << line_in << " has unsupported mode: " << mode << std::endl;
    }
}

void TelemParser::initialize() {
    this->iostream_mutex.lock(); // lock the mutex within the scope of this function

    std::ifstream fin;
    std::string line_in;

    fin.open(this->input_file);
    if(fin.is_open()){
        while(!fin.eof()){
            getline(fin,line_in);               // Read the current line

            if(telem_string_valid(line_in)){
                fill_data(line_in);
            }
            if(fin.tellg() != -1){
                this->reader_location = fin.tellg();
            }
        }


        fin.close();
    }
    else{
        std::cout << "Failed to open " << this->input_file << std::endl;
    }
    this->iostream_mutex.unlock();
}

void TelemParser::dump_data() {
    this->iostream_mutex.lock();

    if(this->TGPS != nullptr){
        this->TGPS->dump_string_data();
    }
    if(this->TKV != nullptr){
        this->TKV->dump_string_data();
    }
    if(this->TSD != nullptr){
        this->TSD->dump_string_data();
    }
    this->iostream_mutex.unlock();
}
