#ifndef PARKINGSPOTTYPE_H
#define PARKINGSPOTTYPE_H

#include <string>

enum class ParkingSpotType {
    Compact,
    Large,
    Electric,
    Motorcycle,
    Disabled
};

// Helper function to convert ParkingSpotType to string
inline std::string parkingSpotTypeToString(ParkingSpotType spotType) {
    switch (spotType) {
        case ParkingSpotType::Compact: return "Compact";
        case ParkingSpotType::Large: return "Large";
        case ParkingSpotType::Electric: return "Electric";
        case ParkingSpotType::Motorcycle: return "Motorcycle";
        case ParkingSpotType::Disabled: return "Disabled";
        default: return "Unknown";
    }
}

#endif
