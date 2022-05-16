#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>
using namespace std;

vector<int> zaehler(11);

double Vector(){
  ifstream fin("datensumme.txt");
  double a;
  for(int i = 0 ; i < 234 ; i++){
    fin >> a;
    zaehler[a] += 1;
  }
  fin.close();
}

double Ausgabe(){
  ofstream fout("hist.txt");
  for(int k = 0 ; k < zaehler.size() ; ++k){
    fout << k << " " << zaehler[k] << endl;
  }
  fout.close();
}

double poisson(double mu, double k){
  double m;
  m = exp(-mu) * pow(mu, k) / tgamma(k + 1);
  return m;
}

int main(){
  Vector();
  Ausgabe();
  ofstream fout("histpoi.txt");
  for (int k = 0 ; k < zaehler.size() ; ++k){
    fout << k << " " << zaehler[k] << " " << 234 * poisson(3.11538, k) << endl;
    cout << k << " " << zaehler[k] << " " << 234 * poisson(3.11538, k) << endl;
  }
  fout.close();
}