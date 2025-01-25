# Logger Singleton Example
This project demonstrates a simple implementation of the Singleton design pattern in C++, with a thread-safe logger.

## Features
- Implements Singleton Design Pattern
- Thread-safe logger using `std::mutex`
- Logs messages from multiple threads

## Getting Started

### Prerequisites
Ensure you have `g++` or another C++ compiler installed on your system.

### Installation
Clone this repository and navigate to the project folder:

### Compilation and Running
Use the following command to compile the project:
g++ -o singleton *.cpp -std=c++11

Run the program:
./singleton

### Example Output
New instance created. No of instaces 1
test msg 1
test msg 2
