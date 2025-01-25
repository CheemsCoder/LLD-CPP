#ifndef VEHICLE_HPP
#define VEHICLE_HPP

class vehicle {
public:
    virtual void createVehicle() = 0;
    virtual ~vehicle() {} // Virtual destructor to clean up derived class objects
};

#endif // VEHICLE_HPP
