#include <iostream>
#include <cstdlib>
#include <string>
#include <cstdio>
#include <cstring>
using namespace std;

template <class T = int>
class DDinamicArray{
    T *V;
    unsigned arraySize;
    unsigned numElem;
    
    void reserve(unsigned newArraySize){
        T *vAux;

        if(newArraySize == 0) throw string("tamanho inv�lido");

        vAux = new T[newArraySize];
        memcpy(vAux,V,sizeof(T)*
               (arraySize < newArraySize ? arraySize : newArraySize)
              );
        delete [] V;
        V = vAux;
        arraySize = newArraySize;
    }
    void elem_swap(const unsigned &i,const unsigned &j){
        T aux;
        aux = V[i];
        V[i] = V[j];
        V[j] = aux;
    }
public:
    DDinamicArray(unsigned arraySize=2):
        arraySize(arraySize),
        V(new T[arraySize]),
        numElem(0)
    {}
    ~DDinamicArray(){
        delete [] V;
    }
    unsigned getNumElem() const{
        return numElem;
    }
    void insert(T elem){
        unsigned i;
        //Verificar se Array está cheio
        if(numElem==arraySize)
            reserve(2*arraySize);
        //Insere elemento na ultima posição
        V[numElem++] = elem;
        //reordena array
        for(i=numElem-1;i>0;--i)
            if(V[i]<V[i-1])
                elem_swap(i,i-1);
    }
    bool removeFromKey(T elem){
        unsigned i;
        for(i=0;i<numElem;++i)
            if(V[i] == elem)
                break;

        if(i==numElem)
            return false;

        for(  ;i<numElem-1;++i)
            V[i] = V[i+1];
        --numElem;
        //Verificar se 3/4 do array está vazio
        if(numElem <= arraySize/4)
            reserve(arraySize/2);

        return true;
    }
    T operator [](unsigned i) const{
        return V[i];
    }
    const DDinamicArray<T>& operator = (const DDinamicArray<T> &other){       
        reserve(other.arraySize);
        memcpy(V,other.V,sizeof(T)*other.numElem);
        numElem = other.numElem;

        return *this;
    }
};

int main()
{   
    DDinamicArray<> obj1,obj2;
    int i;

    obj1.insert(3);
    obj1.insert(1);
    obj1.insert(6);
    obj1.insert(2);
    obj1.insert(9);

    for(i=0;i<obj1.getNumElem();++i)
        cout<<obj1[i]<<' ';
    cout<<endl;

    obj2 = obj1;

    for(i=0;i<obj2.getNumElem();++i)
        cout<<obj2[i]<<' ';
    cout<<endl;

    //obj1.removeFromKey(9);
    obj1.removeFromKey(1);
    //obj1.removeFromKey(3);

    for(i=0;i<obj1.getNumElem();++i)
        cout<<obj1[i]<<' ';
    cout<<endl;

    for(i=0;i<obj2.getNumElem();++i)
        cout<<obj2[i]<<' ';
    cout<<endl;
    return 0;
}






