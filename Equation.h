#ifndef EQUATION_H
#define EQUATION_H

#include <iostream>
#include <string>
#include <vector>


using namespace std;

class Equation{
public:
  Equation();
  Equation(string file);
  Equation(const Equation& pattern);
  ~Equation();

  //Methods
  vector < vector<double> > show_temperature();
  vector<double> show_diffisivity();
  vector<double> show_heat_sources();
private:
  // double x;
  vector < vector<double> > temperature;
  vector<double> diffusivity;
  vector<double> heat_sources;
};
#endif
