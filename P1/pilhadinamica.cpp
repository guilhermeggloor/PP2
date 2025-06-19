#include <iostream>
#include <memory>
#include <cstring>

using namespace std;

template <class T>
class DStack{
    unique_ptr<T> ptr;
    unsigned topIndex;
    unsigned capacity;

    void reserve(unsigned capacity){
        unique_ptr<T> pAux;

        //verificar se o novo capacity � maior que
        if(! (capacity>0))
            capacity = 1;

        //alocar novo array em pAux
        pAux.reset(new T[capacity]);

        //copiar o array de ptr p/ pAux
        memcpy(pAux.get(),ptr.get(),topIndex * sizeof(T));

        //fazer ptr paontar para p/ pAux
        ptr.swap(pAux);
        this->capacity = capacity;
    }

public:
    DStack(unsigned capacity = 2):
        topIndex(0),
        capacity(capacity),
        ptr(new T[capacity])
        {}
    //restorna o elemento que esta no topo da pilha
    T top() const{
        return *(ptr.get()+topIndex-1);
    }
    //insere elemento no topo da pilha
    void push(T elem){
        //se a pilha esta cheia, ent�o alocar mais espa�o
        if(capacity == topIndex)
            reserve(capacity*2);

        //inseri elementos
        *(ptr.get()+topIndex) = elem;
        ++topIndex;
    }
    bool pop(){
        //se pilha vazia ent�o retorne falso
        if(topIndex == 0)
            return false;

        //remover elemento da pilha
        --topIndex;

        //se capacidade * 3/4 > topIndex, ent�o reduzir o tamanho do array
        if(capacity * 3/4 > topIndex)
            reserve(capacity/2);

        //return verdadeiro
        return true;
    }
};

int main()
{
    DStack<int> myStack;
    int i;

    for(i=0;i<4;++i)
        myStack.push(i);

    for(i=0;i<4;++i){
        cout<<myStack.top()<<' ';
        myStack.pop();
    }
    cout<<endl;

    return 0;
}



