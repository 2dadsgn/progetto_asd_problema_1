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




//------ funzioni dichiarate esteranmente----------

//imposta la cella successiva
void Cella::set_next(Cella* cella_in){
    this->next = cella_in;
}

//ritorna la cellasuccessiva come puntatore
Cella* Cella::get_next(){
    return this->next;
}

//imposta la cella precedente
void Cella::set_prev(Cella* cella_in){
    this->prev = cella_in;
}

//ritorna la cella precedente come puntatore
Cella* Cella::get_prev(){
    return this->prev;
}

//setta ptr a insieme
void Cella::set_insieme(Insieme* insieme_in){
    this->insieme = insieme_in;
}

//ritorna ptr a insieme
Insieme* Cella::get_insieme() {
    return this->insieme;
}
//overloading costruttore
Cella::Cella(Insieme* insieme_in, Cella* inprev, Cella* innext){
    this->set_insieme(insieme_in);
    this->set_next(innext);
    this->set_prev(inprev);
}

//overloading costruttore
Cella::Cella(Insieme* insieme_in){
    this->set_insieme(insieme_in);
    this->set_next(nullptr);
    this->set_prev(nullptr);
}

//costruttore per inizializzare cella vuota
Cella::Cella(){
    this->set_insieme(nullptr);
    this->set_next(nullptr);
    this->set_prev(nullptr);
}



//funzioni class linked list

//imposta cella in testa
void Linked_List::set_testa(Cella* in){
    this->testa = in;
}
//imposta cella in coda
void Linked_List::set_coda(Cella* in){
    this->coda = in;
}

//ottiene cella in testa
Cella* Linked_List::get_testa(){
    return this->testa;
}

//ottiene cella in coda
Cella* Linked_List::get_coda(){
    return this->coda;
}

//costruttore

Linked_List::Linked_List() {
    this->set_testa(nullptr);
    this->set_coda(nullptr);
}

//inseriscel insieme nella lista linkata
void Linked_List::ins(Insieme* insieme_in){
    Cella* cursore;
    if(this->get_testa() == nullptr){
        //inserisco la cella in testa
        this->set_testa(new Cella(insieme_in));
        this->set_coda(this->testa);
    }
    else{
        //altrimenti collissione inserisce in coda
        cursore = this->get_coda();
        //inserisco la nuova cella in coda
        cursore->set_next(new Cella(insieme_in ,cursore, nullptr));
        this->set_coda(cursore->get_next());
    }

}

//funzione per la cancellazione di un elemento dalla lista
void Linked_List::del(Insieme* insieme_in){
    Cella* cursore = this->get_testa();
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


#endif //PROGETTO_ASD_PROBLEMA_1_CELLA_CPP
