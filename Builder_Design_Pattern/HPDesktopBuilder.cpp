#include "HPDesktopBuilder.hpp"
#include <iostream>
using namespace std;

void HPDesktopBuilder::buildKeyboard() {
  desktop->setKeyboard("HP Keyboard");
}

void HPDesktopBuilder::buildMonitor() {
  desktop->setMonitor("HP 24-inch Monitor");
}

void HPDesktopBuilder::buildMotherboard() {
  desktop->setMotherboard("HP Motherboard");
}

void HPDesktopBuilder::buildProcessor() {
  desktop->setProcessor("HP Intel Core i7");
}

void HPDesktopBuilder::buildMouse() {
  desktop->setMouse("HP Wireless Mouse");
}

void HPDesktopBuilder::buildRam() {
  desktop->setRam("HP 16GB DDR4 RAM");
}


