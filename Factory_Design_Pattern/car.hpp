#ifndef CAR_HPP
#define CAR_HPP

#include "vehicle.hpp"
using namespace std;

class car : public vehicle {
public:
    void createVehicle() override;
};

#endif // CAR_HPP
