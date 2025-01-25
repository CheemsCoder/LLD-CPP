#ifndef PARKINGSPOT_H
#define PARKINGSPOT_H

#include "Vehicle.h"
#include "ParkingSpotType.h"

class ParkingSpot {
private:
    std::string spotID;
    ParkingSpotType spotType;
    bool isAvailable;
    Vehicle* parkedVehicle;

public:
    ParkingSpot(const std::string& id, ParkingSpotType type)
        : spotID(id), spotType(type), isAvailable(true), parkedVehicle(nullptr) {}

    bool assignVehicle(Vehicle* vehicle) {
        if (isAvailable && isSpotCompatible(vehicle)) {
            parkedVehicle = vehicle;
            isAvailable = false;
            return true;
        }
        return false;
    }

    void vacateSpot() {
        parkedVehicle = nullptr;
        isAvailable = true;
    }

    bool isSpotAvailable() const {
        return isAvailable;
    }

    ParkingSpotType getSpotType() const {
        return spotType;
    }

    bool isSpotCompatible(Vehicle* vehicle) const {
        if (spotType == ParkingSpotType::Compact && vehicle->getType() == VehicleType::Car)
            return true;
        if (spotType == ParkingSpotType::Large && vehicle->getType() == VehicleType::Truck)
            return true;
        if (spotType == ParkingSpotType::Electric && vehicle->getType() == VehicleType::ElectricCar)
            return true;
        if (spotType == ParkingSpotType::Motorcycle && vehicle->getType() == VehicleType::Motorbike)
            return true;
        return false;
    }
};

#endif
