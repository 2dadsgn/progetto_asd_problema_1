#ifndef HEADER
#define HEADER


using namespace std;

int metodo_moltiplicazione(int key, int m);

//classe padre generica per nodo o cella
template <typename I>
class GeneralNode{
private:
    I* insieme;
    GeneralNode* next;
public:
    GeneralNode* get_next();
    void set_next(GeneralNode* input);
    void set_insieme(I* input);
    I* get_insieme();
};


template <class I>
GeneralNode<I>* GeneralNode<I>::get_next(){
    return this->next;
}
template <class I>
void GeneralNode<I>::set_next(GeneralNode<I>* input){
    this->next = input;
}
template <class I>
void GeneralNode <I>::set_insieme(I* input){
    this->insieme = input;
}
template <class I>
I* GeneralNode <I>::get_insieme(){
    return  this->insieme;
}


#endif
