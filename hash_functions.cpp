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
int Hash_Table::metodo_divisione(int key, int m) {
    int k = m;
    return key % k;
};

//qui funzione hash divisione
int Hash_Table::metodo_moltiplicazione(int key, int m) {
    //stabilire A
    float A = (sqrt(5) - 1) / 2;
    float result = key * A;
    result = result - int(result);
    return m * result;;

};

//funzione per verifica se numero primo
bool Hash_Table::is_primo(int n) {
    int meta = n / 2;
    for (int k = 2; k <= meta; k++) {
        if (n % k == 0) {
            return false;
        }
    }
    return true;
}

//funzione per la ricerca del numero primo più vicino ad m ma lontano da 2^k
int Hash_Table::ricerca_estremi(int m) {
    int m_0 = m;
    int t = m;
    int e1 = 2, e2 = 2;
    bool res1 = false, res2 = false;
    //ricerca potenza del due inferiore
    while ((pow(2, e1)) < m) {
        e1++;
    }
    e2 = e1;
    e1--;

    //ricerca numero primo
    while (!res1 || !res2) {

        res1 = this->is_primo(m);
        res2 = this->is_primo(t);
        t++;
        m--;
    }
    t--;
    m++;


    //inserire un controllo che determini il numero primo giusto
    if ((e2 - t) > (m - e1)) {

        return t;
    } else {

        return m;
    }


};


//alla prima chiamata inserendo il numero di elementi che si avranno in input
//restituisce l indice max con cui poi inizilizzare array
//funzione per ottenere l'indice hash

int Hash_Table::get_hash_index(int key) {
    int indice = 0, caso = 0;
    srand(time(NULL));

    //se caso == null non ho mai determinato la funzione hash
    if (this->metodo_hashing == "null") {
        //genero un numero random tra 1 e 2
        int b = rand() % 2 + 1;

        if (b == 1) {
            this->metodo_hashing = "divisione";
            //m temporaneo
            this->m = key / 3;
            this->m = this->ricerca_estremi(m);
        } else {
            this->metodo_hashing = "moltiplicazione";
            int k = 2, potenza = pow(2, k);
            //m nella divisione
            while (potenza < key) {
                k++;
                potenza = pow(2, k);
            }
            this->m = pow(2, --k);
        }
    }
    if (this->metodo_hashing == "divisione") {
        caso = 1;
    } else {
        caso = 2;
    }

    switch (caso) {
        case 1:
            //prima funzione HASH divisione
            indice = this->metodo_divisione(key, m);
            //cout<<"indice prodotto da divisione: "<<indice<<endl;

            break;

        case 2:
            //seconda funzione hash moltiplicazione
            indice = this->metodo_moltiplicazione(key, m);
            //cout<<"indice proddotto da moltiplicazione: "<<indice<<endl;
            break;
    }

    return indice;

}

//----------funzione per leggere da file e ottenere l'input--------------------------

bool Hash_Table::get_input_from_file() {

    fstream file;
    string line, value;
    int indice_virgola, key, contatore = 0;

    file.open(this->nome_file);

    if (file.fail()) {
        cout << "file non trovato" << endl;
        return false;
    }

    //conto numero di elementi per poi stabilire m in hash
    while (getline(file, line)) {
        contatore++;
    }

    //stabilisco il numero di elementi massimo
    this->numero_elementi_input = contatore;

    //resetto puntatore a file
    file.clear();
    file.seekg(0, ios::beg);

    // ottiene indice hash max e inizializza ''m''
    get_hash_index(this->numero_elementi_input);

    //inizializzo vettore sufficientemente grande a contenere tutto con indice generato da funzione hash
    for (int i = 0; i < this->m; i++) {
        //inserisce linked list vuote per allocare spazio
        vettore.push_back(Linked_List());
    }

    //prelevo linee e inserisco in vettore
    while (getline(file, line)) {
        //rilevo lo spazio di mezzo a key e value_in

        indice_virgola = line.find(',');

        //ottengo la key
        key = stoi(line.substr(0, indice_virgola));

        //ottengo la stringa
        value = line.substr(++indice_virgola);

        //inserisco dati
        try {
            this->insert(key, value);
        }
        catch (exception e) {
            cout << endl;
            cout << "--errore  in inserimento dati " << e.what() << endl;
            cout << endl;
        }


    }

    file.close();
    return true;

}
//------------------------------------------------------------------------------------

//costruttore

Hash_Table::Hash_Table(string nome_file_in) {

    this->nome_file = nome_file_in;
    this->metodo_hashing = "null";
    this->numero_elementi_input = 0;
    this->m = 0;

    //legge dal file
    try {
        get_input_from_file();

    }
    catch (...) {
        cout << "errore in input da file" << endl;
    }
    cout << "capacity: " << this->vettore.capacity() << endl;
}

//funzione per stampa della hash table
void Hash_Table::PrintOut() {
    //iteratore per scorrere il vettore
    vector<Linked_List>::iterator iteratore = vettore.begin();
    while (iteratore != vettore.end()) {
        Cella<Linked_List> *itr_cella = iteratore->get_testa();
        //itero le celle all'interno della linked list
        while (itr_cella != nullptr) {

            Nodo<Insieme> *itr;
            itr = itr_cella->get_insieme()->get_head();

            cout << itr->get_key() << " - ";
            itr_cella = itr_cella->get_next();

        }
        cout << endl;
        iteratore++;
    }
}

//funzione per stampare imsieme disgiunto
void Hash_Table::print_insieme() {
    string value;
    int indice;
    cout << "inserire la key e value separati da una virgola" << endl;
    cin >> value;
    indice = value.find(',');
    Cella<Linked_List> * cursore = this->research(stoi(value.substr(0,indice)),value.substr(indice+1));
    if(cursore == nullptr){
        cout<<"tupla non trovata"<<endl;
    }
    else{
        Nodo<Insieme>* itr_nodi = cursore->get_insieme()->get_head();
        while(itr_nodi != nullptr){
            cout<<itr_nodi->get_key()<<endl;
            itr_nodi = itr_nodi->get_next();
        }
    }

}

// funzione per inserimento in hash table
void Hash_Table::insert(int key, string value) {

    //creo l'oggetto insieme con i dati appena estratti
    //e inserisco nell'oggetto linked lsit
    //il quale si occupa di trovare la giusta locazione per tali dati
    this->vettore.at(get_hash_index(key)).ins(this->make_set(key, value));

}

//ricerca del key-value nella tavola
Cella<Linked_List> *Hash_Table::research(int key, string value) {

    //iteratore per scorrere il vettore
    vector<Linked_List>::iterator iteratore = vettore.begin();
    while (iteratore != vettore.end()) {
        Cella<Linked_List>* itr_cella = iteratore->get_testa();

        //itero le celle all'interno della linked list
        while (itr_cella != nullptr) {
            Nodo<Insieme> *itr;
            itr = itr_cella->get_insieme()->get_head();

            //itero i nodi
            while(itr != nullptr){
                //nel momento dell'occorrenza esce e ritorna il ptr all insieme
                if (itr->get_key() == key && itr->get_value() == value) {
                    cout << "ricerca con successo" << endl;
                    return itr_cella;
                }
                //iteratore per i nodi dell insieme
                itr = itr->get_next();
            }
            //iteratore della lista per le celle
            itr_cella = itr_cella->get_next();
        }
        //incremento iteratore del vettore
        iteratore++;
    }

    return nullptr;
}

//make set per creazioen insiemi disgiunti
Insieme *Hash_Table::make_set(int key, string value) {
    //inserisco l'insieme nella Cella nell'indice del vettore generato
    return new Insieme(key, value);
}

//make set richiamabile esternamente inserisce nuovi insiemi al difuori del file.txt
void Hash_Table::callable_make_set(int key, string value) {
    //inserisco l'insieme nella Cella nell'indice del vettore generato
    this->insert(key, value);
}

//findset privata che ritorna l'oggetto
Nodo<Insieme> *Hash_Table::find_set(Insieme *s1) {
    return s1->get_head();
}

//funzione richiamabile esternamente della classe hash table che stampa il rappresentante
void Hash_Table::callable_find_set(int key, string value) {

    //effettuo ricerca
    Cella<Linked_List> *ptr = this->research(key, value);

    if (ptr == nullptr) {
        cout << "elemento non trovato" << endl;
    } else {
        cout << "Il rappresentante dell'insieme "<<ptr->get_insieme() <<" è il nodo di key: " << ptr->get_insieme()->get_head()->get_key()
             << ", e di value: " << ptr->get_insieme()->get_head()->get_value() << " memorizzato all'indirizzo: " << ptr
             <<endl;
    }

};

void Hash_Table::callable_union(int key1, string value1, int key2, string value2) {
    Cella<Linked_List> *c1 = this->research(key1, value1);
    Cella<Linked_List> *c2 = this->research(key2, value2);
    if (c1 == nullptr || c2 == nullptr) {
        //se uno dei due insiemi non è stato trovato
        cout<<"la ricerca non ha prodotto alcun risulato"<<endl;
    } else if (c1 == c2){
        //se gli insiemi sono stati già uniti
        cout<<"Le due tuple sono state già unite"<<endl;
    }
    else {
        Insieme *s1 = c1->get_insieme();
        Insieme *s2 = c2->get_insieme();
        Nodo<Insieme> *ptr;

        //se rango s1 > rango s2
        if (s1->get_rank() > s2->get_rank()) {
            //concateno i due insiemi
            s1->get_tail()->set_next(s2->get_head());


            //la nuova coda dell'insieme
            s1->set_tail(s2->get_tail());


            //i nuovi elementi devono puntare all'insieme s1
            ptr = s2->get_head();
            while (ptr != nullptr) {
                ptr->set_insieme(s1);
                ptr = ptr->get_next();
            }

            //elimino cella ed insieme s2
            c2->get_lista()->del_cella(c2);

            cout << "Unito " << s2->get_head()->get_key() << " a " << s1->get_head()->get_key() << endl;

        } else {
            //concateno i due insiemi
            s2->get_tail()->set_next(s1->get_head());

            //la coda di s2 diventa la coda di s1
            s2->set_tail(s1->get_tail());

            //i nuovi elementi devono puntare all'insieme s1
            ptr = s1->get_head();
            while (ptr != nullptr) {
                ptr->set_insieme(s2);
                ptr = ptr->get_next();
            }

            //aumento rank di s2
            s2->set_rank(s2->get_rank() + 1);


            //elimino cella ed insieme s2
            c1->get_lista()->del_cella(c1);

            cout << "Unito " << s1->get_head()->get_key() << " a " << s2->get_head()->get_key() << endl;

        }

    }



    //ricordarsi di eliminare anche la cella in cui si trovava l'insieme
}

void Hash_Table::menu() {

    int scelta, indice, indice1;
    string value, value1;

    while (scelta != 0) {
        cout << "Scegliere dal menu l'azione" << endl << "- 0 - Per terminare il programma" << endl
             << "- 1 - Esegue la findset su input" << endl << "- 3 - Esegue la union" <<endl<<
             "- 4 - Stampa un determinato insieme"<< endl;

        cin >> scelta;
        switch (scelta) {
            case 1:
                cout << "inserire la key e value separati da una virgola" << endl;
                cin >> value;
                indice = value.find(',');
                try {
                    this->callable_find_set(stoi(value.substr(0, indice)), value.substr(indice + 1));
                }
                catch (...) {
                    cout << "errore in findSet" << endl;
                }
                break;
            case 2:
                cout << "inserire la key e value separati da una virgola" << endl;
                cin >> value;
                indice = value.find(',');
                try {
                    this->callable_make_set(stoi(value.substr(0, indice)), value.substr(indice + 1));
                }
                catch (...) {
                    cout << "errore in makeSet" << endl;
                }
                break;
            case 3:
                cout << "inserire la key e value separati da una virgola" << endl;
                cin >> value;
                indice = value.find(',');

                cout << "inserire la seconda key e value separati da una virgola" << endl;
                cin >> value1;
                indice1 = value1.find(',');

                try {
                    cout<<"Effettuo Union su: "<<stoi(value.substr(0, indice))<<" "<< value.substr(indice + 1)<<" , "<<
                            stoi(value1.substr(0, indice1))<<" "<< value1.substr(indice1 + 1)<<endl;
                    this->callable_union(stoi(value.substr(0, indice)), value.substr(indice + 1),
                                         stoi(value1.substr(0, indice1)), value1.substr(indice1 + 1));
                }
                catch (...) {
                    cout << "errore in Union" << endl;
                }
                break;
            case 4:
                this->print_insieme();
                break;
        }
        cout << endl << endl << endl;
    }
}

#endif
