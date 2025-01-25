#ifndef LOGGER_HPP
#define LOGGER_HPP
#include <iostream>
#include <mutex>
using namespace std;

class Logger {
  static int ctr;
  static Logger* loggerInstance;
  static mutex mtx;
  Logger();
  Logger(const Logger &);
  Logger operator=(const Logger &);
  public:
    void log(string s);
    static Logger* getLogger();
};

#endif