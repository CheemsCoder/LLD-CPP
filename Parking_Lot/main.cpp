#include <iostream>
#include "ParkingLot.h"
#include "Vehicle.h"
#include "ParkingFloor.h"
#include "EntryPanel.h"
#include "ExitPanel.h"

int main() {
    ParkingLot parkingLot;

    // Create floors and panels
    ParkingFloor* floor1 = new ParkingFloor("Floor1");
    floor1->addParkingSpot(ParkingSpot("S1", ParkingSpotType::Compact));
    floor1->addParkingSpot(ParkingSpot("S2", ParkingSpotType::Large));
    parkingLot.addFloor(floor1);

    EntryPanel* entryPanel = new EntryPanel("Entry1");
    parkingLot.addEntryPanel(entryPanel);

    ExitPanel* exitPanel = new ExitPanel("Exit1");
    parkingLot.addExitPanel(exitPanel);

    // Simulate vehicle entry
    Vehicle* car = new Car("CAR-123");
    ParkingSpot* availableSpot = floor1->findAvailableSpot(car);
    ParkingTicket* ticket = entryPanel->generateParkingTicket(car, availableSpot);

    if (ticket) {
        std::cout << "Ticket generated: " << ticket->getTicketID() << std::endl;
    } else {
        std::cout << "No parking spot available!" << std::endl;
    }

    // Simulate vehicle exit
    double cost = exitPanel->processPayment(ticket, 20.0); // $20/hour
    std::cout << "Total cost: $" << cost << std::endl;

    delete car;
    delete ticket;
    delete floor1;
    delete entryPanel;
    delete exitPanel;

    return 0;
}
