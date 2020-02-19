/*insieme disgiunto disjointset*/

#ifndef INSIEME_DISGIUNTO
#define INSIEME_DISGIUNTO

#include <string>
#include "disjointset.h"
#include <iostream>
using namespace std;

//---------------------- funzioni della classe insieme  -----------------------------------

//ritorna il ptr alla testa della lista
Nodo<Insieme>* Insieme::get_head(){
    return this->head;
}
//ritorna il ptr alla coda della lista
Nodo<Insieme>* Insieme::get_tail(){
    return this->tail;
}
//imposta la testa della lista
void Insieme::set_head(Nodo<Insieme>* input){
    this->head=input;
}
//impodta la coda della lista
void Insieme::set_tail(Nodo<Insieme>* input){
    this->tail=input;
}
//imposta il rango della radice
void Insieme::set_rank(int input){
    this->rank=input;
}
//restituisce il rango della radice
int Insieme::get_rank(){
    return this->rank;
}
//overloading del costruttore
Insieme::Insieme(int key_in, string value_in){
    this->set_head(new Nodo <Insieme>());
    this->set_tail(this->get_head());
    head->set_key(key_in);
    head->set_value(value_in);
    head->set_insieme(this);
    this->set_rank(0);

}

//costruttore con inizializzazione
Insieme::Insieme(){
    this->set_head(new Nodo <Insieme>());
    this->set_tail(this->get_head());
    head->set_insieme(this);
    this->set_rank(0);
}

#endif
