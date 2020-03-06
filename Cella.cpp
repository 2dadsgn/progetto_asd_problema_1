//
// Created by daniele lubrano on 17/02/2020.
//

//
// Created by daniele lubrano on 13/02/2020.
//

#ifndef PROGETTO_ASD_PROBLEMA_1_CELLA_CPP
#define PROGETTO_ASD_PROBLEMA_1_CELLA_CPP

#include "Cella.h"
#include "disjointset.h"
#include <iostream>
 using namespace std;




//-----------------------funzioni class linked list -----------------------

//imposta cella in testa
void Linked_List::set_testa(Cella<Linked_List>* in){
    this->testa = in;
}
//imposta cella in coda
void Linked_List::set_coda(Cella<Linked_List>* in){
    this->coda = in;
}

//ottiene cella in testa
Cella<Linked_List>* Linked_List::get_testa(){
    return this->testa;
}

//ottiene cella in coda
Cella<Linked_List>* Linked_List::get_coda(){
    return this->coda;
}

//costruttore

Linked_List::Linked_List() {
    this->set_testa(nullptr);
    this->set_coda(nullptr);
}

//inseriscel insieme nella lista linkata
void Linked_List::ins(Insieme* insieme_in){
    Cella<Linked_List>* cursore;
    if(this->get_testa() == nullptr){
        //inserisco la cella in testa
        this->set_testa(new Cella<Linked_List>(insieme_in));
        this->testa->set_lista(this);
        this->set_coda(this->testa);
    }
    else{
        //altrimenti collissione inserisce in coda
        cursore = this->get_coda();
        //inserisco la nuova cella in coda
        cursore->set_next(new Cella<Linked_List>(insieme_in ,cursore, nullptr));
        this->set_coda(cursore->get_next());
        this->coda->set_lista(this);
    }

}

//funzione per la cancellazione di un elemento dalla lista
void Linked_List::del_insieme(Insieme* insieme_in){
    Cella<Linked_List>* cursore = this->get_testa();
    if(this->get_testa()->get_insieme()->get_head() == insieme_in->get_head()){
        //è la testa
        //elimina il collegamento dal secondo elemento alla attuale testa
        cursore->get_next()->set_prev(nullptr);
        //impost come nuova testa della coda il secondo elemento
        this->set_testa(cursore->get_next());

    }
    else if(this->get_coda()->get_insieme()->get_head() == insieme_in->get_head()){
        //si trova in coda
        cursore = this->get_coda()->get_prev();
        //imposto come nuova coda il penultimo
        this->set_coda(cursore);
        //elimino collegamento alla precedente coda
        this->coda->set_next(nullptr);
    }
    else{
        //è un elemento di mezzo
        while (cursore != nullptr){
            if(cursore->get_insieme()->get_head() == insieme_in->get_head()){
                //imposto il putantore dell'elemento precedente a cursore in modo tale che punti
                //al successivo di cursore
                cursore->get_prev()->set_next(cursore->get_next());
                //imposto il puntatore del successivo a cursore in modo tale che punti
                //al precedente di cursore
                cursore->get_next()->set_prev(cursore->get_prev());
                break;
            }
            cursore = cursore->get_next();
        }

    }
}

//cancellazione cella
void Linked_List::del_cella(Cella<Linked_List>* cella_in){
    Cella<Linked_List>* ptr;

    if(  cella_in->get_prev() == nullptr ){
        //la cella in input è la testa della lista
        if(cella_in->get_next() == nullptr){
            //allora la cella è unica
            cella_in->get_lista()->set_coda(nullptr);
            cella_in->get_lista()->set_testa(nullptr);

        }
        else{
            //altrimenti la cella successiva diviene la nuova testa della lista
            ptr = cella_in->get_next();//successivo di cella_in
            ptr->set_prev(nullptr);
            cella_in->get_lista()->set_testa(ptr);
        }
    }
    else if ( cella_in->get_next() == nullptr){
        //allora la cella è la coda
        ptr = cella_in->get_prev();
        ptr->set_next(nullptr);
        cella_in->get_lista()->set_coda(ptr);

    }
    else{
        //altrimenti la cella è una celle di mezzo
        cella_in->get_prev()->set_next(cella_in->get_next());
        cella_in->get_next()->set_prev(cella_in->get_prev());

    }

}


#endif //PROGETTO_ASD_PROBLEMA_1_CELLA_CPP
