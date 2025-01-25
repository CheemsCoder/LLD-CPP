#ifndef HPDESKTOPBUILDER_HPP
#define HPDESKTOPBUILDER_HPP

#include "DesktopBuilder.hpp"

class HPDesktopBuilder: public DesktopBuilder {
  void buildMotherboard();
  void buildMonitor();
  void buildProcessor();
  void buildMouse();
  void buildKeyboard();
  void buildRam();
};

#endif