#include "vehicle.hpp"


//Class implementation for the base class

Vehicle::Vehicle(int w, std::string c): wheels(w) , color(c){}




//base class info function implementation
void Vehicle:: info() const {

std::cout << "# of wheels: " << wheels << std::endl;
std::cout << "Color: " << color << std::endl;

};

//this part is really important. 
//you do not have access to wheels and color info so that you need to use constructor of the base class. 
Car::Car(int w , std::string c , int p): Vehicle(w,c), passenger(p) {}

//car class info function implementation
void Car::car_info() const {
    Vehicle::info();
    std::cout << "Passenger: " << passenger <<std::endl;

};

Truck::Truck (int w , std::string c , bool is_trl , int t_p):  Vehicle(w,c), is_trailer(is_trl), trailer_payload(t_p) {}


void Truck::truck_info() const {
    Vehicle::info();
    std::cout << "Trailer Situation:" << is_trailer << std::endl;

    if (is_trailer == true ) {
        std::cout << "Trailer Payload : " << trailer_payload << std::endl;
    
    }
    else {
        std::cout << "Trailer Payload cannot exist! " << std::endl;
        std::cout << "Well actually it may exist! " << std::endl;
        std::cout << "Trailer Payload : " << trailer_payload << std::endl;

    }
};

Bus::Bus(int w , std::string c  ,int p , std::string own ):Car(w,c,p) , owner(own) {}

void Bus::bus_info() const {

    Car::car_info();
    std::cout << "Owner of the car: " << owner << std::endl;
};

