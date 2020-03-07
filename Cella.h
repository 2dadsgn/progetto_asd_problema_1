//
// Created by daniele lubrano on 13/02/2020.
/*la classe linked list gestisce la classe cella */
//

#ifndef PROGETTO_ASD_PROBLEMA_1_CELLA_H
#define PROGETTO_ASD_PROBLEMA_1_CELLA_H


#include "disjointset.h"


template <typename I>
class Cella{
private:
    Insieme* insieme;
    Cella* prev;
    Cella* next;
    I* lista;
public:
    void set_prev(Cella* cella_in);
    Cella* get_prev();
    Cella* get_next();
    void set_next(Cella* input);
    void set_insieme(Insieme* insieme_in);
    Insieme* get_insieme();
    void set_lista(I* lista_in);
    I* get_lista();

    Cella(Insieme* insieme_in);

    Cella(Insieme* insieme_in, Cella* inprev, Cella* innext);

    //costruttore per inizializzare cella vuota
    Cella();
};


//------ funzioni dichiarate esteranmente della classe CELLA----------

//imposta la cella successiva
template <typename I>
void Cella<I>::set_next(Cella* cella_in){
    this->next = cella_in;
}

//ritorna la cellasuccessiva come puntatore
template <typename I>
Cella<I>* Cella<I>::get_next(){
    return this->next;
}

//imposta la cella precedente
template <typename I>
void Cella<I>::set_prev(Cella* cella_in){
    this->prev = cella_in;
}

//ritorna la cella precedente come puntatore
template <typename I>
Cella<I>* Cella<I>::get_prev(){
    return this->prev;
}

//setta ptr a insieme
template <typename I>
void Cella<I>::set_insieme(Insieme* insieme_in){
    this->insieme = insieme_in;
}

//ritorna ptr a insieme
template <typename I>
Insieme* Cella<I>::get_insieme() {
    return this->insieme;
}

//imposta la lista di appartenenza
template <typename I>
void Cella<I>::set_lista(I* lista_in){
    this->lista = lista_in;

}
//overloading costruttore
template <typename I>
Cella<I>::Cella(Insieme* insieme_in, Cella* inprev, Cella* innext){
    this->set_insieme(insieme_in);
    this->set_next(innext);
    this->set_prev(inprev);
    this->lista = nullptr ;
}

//overloading costruttore
template <typename I>
Cella<I>::Cella(Insieme* insieme_in){
    this->set_insieme(insieme_in);
    this->set_next(nullptr);
    this->set_prev(nullptr);
    this->lista = nullptr ;
}

//costruttore per inizializzare cella vuota
template <typename I>
Cella<I>::Cella(){
    this->set_insieme(nullptr);
    this->set_next(nullptr);
    this->set_prev(nullptr);
    this->lista = nullptr ;
}

//ritorna la lista di appartenenza
template <typename  I>
I* Cella<I>::get_lista() {
    return this->lista;
}


//------classe linked list---------------------
class Linked_List{
private:
    Cella<Linked_List>* testa;
    Cella<Linked_List>* coda;
public:
    void set_testa(Cella<Linked_List>* in);
    void set_coda(Cella<Linked_List>* in);
    Cella<Linked_List>* get_testa();
    Cella<Linked_List>* get_coda();
    void ins(Insieme* insieme_in);
    void del_insieme(Insieme* insieme_in);
    void del_cella(Cella<Linked_List>* cella_in);
    Linked_List();

};



#endif //PROGETTO_ASD_PROBLEMA_1_CELLA_H
