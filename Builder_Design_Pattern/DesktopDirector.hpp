#ifndef DESKTOPDIRECTOR_HPP
#define DESKTOPDIRECTOR_HPP

#include "DesktopBuilder.hpp"

class DesktopDirector {
  private:
    DesktopBuilder* desktopBuilder;
  public:
    DesktopDirector(DesktopBuilder* pDesktopBuilder) {
      desktopBuilder = pDesktopBuilder;
    }
    Desktop* getDesktop() {
      return desktopBuilder->getDesktop();
    }
    Desktop* buildDesktop() {
      desktopBuilder->buildKeyboard();
      desktopBuilder->buildMonitor();
      desktopBuilder->buildMotherboard();
      desktopBuilder->buildMouse();
      desktopBuilder->buildProcessor();
      desktopBuilder->buildRam();
      return desktopBuilder->getDesktop();
    }

};


#endif