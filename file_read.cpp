#include <string>
#include <fstream>
#include <iostream>
using namespace std;

bool get_input_from_file(string nome_file,int* numero_elementi){
  fstream file;
  string line, value;
  int a, b,contatore=0;

  file.open(nome_file);

  if(file.fail()){
      cout<<"file non trovato"<<endl;
    return false;
  }

  //conto numero di elementi per poi stabilire m in hash
  while(getline(file,line)){

      contatore++;
  }
  *numero_elementi = contatore;
  //resetto puntatore a file
  file.clear();
  file.seekg(0,ios::beg);

  //prelevo linee
  while(getline(file,line)){
    //rilevo lo spazio di mezzo a key e value_in
    a  = line.find(' ');
    //ottengo la key
    b = stoi(line.substr(0,a));
    //ottengo la stringa
    value = line.substr(a);

  }

  file.close();
  return true;

}
