#include "DellDesktopBuilder.hpp"
#include <iostream>
using namespace std;

void DellDesktopBuilder::buildKeyboard() {
  desktop->setKeyboard("Dell Keyboard");
}

void DellDesktopBuilder::buildMonitor() {
  desktop->setMonitor("Dell 24-inch Monitor");
}

void DellDesktopBuilder::buildMotherboard() {
  desktop->setMotherboard("Dell Motherboard");
}

void DellDesktopBuilder::buildProcessor() {
  desktop->setProcessor("Dell Intel Core i7");
}

void DellDesktopBuilder::buildMouse() {
  desktop->setMouse("Dell Wireless Mouse");
}

void DellDesktopBuilder::buildRam() {
  desktop->setRam("Dell 16GB DDR4 RAM");
}


