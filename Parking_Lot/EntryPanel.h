#ifndef ENTRYPANEL_H
#define ENTRYPANEL_H

#include "Vehicle.h"
#include "ParkingSpot.h"
#include "ParkingTicket.h"
#include "ParkingSpotType.h"
#include <string>

class EntryPanel {
private:
    std::string entryPanelID;

public:
    EntryPanel(const std::string& id) : entryPanelID(id) {}

    ParkingTicket* generateParkingTicket(Vehicle* vehicle, ParkingSpot* spot) {
        return new ParkingTicket(
            "TICKET-" + vehicle->getRegisterNumber(),
            parkingSpotTypeToString(spot->getSpotType()), // Convert enum to string
            vehicle->getRegisterNumber()
        );
    }
};

#endif
