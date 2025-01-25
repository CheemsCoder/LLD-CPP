#include <iostream>
#include "Logger.hpp"
using namespace std;
int Logger::ctr = 0;
Logger* Logger::loggerInstance = nullptr;
mutex Logger::mtx;

Logger::Logger() {
  ctr++;
  cout << "New instance created. No of instaces " << ctr << endl;
}

void Logger::log(string s) {
  cout << s << endl;
}

Logger* Logger::getLogger() {
  // double check locking, as we need to be thread only at the first time of creating instance
  if(loggerInstance == nullptr) {
    // thread safety in singleton
    mtx.lock();
    if(loggerInstance == nullptr) {
      loggerInstance = new Logger();
    }
    mtx.unlock();
  }
  
  return loggerInstance;
}

