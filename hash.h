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

    Cella<Linked_List>* research(int key, string value);

    int ricerca_estremi(int m);

    bool is_primo(int n);

    int metodo_moltiplicazione(int key, int m);

    int metodo_divisione(int key, int m);

    //legge il file contenuto nella variabile nome_file
    bool get_input_from_file();

    //tramite la key inserita genera l indice scegliendo una funzione hash random
    int get_hash_index( int key);

    void union_nodes(Insieme* s1, Insieme* s2);
    Nodo<Insieme>* find_set(Insieme* s1);

public:

    //costruttore
    Hash_Table(string nome_file);

    //funzioni insiemi disgiunti
    Insieme* make_set(int key, string value);

    //view hash table
    void PrintOut();

    //funzione pubblica di findset
    void callable_find_set(int key, string value);

    void callable_union(int key1, string value1, int key2, string value2);
    void callable_make_set(int key, string value);

    void menu();

    //stampa l'insieme
    void print_insieme();
};




#endif //PROGETTO_ASD_PROBLEMA_1_HASH_H
