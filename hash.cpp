/*funzioni hash*/
#ifndef HASH
#define HASH
#include <vector>
#include <math.h>
#include <iostream>
#include <time.h>
#include <stdlib.h>
#include "header.h"

using namespace std;


//qui funzione moltiplicazione
int metodo_divisione(int key, int* m){
  int k = *m;

  return  key % k;
};

//qui funzione has divisione
int metodo_moltiplicazione(int key, int* m){
  //stabilire A
  float A =(sqrt(5)-1)/2;
  float result = key * A;
  result = result -int(result);
  return *m * result;
};

//funzione per verifica se numero primo
bool is_primo(int n){
  int meta = n/2;
  for(int k=2;k<= meta;k++){
    if(n%k == 0){
      return false;
    }
  }
  return true;
}

//funzione per la ricerca del numero primo più vicino ad m ma lontano da 2^k
int ricerca_estremi(int* m){
  int k  = *m;
  int t=k;
  int e1=2,e2=2;
  bool res1 =false, res2 = false;
  //ricerca potenza del due inferiore
  while((2^e1)< k){
    e1++;
  }
  e2 = e1;
  e1--;

  //ricerca numero primo
  while(res1 != true || res2 != true){

    res1 = is_primo(k);
    res2 = is_primo(t);
    t++;
    k--;
  }

  if(res1 == true){
    return k;
  }
  else{
    return t;
  }


};


//inizializzare caso nel main a 0
//alla prima chiamata inserendo il numero di elementi che si avranno in input
//restituisce l indice max con cui poi inizilizzare array
int get_hash_index( int key, int* caso, int* m){
  int indice=0;
  srand (time(NULL));


  //se caso == 0 non ho ma determinato la funzione hash
  if( *caso == 0){
    //genero un numero random tra 1 e 2
    *caso = rand()%2+1;

    if(*caso == 1){
      //m temporaneo
      *m = key / 3;
      *m = ricerca_estremi(m);
    }
    else{
      int k=2,potenza=pow(2,k);
      //m nella divisione
      while (potenza < key) {
        k++;
        potenza = pow(2,k);
      }
      *m =pow(2,k);
    }
  }

  switch(*caso){
    case 1:
    //prima funzione HASH divisione
    indice = metodo_divisione(key,m);

    break;

    case 2:
    //seconda funzione hash moltiplicazione
    indice = metodo_moltiplicazione(key,m);
    break;
  }

  return indice;

}


#endif
