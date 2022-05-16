#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>
using namespace std;

vector<int> daten;
int zahl;

int Construct(){
  ifstream fin ("datensumme.txt");
  for(int i=0; i<234;i++){
    fin >> zahl;
    daten.push_back(zahl);
  }
  fin.close();
}

double prob(vector<int> daten, double mu){
  double m = 1;
  for(int k : daten){
    m *= exp(-mu) * pow(mu, k) / tgamma(k + 1);
  }
  return m;
}

double prob2(vector<int> daten){
  double m = 1;
  for(int k : daten){
    m *= exp(-k) * pow(k, k) / tgamma(k + 1);
  }
  return m;
}

int main(){
  ofstream fout ("likelihood.txt");  
  ofstream fout2 ("nll.txt");
  ofstream fout3 ("deltanll.txt");
  Construct();
  cout << prob(daten, 3.11538) << endl;
  double a = 0,b;
  for (int i = 0; i<61;i++){
    fout << a << " " << prob(daten, a) << endl;
    fout2 << a << " " << -2*log(prob(daten, a)) << endl;
    fout3 << a << " " << -2*log(prob(daten, a))-2*log(prob(daten, 3.11538)) << endl;
    a += 0.1;
  }
  b = -2*log(prob(daten, 3.11538)/prob2(daten));
  cout << -2*log(prob(daten, 3.11538)/prob2(daten)) << endl;
  cout << (b-233)/sqrt(2*233) << endl;
  fout.close();
  fout2.close();
  fout3.close();
}