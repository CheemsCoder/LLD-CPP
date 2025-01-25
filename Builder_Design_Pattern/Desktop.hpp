#ifndef DESKTOP_HPP
#define DESKTOP_HPP

#include <iostream>
using namespace std;

class Desktop
{
  string motherboard;
  string processor;
  string monitor;
  string mouse;
  string keyboard;
  string ram;
  public:
    void setMonitor(string pMonitor);
    void setMotherboard(string pMotherboard);
    void setProcessor(string pProcessor);
    void setMouse(string pMouse);
    void setKeyboard(string pKeyboard);
    void setRam(string pRam);
    void showSpecs();
};


#endif