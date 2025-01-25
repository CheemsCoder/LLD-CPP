#include <iostream>
#include "Logger.hpp"
#include <thread>
using namespace std;

void user1logs() {
  Logger* log1 = Logger::getLogger();
  log1->log("test msg 1");
}

void user2logs() {
  Logger* log2 = Logger::getLogger();
  log2->log("test msg 2");
}

int main() {
  thread t1(user1logs);
  thread t2(user2logs);
  t1.join();
  t2.join();
  return 0;
}