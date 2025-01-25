#ifndef PARKINGFLOOR_H
#define PARKINGFLOOR_H

#include <vector>
#include <string>
#include "ParkingSpot.h"

class ParkingFloor {
private:
    std::string floorID;
    std::vector<ParkingSpot> spots;

public:
    ParkingFloor(const std::string& id) : floorID(id) {}

    void addParkingSpot(const ParkingSpot& spot) {
        spots.push_back(spot);
    }

    ParkingSpot* findAvailableSpot(Vehicle* vehicle) {
        for (auto& spot : spots) {
            if (spot.isSpotAvailable() && spot.isSpotCompatible(vehicle)) {
                return &spot;
            }
        }
        return nullptr;
    }

    std::string getFloorID() const {
        return floorID;
    }
};

#endif
