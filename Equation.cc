#include "Equation.h"
#include <fstream>

Equation::Equation(){
  //temperature
  vector<double> vec;
  for(int i=0; i<100; i++){
    if(i>=40 && i<=60){
      vec.push_back(100);
    } else if(i<40 || i>60){
      vec.push_back(0);
    }
  }
  temperature.push_back(vec);

  //diffusivity
  for(int i=0; i<100; i++){
    if(i<50){
      diffusivity.push_back(0.1);
    } else if(i>=50){
      diffusivity.push_back(0.01);
    }
  }
  //Heat sources
  for(int i=0; i<100; i++){
    heat_sources.push_back(0);
  }
}

Equation::Equation(string file){
  ifstream file_stream(file.c_str());
  if(file_stream.fail()){
    cout << "Problem with file opening" << endl;
  }

  double a,b,c;
  vector<double> vec;

  while (true) {
    file_stream >> a >> b >> c;
    if(file_stream.fail()) break;

    vec.push_back(a);
    diffusivity.push_back(b);
    heat_sources.push_back(c);
  }
  temperature.push_back(vec);
  file_stream.close();
}


Equation::Equation(const Equation& pattern){
  temperature = pattern.temperature;
  diffusivity = pattern.diffusivity;
  heat_sources = pattern.heat_sources;
}


Equation::~Equation(){
  // cout << "Object Equation deleted." << endl;
}

//Metods
vector < vector<double> > Equation::show_temperature(){
  return temperature;
}

vector<double> Equation::show_diffisivity(){
  return diffusivity;
}

vector<double> Equation::show_heat_sources(){
  return heat_sources;
}
