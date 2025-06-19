#include <iostream>

#if !defined nullptr
#define nullptr 0
#endif

using namespace std;

template <class T>
class No {
    T chave;
    No<T> *prox;
public: 
    No(T chave, No<T> *prox = nullptr):
        chave(chave), prox(prox)
    {}
    T& getChave() {
        return chave;
    }
    No<T>*& getProx() {
        return prox;
    }
    
    void setChave(T chave) {
        this->chave = chave;
    }
    void setProx(No<T> *prox) {
        this->prox = prox;
    }
}; 

template <class T>
class FIFO {
    No<T> *pt;
public:
    FIFO(): pt(nullptr)
    {}
    void insert(T chave) {
        No<T> **pAux;
        pAux = &pt;
        while(*pAux != nullptr)
            pAux = &(*pAux)->getProx();
        (*pAux) = new No<T>(chave);
    }
    bool isVazio() const {
        return pt == nullptr;
    }

    T remove() {
        No<T>* Aux;
        T retChave = 0;
        if(pt != nullptr) {
            Aux = pt;
            pt = pt->getProx();
            retChave = Aux->getChave();
        }
        return retChave;
    }

    T& operator[](unsigned i) {
        No<T> *Aux;
        Aux = pt;
        while(i>0) {
            Aux = Aux->getProx();
            --i;
        }
        Aux->getChave();
    }
    const FIFO<T>& operator =(const FIFO<T> &other) {
        No<T> **pAuxThis, *pAuxOther;
        pAuxOther = other.pt;
        pAuxThis = &pt;

        while(pAuxOther != nullptr) {
            (*pAuxThis) = new No<T>(pAuxOther->getChave());
            pAuxOther = pAuxOther->getChave();
            pAuxThis = &(*pAuxThis)->getChave();
        }
        return *this;
    }
    ~FIFO() {
        No<T> *Aux;
        while(pt != nullptr) {
            Aux = pt;
            pt = pt->getChave();
            delete Aux;
        }
    }
};

int main()
{
    FIFO<int> a, b;
    int i;

    for(i = 0; i < 5; i++) {
        a.insert(i);
    }

    for(i=0;i<5;++i)
        cout<<a[i]<<' ';
    cout<<endl;

    return 0;
}