//
// Created by daniele lubrano on 13/02/2020.
//

#ifndef PROGETTO_ASD_PROBLEMA_1_CELLA_H
#define PROGETTO_ASD_PROBLEMA_1_CELLA_H

#include "header.h"
#include "disjointset.h"
template  <typename I>
class Cella: public GeneralNode<I>{
private:
    Cella* prev;
public:
    void set_prev(Cella* cella_in);
    Cella* get_prev();

    Cella(Insieme* insieme_in);
};
#endif //PROGETTO_ASD_PROBLEMA_1_CELLA_H
