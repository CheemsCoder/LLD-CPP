#ifndef EXITPANEL_H
#define EXITPANEL_H

#include <string>
#include "ParkingTicket.h"

class ExitPanel {
private:
    std::string panelID;

public:
    ExitPanel(const std::string& id) : panelID(id) {}

    double processPayment(ParkingTicket* ticket, double hourlyRate) {
        ticket->closeTicket();
        double durationInHours = static_cast<double>(ticket->getDuration()) / 3600.0;
        return durationInHours * hourlyRate;
    }
};

#endif
