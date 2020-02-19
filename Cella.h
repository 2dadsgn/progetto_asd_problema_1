//
// Created by daniele lubrano on 13/02/2020.
/*la classe linked list gestisce la classe cella */
//

#ifndef PROGETTO_ASD_PROBLEMA_1_CELLA_H
#define PROGETTO_ASD_PROBLEMA_1_CELLA_H

#include "header.h"
#include "disjointset.h"



class Cella{
private:
    Insieme* insieme;
    Cella* prev;
    Cella* next;
public:
    void set_prev(Cella* cella_in);
    Cella* get_prev();
    Cella* get_next();
    void set_next(Cella* input);
    void set_insieme(Insieme* insieme_in);
    Insieme* get_insieme();

    Cella(Insieme* insieme_in);

    Cella(Insieme* insieme_in, Cella* inprev, Cella* innext);

    //costruttore per inizializzare cella vuota
    Cella();
};

class Linked_List{
private:
    Cella* testa;
    Cella* coda;
public:
    void set_testa(Cella* in);
    void set_coda(Cella* in);
    Cella* get_testa();
    Cella* get_coda();
    void ins(Insieme* insieme_in);
    void del(Insieme* insieme_in);
    Linked_List();

};



#endif //PROGETTO_ASD_PROBLEMA_1_CELLA_H
