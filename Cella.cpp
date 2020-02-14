//
// Created by daniele lubrano on 13/02/2020.
//

#ifndef CELLA
#define CELLA
#include "Cella.h"
#include "disjointset.h"

using namespace std;

template  <typename I>
void Cella<I>::set_prev(Cella* cella_in){
    this->prev = cella_in;
}

template  <typename I>
Cella<I>* Cella<I>::get_prev(){
    return this->prev;
}
template  <typename I>
Cella<I>::Cella(Insieme* insieme_in){
    this->set_insieme(insieme_in);
}
#endif