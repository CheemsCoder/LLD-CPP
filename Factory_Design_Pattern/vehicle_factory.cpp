#include "vehicle_factory.hpp"
#include "car.hpp"
#include "bike.hpp"
#include <iostream>
using namespace std;

vehicle* vehicle_factory::getVehicle(const string& vehicleType) {
    vehicle* vehicle = nullptr;
    if (vehicleType == "car") {
        vehicle = new car();
    } else if (vehicleType == "bike") {
        vehicle = new bike();
    } else {
        cout << "Please provide a valid type (bike/car)" << endl;
    }
    return vehicle;
}
