#include "time.hpp"

//Class Implementation for time

//Constructor

Time::Time(int h, int m){
        if ( h >= 0 && h<=23 && m>=0 && m<=59){
            minute = m;
            hour = h;

        }
        else {
            std::cout << "Wrong time ?" << std::endl;
            std::cout << "Initialized to default values" << std::endl;

            minute = 0;
            hour = 0;
        }
};

void Time::increment_minute(){
    if (minute + 1 == 60){
        minute = 0;
        hour = hour + 1;


    }
    else if (minute + 1 < 60) {
        minute = minute + 1;

    }



};

void Time::decrement_minute() {
    if (minute - 1 < 0 ){
        hour = hour -1 ;
        minute = 59;

    }
    else 
    minute = minute - 1;


};

void Time::print_time() const {

std::cout << "Hour: " << hour << " Minute: " << minute << std::endl;

};

void Time::set_time(int h, int m) {
        if ( h >= 0 && h<=23 && m>=0 && m<=59){
            minute = m;
            hour = h;

        }
        else {
            std::cout << "Wrong time ?" << std::endl;
            std::cout << "Initialized to default values" << std::endl;

            minute = 0;
            hour = 0;
        }

};


//
Timezone::Timezone(int h, int m, int tz){
        if ( h >= 0 && h<=23 && m>=0 && m<=59 && tz >= -11 && tz <=12 ){
            minute = m;
            hour = h;
            timezone = tz;

        }
        else {
            std::cout << "Wrong time ?" << std::endl;
            std::cout << "Initialized to default values" << std::endl;

            minute = 0;
            hour = 0;
            timezone = 0;
        }

};

 void Timezone::see_timezone() const {
    std::cout << "Timeline is " << timezone << std::endl;


};

void Timezone::print_time() const {
    std::cout << timezone << " " << hour << ":" << minute << std::endl;

};

void Timezone::change_timezone(int new_tz) {
    if (new_tz < timezone){
        hour = hour - (abs(new_tz) + abs(timezone));
        timezone = new_tz;

    }
    else if (new_tz > timezone) {
        hour = hour + (abs(new_tz) - timezone);
        timezone = new_tz;
    

    }

    if (hour > 23)
    {hour = hour - 24;
    
    }

};