#ifndef MAIN
#define MAIN
#include <iostream>
#include <vector>
#include "header.h"


using namespace std;

#endif

int main(){
  int numero_elementi=0;
  int index, m=0, caso = 0, key = 1999;
  try{
      get_input_from_file("file.txt", &numero_elementi);
  }
  catch (...){
      cout<<"errore in lettura file"<<endl;
  }

  index = get_hash_index(numero_elementi,&caso,&m);
  cout<<index<<" - "<<m<<endl;



}
