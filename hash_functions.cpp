//
// Created by daniele lubrano on 11/02/2020.
//

/*funzioni hash*/
#ifndef HASH_FUNCTIONS
#define HASH_FUNCTIONS

#include <cmath>
#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <fstream>
#include "hash.h"
#include "disjointset.h"
#include "Cella.h"

using namespace std;

//qui funzione hash moltiplicazione
int metodo_divisione(int key, int m){
    int k = m;
    return  key % k;
};

//qui funzione hash divisione
int metodo_moltiplicazione(int key, int m){
    //stabilire A
    float A =(sqrt(5)-1)/2;
    float result = key * A;
    result = result -int(result);
    return m * result;;

};

//funzione per verifica se numero primo
bool is_primo(int n){
    int meta = n/2;
    for(int k=2;k<= meta;k++){
        if(n%k == 0){
            return false;
        }
    }
    return true;
}

//funzione per la ricerca del numero primo più vicino ad m ma lontano da 2^k
int ricerca_estremi(int m){
    int m_0=m;
    int t=m;
    int e1=2,e2=2;
    bool res1 =false, res2 = false;
    //ricerca potenza del due inferiore
    while((pow(2,e1))< m){
        e1++;
    }
    e2 = e1;
    e1--;

    //ricerca numero primo
    while(!res1 || !res2){

        res1 = is_primo(m);
        res2 = is_primo(t);
        t++;
        m--;
    }
    t--;
    m++;


    //inserire un controllo che determini il numero primo giusto
    if( (e2-t) > (m-e1)){

        return t;
    }
    else{

        return m;
    }




};

//inizializzare caso nel main a 0
//alla prima chiamata inserendo il numero di elementi che si avranno in input
//restituisce l indice max con cui poi inizilizzare array
//funzione per ottenere l'indice hash

int Hash_Table::get_hash_index( int key){
    int indice=0,caso=0;
    srand (time(NULL));


    //se caso == 0 non ho ma determinato la funzione hash
    if( this->metodo_hashing == "null"){
        //genero un numero random tra 1 e 2
        int b = rand()%2+1;

        if(b == 1){
            this->metodo_hashing = "divisione";
            //m temporaneo
            this->m = key / 3;
            this->m = ricerca_estremi(m);
        }
        else{
            this->metodo_hashing = "moltiplicazione";
            int k=2,potenza=pow(2,k);
            //m nella divisione
            while (potenza < key) {
                k++;
                potenza = pow(2,k);
            }
            this->m=pow(2,--k);
        }
    }
    if(this->metodo_hashing == "divisione"){
        caso=1;
    } else{
        caso=2;
    }

    switch(caso){
        case 1:
            //prima funzione HASH divisione
            indice = metodo_divisione(key,m);
            //cout<<"indice prodotto da divisione: "<<indice<<endl;

            break;

        case 2:
            //seconda funzione hash moltiplicazione
            indice = metodo_moltiplicazione(key,m);
            //cout<<"indice proddotto da moltiplicazione: "<<indice<<endl;
            break;
    }

    return indice;

}

//----------funzione per leggere da file e ottenere l'input--------------------------

bool Hash_Table::get_input_from_file(){

    fstream file;
    string line, value;
    int indice_virgola,key, contatore=0;

    file.open(this->nome_file);

    if(file.fail()){
        cout<<"file non trovato"<<endl;
        return false;
    }

    //conto numero di elementi per poi stabilire m in hash
    while(getline(file,line)){
        contatore++;
    }

    //stabilisco il numero di elementi massimo
    this->numero_elementi_input = contatore;

    //resetto puntatore a file
    file.clear();
    file.seekg(0,ios::beg);

    // ottiene indice hash max e inizializza ''m''
    get_hash_index(this->numero_elementi_input);

    //inizializzo vettore sufficientemente grande a contenere tutto con indice generato da funzione hash
    for (int i=0;i<this->m;i++){
        //inserisce linked list vuote per allocare spazio
        vettore.push_back(Linked_List());
    }

    //prelevo linee e inserisco in vettore
    while(getline(file,line)){
        //rilevo lo spazio di mezzo a key e value_in

        indice_virgola  = line.find(',');

        //ottengo la key
        key = stoi(line.substr(0,indice_virgola));

        //ottengo la stringa
        value = line.substr(++indice_virgola);

        //inserisco dati
        try{
            this->insert(key,value);
        }
        catch (exception e){
            cout<<endl;
            cout<<"--errore  in inserimento dati "<<e.what()<<endl;
            cout<<endl;
        }


    }

    file.close();
    return true;

}
//------------------------------------------------------------------------------------

//costruttore

Hash_Table::Hash_Table( string nome_file_in){

    this->nome_file  =nome_file_in;
    this->metodo_hashing = "null";
    this->numero_elementi_input=0;
    this->m=0;

    //legge dal file
    try{
        get_input_from_file();

    }
    catch(...){
        cout<<"errore in input da file"<<endl;
    }
    cout<<"capacity: "<<this->vettore.capacity()<<endl;
}

void Hash_Table::PrintOut(){
    //iteratore per scorrere il vettore
    vector <Linked_List>::iterator iteratore = vettore.begin();
    while(iteratore != vettore.end()){
        Cella* itr_cella = iteratore->get_testa();
        //itero le celle all'interno della linked list
        while(itr_cella != nullptr){

            Nodo<Insieme>* itr;
            itr  = itr_cella->get_insieme()->get_head();

            cout<<itr->get_key()<<" - ";
            itr_cella = itr_cella->get_next();

        }
        cout<<endl;
        iteratore++;
    }
}


void Hash_Table::insert(int key, string value ){

    //creo l'oggetto insieme con i dati appena estratti
    //e inserisco nell'oggetto linked lsit
    //il quale si occupa di trovare la giusta locazione per tali dati
    this->vettore.at(get_hash_index(key)).ins(new Insieme (key,value));

}
//ricerca del key-value nella tavola
Insieme* Hash_Table::research(int key, string value ){

    //iteratore per scorrere il vettore
    vector <Linked_List>::iterator iteratore = vettore.begin();
    while(iteratore != vettore.end()){
        Cella* itr_cella = iteratore->get_testa();

        //itero le celle all'interno della linked list
        while(itr_cella != nullptr){

            Nodo<Insieme>* itr;
            itr  = itr_cella->get_insieme()->get_head();

            //nel momento dell'occorrenza esce e ritorna il ptr all insieme
            if(itr->get_key() == key && itr->get_value() == value){
                cout<<"trovato"<<endl;
                return itr->get_insieme();
            }
            itr_cella = itr_cella->get_next();
        }

        iteratore++;
    }
}


Insieme* Hash_Table::make_set(int key, string value){
    //inserisco l'insieme nella Cella nell'indice del vettore generato
    return new Insieme(key,value);
}

void Hash_Table::callable_find_set(int key, string value){
    Insieme* ptr = this->research(key,value);
    cout<<"Il rappresentante dell'insieme è il nodo di key: "<<ptr->get_head()->get_key()<<" e di value :"<<ptr->get_head()->get_value()<<endl;

};


#endif
