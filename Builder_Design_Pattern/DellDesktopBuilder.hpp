#ifndef DELLDESKTOPBUILDER_HPP
#define DELLDESKTOPBUILDER_HPP

#include "DesktopBuilder.hpp"

class DellDesktopBuilder: public DesktopBuilder {
  void buildMotherboard();
  void buildMonitor();
  void buildProcessor();
  void buildMouse();
  void buildKeyboard();
  void buildRam();
};

#endif