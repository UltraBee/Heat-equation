#ifndef PARAMETERS_H
#define PARAMETERS_H

#include <iostream>
#include <string>

using namespace std;

class Parameters{
public:
  //Constructors
  Parameters();
  Parameters(string file);
  Parameters(double a, int b, double c);
  Parameters(const Parameters& pattern);
  ~Parameters();

  //Methods
  double show_delta_x(){
    return delta_x;
  }
  double show_epsilon(){
    return epsilon;
  }
  int show_m(){
    return m;
  }

private:
  double delta_x;
  double epsilon;
  int m;
};
#endif
