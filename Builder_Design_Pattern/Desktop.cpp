#include "Desktop.hpp"
#include <iostream>
using namespace std;

void Desktop::setKeyboard(string pKeyboard) {
  keyboard = pKeyboard;
}
void Desktop::setMonitor(string pMonitor) {
  monitor = pMonitor;
}
void Desktop::setMotherboard(string pMotherboard) {
  motherboard = pMotherboard;
}
void Desktop::setProcessor(string pProcessor) {
  processor = pProcessor;
}
void Desktop::setMouse(string pMouse) {
  mouse = pMouse;
}
void Desktop::setRam(string pRam) {
  ram = pRam;
}
void Desktop::showSpecs() {
  cout << "-------------------------------------------" << endl;
  cout << "Monitor: " << monitor << endl;
  cout << "Keyboard: " << keyboard << endl;
  cout << "Mouse: " << mouse << endl;
  cout << "Motherboard: " << motherboard << endl;
  cout << "Processor: " << processor << endl;
  cout << "RAM: " << ram << endl;
  cout << "-------------------------------------------" << endl;
}
