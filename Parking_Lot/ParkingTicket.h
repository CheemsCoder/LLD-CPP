#ifndef PARKINGTICKET_H
#define PARKINGTICKET_H

#include <string>
#include <ctime>

class ParkingTicket {
private:
    std::string ticketID;
    std::string spotType;
    std::string vehicleRegisterNumber;
    std::time_t startTime;
    std::time_t endTime;

public:
    ParkingTicket(const std::string& id, const std::string& spotType, const std::string& regNumber)
        : ticketID(id), spotType(spotType), vehicleRegisterNumber(regNumber), startTime(std::time(nullptr)), endTime(0) {}

    void closeTicket() {
        endTime = std::time(nullptr); // Record the time when the ticket is closed
    }

    std::time_t getDuration() const {
        if (endTime == 0) {
            return 0; // Ticket is still open
        }
        return endTime - startTime; // Return duration in seconds
    }

    std::string getTicketID() const { return ticketID; }
    std::string getSpotType() const { return spotType; }
    std::string getVehicleRegisterNumber() const { return vehicleRegisterNumber; }
};

#endif
