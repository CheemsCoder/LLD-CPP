#ifndef VEHICLE_H
#define VEHICLE_H

#include <string>

enum class VehicleType {
    Car,
    Truck,
    ElectricCar,
    Motorbike
};

class Vehicle {
protected:
    std::string registerNumber;
    VehicleType type;

public:
    Vehicle(const std::string& regNumber, VehicleType vehicleType)
        : registerNumber(regNumber), type(vehicleType) {}

    virtual ~Vehicle() = default;

    VehicleType getType() const {
        return type;
    }

    std::string getRegisterNumber() const {
        return registerNumber;
    }
};

class Car : public Vehicle {
public:
    Car(const std::string& regNumber) : Vehicle(regNumber, VehicleType::Car) {}
};

class Truck : public Vehicle {
public:
    Truck(const std::string& regNumber) : Vehicle(regNumber, VehicleType::Truck) {}
};

class ElectricCar : public Vehicle {
public:
    ElectricCar(const std::string& regNumber) : Vehicle(regNumber, VehicleType::ElectricCar) {}
};

class Motorbike : public Vehicle {
public:
    Motorbike(const std::string& regNumber) : Vehicle(regNumber, VehicleType::Motorbike) {}
};

#endif
