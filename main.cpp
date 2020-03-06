#ifndef MAIN
#define MAIN

#include "hash.h"
#include "tester.h"



using namespace std;

#endif

int main(){
    tester testa;
    testa.create();
    Hash_Table  tavola("../tester.txt");
    tavola.menu();

    return 0;
}
