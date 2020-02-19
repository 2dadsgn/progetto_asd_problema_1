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
class Nodo{
private:
    int key;
    string value;
    Nodo* next;
    I* insieme;
public:
    int get_key();
    string get_value();
    void set_key(int input);
    void set_value(string input);
    void set_next(Nodo* in);
    Nodo* get_next();
    I* get_insieme();
    void set_insieme(I* in);
    Nodo();
};



//---------------------- funzioni della classe Nodo  -----------------------------------

//get key
template <typename I>
int Nodo<I>::get_key(){
    return this->key;
}

//get value
template <typename I>
string Nodo<I>::get_value(){
    return this->value;
}

//inserisce key
template <typename I>
void Nodo<I>::set_key(int input){
    this->key=input;
}

//inserisce value
template <typename I>
void Nodo<I>::set_value(string input){
    this->value=input;
}

//imposta il successivo
template <typename I>
void Nodo<I>::set_next(Nodo* in){
    this->next = in;

}

//ritorna il successivp
template <typename I>
Nodo<I>* Nodo<I>::get_next(){
    return this->next;
}
//costruttore
template <typename I>
Nodo<I>::Nodo(){
    this->set_next(nullptr);
    this->set_insieme(nullptr);
    this->set_key(-999);
    this->set_value("");
}

//funzione per impostare l'insieme di appartenenza
template <typename I>
void Nodo<I>::set_insieme(I* insieme_in){
    this->insieme = insieme_in;
}
template <typename I>
I* Nodo<I>::get_insieme(){
    return this->insieme;
}


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
