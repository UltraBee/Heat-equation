#include <iostream>
#include <string>
#include "Parameters.h"
#include "Equation.h"
#include "Solver.h"
using namespace std;

int main(){
  Parameters p;
  Equation e;

  cout << "Witaj w programie! Wpisz odpowiednią cyfrę:" << endl;
  cout << "1. Wczytuję parametry delta_x, m i epsilon z pliku." << endl;
  cout << "2. Wpisuję parametry z klawiatury." << endl;
  cout << "3. Chcę parametry domyślne." << endl;

  int x;
  cin >> x;

  if(x==1){
    cout << "Wpisz nazwę pliku: " << endl;
    string file;
    cin >> file;
    Parameters p(file.c_str());
  }
  else if(x==2){
    double a,c;
    int b;
    cout << "Podaj delta_x: ";
    cin >> a;
    cout << "Podaj m: ";
    cin >> b;
    cout << "Podaj epsilon: ";
    cin >> c;
    Parameters p (a,b,c);
  }
  else if(x==3){
    Parameters p;
  } else{
    cout << "Błąd! Koniec programu." << endl;
    return 1;
  }
  cout << endl;
  cout << "Wpisz odpowiednią cyfrę:" << endl;
  cout << "1. Wczytuję dane do równania z pliku." << endl;
  cout << "2. Chcę wczytać domyślne dane." << endl;
  cin >> x;
  if(x==1){
    cout << "Wpisz nazwę pliku: " << endl;
    string file;
    cin >> file;
    Equation e(file.c_str());
  } else if(x==2){
    Equation e;
  } else {
      cout << "Błąd! Koniec programu." << endl;
      return 1;
  }

  cout << endl << "Do jakiego pliku chcesz zapisać wyniki?" << endl;
  string solution_file;
  cin >> solution_file;

  Solver s(e,p);
  s.solve();
  s.saveSolution(solution_file.c_str());

  cout << endl << "Wyniki zostały wyeksportowane do pliku " << solution_file << endl;

  //Tests
  // cout << p1.show_delta_x() << endl;
  // cout << p1.show_epsilon() << endl;
  // cout << p1.show_m() << endl;
  //
  // cout << p2.show_delta_x() << endl;
  // cout << p2.show_epsilon() << endl;
  // cout << p2.show_m() << endl;
  //
  // e1.show_diffisivity();
  // e1.show_initial_conditions();
  // e1.show_heat_sources();


  return 0;
}
