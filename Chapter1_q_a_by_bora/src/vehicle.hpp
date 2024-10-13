#include <iostream>

// base class vehicle is defined

class Vehicle {
    protected:
    int wheels; // all inherited class will have this
    std::string color; // again all inherited class will have this
    
    public:
    Vehicle(int w = 0, std::string c = "white"); // do not ever forget about constructor amk!
    void info(void) const; //used for printing info about this base class 

};

class Car:public Vehicle {
    protected:
    int passenger; // used for determining # of passenger in the car 

    public:
    Car(int w = 0, std::string c = "white", int p = 1);
    void car_info(void) const; // overwriting info function of base class for car_info

};
class Truck:public Vehicle {
    private:
    bool is_trailer; // used for determining whether truck has a trailer or not
    int trailer_payload; // if truck has a trailer what is it's payload?

    public:
    Truck(int w = 0, std::string c = "whilte",bool is_trailer = true, int t_p = 15000);
    void truck_info(void) const;
};

class Bus:public Car {
    private:
    std::string owner;

    public:
    Bus(int w = 0, std::string c = "white" , int p = 1, std::string own = "bora");
    void bus_info(void) const;

};


