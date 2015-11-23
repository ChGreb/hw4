/*	Homework4	Filter
 * 	Christian Greb	20300
 */
#include<iostream>
#include<cstdlib>
#include<fstream>
#include<string>
#include<sstream>

using namespace std;


double* read(const int);
double* filter(const int, double* const);
void print(string, double* const, const int);

int main(){
  const int N = 237;
  int M;
  double* noisy;
  stringstream name;
  
  cout <<"How often should the signal be filtered?" << endl << "M= ";
  cin >> M;
  
  system("mkdir filtered_signal");
  noisy = read(N);
    
  for(int j=0; j<M; j++){
    noisy = filter(N, noisy);
    name.str("");
    name << "filtered_signal/filtered_" << (j+1) <<".txt";
    print(name.str(), noisy, N);
  }
  
  delete[] noisy;
  return 0; 
}


double* read(const int N){
  ifstream input("noisy.txt");
  double* noisy = new double[N];
  
  for(int i=0;i<N;i++)
    input >> noisy[i];
  
  input.close();
  return noisy;
}


double* filter(const int N, double* const noisy){
   double temp0, temp1, tempN;    
   temp0 = tempN = noisy[0];
   temp1 = noisy[1];
   noisy[0] = (noisy[N-1]+noisy[0]+noisy[1])/3; 
    
    for(int i=1; i<(N-1);i++){
      noisy[i] = (temp0+temp1+noisy[i+1])/3;
      temp0 = temp1;
      temp1 = noisy[i+1];
    }
   noisy[N-1] = (temp0+temp1+tempN)/3;
   return noisy;
  }   
  
void print(string name, double* const noisy, const int N){
  ofstream out(name.c_str());
  for(int i=0; i<N; i++)
    out << noisy[i] << endl;
  out.close();
}  