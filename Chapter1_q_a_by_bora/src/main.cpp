#include "vehicle.hpp"

int main(){


//let first create objects.

Car Car1(4 ,"green",5);
Car Car2(4,"blue",5);

Truck Truck1(6,"red",true,15000);
Truck Truck2(4,"yellow",false,40000);

Bus Bus1(4,"black",40,"my_tours");


Car1.car_info();
Car2.car_info();

Truck1.truck_info();
Truck2.truck_info();

Bus1.bus_info();



return 0;
};