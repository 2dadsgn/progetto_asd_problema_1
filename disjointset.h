//
// Created by daniele lubrano on 10/02/2020.
//

#ifndef PROGETTO_ASD_PROBLEMA_1_DISJOINTSET_H
#define PROGETTO_ASD_PROBLEMA_1_DISJOINTSET_H

#include <string>
using namespace std;

//class nodo dell'insieme disgiunto
template <typename I>
class Nodo{
private:
    int key;
    string value;
    I* insieme;
    Nodo* next;
public:
    int get_key();
    string get_value();
    Nodo* get_next();
    //ritorna il ptr alla radice
    I* get_insieme();
    void set_key(int input);
    void set_value(string input);
    void set_next(Nodo* input);
    void set_insieme(I* input);
    Nodo();
};

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

//get successivo nodo
template <typename I>
Nodo<I>* Nodo<I>::get_next(){
    return this->next;
}

//ritorna il ptr alla radice
template <typename I>
I* Nodo<I>::get_insieme(){
    return this->insieme;
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
//inserisce next
template <typename I>
void Nodo<I>::set_next(Nodo* input){
    this->next=input;
}
//imposta l insieme di appartenenza
template <typename I>
void Nodo<I>::set_insieme(I* input){
    this->insieme=input;
}
//costruttore
template <typename I>
Nodo<I>::Nodo(){
    this->set_next(nullptr);
    this->set_insieme(nullptr);
    this->set_key(-999);
    this->set_value("");
}


//classe insieme con puntatore alla radice e alla coda, gestisce l'insieme disgiunto
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

Nodo<Insieme>* Insieme::get_head(){
    return this->head;
}
//ritorna il ptr alla radice
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
//overload del costruttore
Insieme::Insieme(int key_in, string value_in){
    this->set_head(new Nodo <Insieme>());
    this->set_tail(this->get_head());
    head->set_key(key_in);
    head->set_value(value_in);
    head->set_insieme(this);
    this->set_rank(0);
}
Insieme::Insieme(){
    this->set_head(new Nodo <Insieme>());
    this->set_tail(this->get_head());
    head->set_insieme(this);
    this->set_rank(0);
}

#endif //PROGETTO_ASD_PROBLEMA_1_DISJOINTSET_H
