#include <iostream>
#include "vehicle_factory.hpp"
using namespace std;

int main() {
    string vehicleType;
    cout << "Please Enter Vehicle Type: ";
    cin >> vehicleType;
    
    vehicle* vehicle = vehicle_factory::getVehicle(vehicleType);
    if (vehicle) {
        vehicle->createVehicle();
        delete vehicle; // Clean up memory
    }

    return 0;
}
