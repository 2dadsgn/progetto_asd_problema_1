//
// Created by daniele lubrano on 10/02/2020.
//

#ifndef PROGETTO_ASD_PROBLEMA_1_DISJOINTSET_H
#define PROGETTO_ASD_PROBLEMA_1_DISJOINTSET_H

#include <string>
#include "header.h"
using namespace std;



//-------------class nodo dell'insieme disgiunto per problema 1
template <typename I>
class Nodo: public GeneralNode<I>{
private:
    int key;
    string value;
public:
    int get_key();
    string get_value();
    //ritorna il ptr alla radice
    void set_key(int input);
    void set_value(string input);
    Nodo();
};


//------------------classe insieme con puntatore alla radice e alla coda, gestisce l'insieme disgiunto
class Insieme{
private:
    Nodo <Insieme>* head;
    Nodo <Insieme>* tail;
    int rank;
public:

    Nodo<Insieme>* get_head();
    //ritorna il ptr alla radice
    Nodo<Insieme>* get_tail();
    void set_head(Nodo<Insieme>* input);
    void set_tail(Nodo<Insieme>* input);
    void set_rank(int input);
    int get_rank();

    //overload del costruttore
    Insieme(int key_in, string value_in);
    Insieme();
};





#endif //PROGETTO_ASD_PROBLEMA_1_DISJOINTSET_H
