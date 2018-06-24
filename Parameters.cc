#include "Parameters.h"
#include <fstream>

Parameters::Parameters(){
  delta_x = 0.1;
  m = 20;
  epsilon = 0.001;
}

Parameters::Parameters(string file){
  ifstream file_stream(file.c_str());
  if(file_stream.fail()){
    cout << "Problem with file opening" << endl;
  }
  double a,c;
  int b;

  file_stream >> a >> b >> c;
  if(file_stream.fail()){
    cout << "Problem with stream. Check the file." << endl;
  }

  delta_x = a;
  m = b;
  epsilon = c;
  file_stream.close();
}


Parameters::Parameters(double a, int b, double c){
  delta_x = a;
  m = b;
  epsilon = c;
}

Parameters::Parameters(const Parameters& pattern){
  delta_x = pattern.delta_x;
  m = pattern.m;
  epsilon = pattern.epsilon;
}

Parameters::~Parameters(){
  // cout << "Object Parameters deleted." << endl;
}
