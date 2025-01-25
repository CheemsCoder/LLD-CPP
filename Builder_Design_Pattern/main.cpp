#include "HPDesktopBuilder.hpp"
#include "DellDesktopBuilder.hpp"
#include "DesktopDirector.hpp"

int main() {
  HPDesktopBuilder* hpDesktopBuilder = new HPDesktopBuilder();
  DellDesktopBuilder* dellDesktopBuilder = new DellDesktopBuilder();

  DesktopDirector* director1 = new DesktopDirector(hpDesktopBuilder);
  DesktopDirector* director2 = new DesktopDirector(dellDesktopBuilder);

  Desktop* desktop1 = director1->buildDesktop();
  Desktop* desktop2 = director2->buildDesktop();
  
  desktop1->showSpecs();
  desktop2->showSpecs();
  return 0;
}