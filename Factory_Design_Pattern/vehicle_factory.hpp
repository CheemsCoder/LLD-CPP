#ifndef VEHICLE_FACTORY_HPP
#define VEHICLE_FACTORY_HPP

#include <iostream>
#include "vehicle.hpp"
using namespace std;

class vehicle_factory {
public:
    static vehicle* getVehicle(const string& vehicleType);
};

#endif // VEHICLE_FACTORY_HPP
