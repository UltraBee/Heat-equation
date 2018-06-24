#ifndef SOLVER_H
#define SOLVER_H

#include <iostream>
#include <string>
#include "Equation.h"
#include "Parameters.h"
using namespace std;

class Solver{
public:

  Solver(Equation &eq, Parameters &par);
  ~Solver();

  vector < vector<double> > solve();
  void saveSolution(string file);

private:
  int m;
  double dt, dx, epsilon;
  vector<double> alfa, fx, temp;
  vector < vector<double> > u;
};
#endif
