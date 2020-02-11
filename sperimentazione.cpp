#include <iostream>
#include <math.h>
#include <fstream>

using namespace std;


int main(){
  string linea;
  fstream file;
  file.open("file.txt");
  while(getline(file,linea)){
    cout<<linea<<endl;
  }
  file.clear();
  file.seekg(0,ios::beg);

  while(getline(file,linea)){
    cout<<linea<<endl;
  }
  file.close();

  }
