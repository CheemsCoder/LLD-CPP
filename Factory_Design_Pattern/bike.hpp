#ifndef BIKE_HPP
#define BIKE_HPP

#include "vehicle.hpp"
using namespace std;

class bike : public vehicle {
public:
    void createVehicle() override;
};

#endif // BIKE_HPP
