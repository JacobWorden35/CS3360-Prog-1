#include <iostream>
#include <cstdlib> 
#include <ctime>
#include <random>

/*
Problem 1: 
  * Generate a workload for a system that is composed of 1000 processes.
  * Processes arrive with an expected average arrival rate of 2 processes per second that follows a Poisson Distribution.
  * Service time for each process follows an Exponential Distribution w/ expected average service time of 1 second.
  * Output: <process ID, arrival time, requested service time>
  * Process IDs are assigned incrementally starting at 1.
*/

int main() {
  //allows for rng:
  std::srand(static_cast<unsigned int>(std::time(nullptr)));
  //Declaration of Vars:
  int processID = 1;
  double arrivalTime = 0.0;
  double requestedServiceTime = 0.0;
  //Used for Poisson & Exponential
  std::default_random_engine generator;
  std::exponential_distribution<double> expDistribution(1);
  //loop through proccess's
  for (processID = 1; processID <= 1000; processID++) {
    //generate arrivalTime:
    arrivalTime = arrivalTime + (0.4 + static_cast <float> (rand()) / ( static_cast <float> (RAND_MAX/(0.6-0.4)))); 
    //arrivalTime = arrivalTime + poisDistribution(generator);
    //generate requestedServiceTime:
    requestedServiceTime = expDistribution(generator);

    //output:
    std::cout << "(" << processID << ", " << arrivalTime << ", " << requestedServiceTime << ")" << std::endl;
  }
}