#include "Solver.h"
#include <cmath>
#include <fstream>

Solver::Solver(Equation &eq, Parameters &par){
  dx = par.show_delta_x();
  m = par.show_m();
  epsilon = par.show_epsilon();
  u = eq.show_temperature();
  alfa = eq.show_diffisivity();
  fx = eq.show_heat_sources();
}

Solver::~Solver(){
  // cout << "Object Solver deleted." << endl;
}

// solve method
vector < vector<double> > Solver::solve(){
  //max alfa
  double alfa_max=alfa[0];
  for(int i=0; i<alfa.size(); ++i){
    if(alfa[i]>alfa_max){
      alfa_max = alfa[i];
    }
  }
  //delta t
  dt = (0.5*pow(dx, 2.0))/alfa_max;

  //solution
  double solution;

  for(int i=0; i<3600; i++){ // po czasie
    vector<double> t_vec;
    t_vec.push_back(0); // z warunkow brzegowych
    for(int j=1; j<u[0].size()-1; j++){
      solution = u[i][j] + dt*fx[j] + dt*alfa[j]*(u[i][j+1] - 2*u[i][j] + u[i][j-1])/pow(dx, 2.0);
      // cout << "dla x" << j << " t=" << i << ": "<< solution << endl;
      t_vec.push_back(solution);
    }
    u.push_back(t_vec);
    // cout << "size u po dodaniu x_vec " << u.size() << u[0].size() << endl;
  }
  return u;
}


void Solver::saveSolution(string file){
  ofstream file_stream(file.c_str());

  if(file_stream.fail()){
    ofstream file_stream("solution.dat");
  }

  for(int i=0; i<3600; i++){
    if(i%m==0){ // po czasie
    for(int j=0; j<u[0].size(); j++){
        file_stream << u[i][j] << " ";
    }
    file_stream << endl;
    }
  }

  file_stream.close();
}
