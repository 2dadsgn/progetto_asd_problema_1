//
// Created by daniele lubrano on 11/02/2020.
/*class per la creazione e gestione della hash table*/
//

#ifndef PROGETTO_ASD_PROBLEMA_1_HASH_H
#define PROGETTO_ASD_PROBLEMA_1_HASH_H


#include "disjointset.h"
#include "Cella.h"
#include <string>
#include <vector>
#include <iostream>


using namespace std;

//classe hash con cui gestire la creazione della funzione hash
// e l'inserimento degli elementi

class Hash_Table{
    //sostituire insieme  con tipo Cella
    vector <Cella<Insieme>*> vettore;
    string metodo_hashing;         //variabile per memorizzare il metodo hashing utilizzato
    int m;                         //m per il calcolo dell'indice
    string nome_file;
    int numero_elementi_input;


public:
    bool get_input_from_file();
    int get_hash_index( int key);
    Hash_Table(string nome_file);

    void get_used_memory();

    template  <typename I>
    void make_set(int key, string value);
    void union_nodes(int key, int key2);
    Insieme* find_set(int key);

};


template  <typename I>
void Hash_Table::make_set(int key, string value){
    //inserisco l'insieme nella Cella nell'indice del vettore generato
    this->vettore.at(get_hash_index(key)) = new Cella<I>(new Insieme(key,value));
}




#endif //PROGETTO_ASD_PROBLEMA_1_HASH_H
