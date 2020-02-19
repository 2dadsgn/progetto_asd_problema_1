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
private:
    vector <Linked_List> vettore;
    string metodo_hashing;         //variabile per memorizzare il metodo hashing utilizzato
    int m;                         //m per il calcolo dell'indice
    string nome_file;
    int numero_elementi_input;

    void insert(int key, string value);

    Insieme* research(int key, string value);

    //legge il file contenuto nella variabile nome_file
    bool get_input_from_file();

    //tramite la key inserita genera l indice scegliendo una funzione hash random
    int get_hash_index( int key);

    void union_nodes(int key, int key2);
    Insieme* find_set(int key);

public:

    //costruttore
    Hash_Table(string nome_file);

    //funzioni insiemi disgiunti
    Insieme* make_set(int key, string value);

    //view hash table
    void PrintOut();

    //funzione pubblica di findset
    void callable_find_set(int key, string value);
};




#endif //PROGETTO_ASD_PROBLEMA_1_HASH_H
