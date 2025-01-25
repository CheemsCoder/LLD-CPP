#ifndef PARKINGLOT_H
#define PARKINGLOT_H

#include <vector>
#include "ParkingFloor.h"
#include "EntryPanel.h"
#include "ExitPanel.h"
#include "ParkingSpotType.h"


class ParkingLot {
private:
    std::vector<ParkingFloor*> floors;
    std::vector<EntryPanel*> entryPanels;
    std::vector<ExitPanel*> exitPanels;

public:
    ParkingLot() {}

    void addFloor(ParkingFloor* floor) {
        floors.push_back(floor);
    }

    void addEntryPanel(EntryPanel* panel) {
        entryPanels.push_back(panel);
    }

    void addExitPanel(ExitPanel* panel) {
        exitPanels.push_back(panel);
    }
};

#endif
