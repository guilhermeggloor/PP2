#include<iostream>

#if !defined nullptr
#define nullptr 0
#endif

using namespace std;
template <class T>
class DNo{
    T key;
    DNo<T> *next;
    public:
        DNo(T key = 0, DNo<T> *next = nullptr):
        key(key),
        next(next)
        {}
        T& getKey(){
            return key;
        }
        DNo<T>*& getNext(){
            return next;
        }
        void setKey(T key){
            this->key = key;
        }
        void setNext(DNo<T> *next){
            this->next=next;
        }
};
template <class T>
class DFIFO{
    DNo<T> *ptr;
    public:
        DFIFO() : ptr(nullptr)
        {}
        void insert(T key){
            DNo<T> **ppAux;
            ppAux = &ptr;
            while(*ppAux !=nullptr)
                ppAux = &(*ppAux)->getNext();
            (*ppAux) = new DNo<T>(key);
        }
        bool isEmpty() const{
            return ptr == nullptr;
        }
        T remove(){
            DNo<T>* pAux;
            T retKey = 0;
            if(ptr != nullptr){
                pAux = ptr;
                ptr = ptr->getNext();
                retKey = pAux->getKey();
                delete pAux;
            }
            return retKey;
        }
        T& operator[](unsigned i){
            DNo<T> *pAux;
            pAux = ptr;
            while(i>0){
                pAux = pAux->getNext();
                --i;
            }
            pAux->getKey();
        }
        const DFIFO<T>& operator =(const DFIFO<T> &other){
            DNo<T> **ppAuxThis,*pAuxOther;
            pAuxOther = other.ptr;
            ppAuxThis = &ptr;
            while(pAuxOther!=nullptr){
                (*ppAuxThis) = new DNo<T>(pAuxOther->getKey());
                pAuxOther = pAuxOther->getNext();
                ppAuxThis = &(*ppAuxThis)->getNext();
            }
            return *this;
        }
        ~DFIFO(){
            DNo<T> *pAux;            
            while(ptr!=nullptr){
                pAux = ptr;
                ptr = ptr->getNext();
                delete pAux;
            }
        }
};

int main(){
    DFIFO<int> fifo,fifo2;
    int i;

    for(i=0;i<5;++i)
        fifo.insert(i);

    for(i=0;i<5;++i)
        cout<<fifo[i]<<' ';
    cout<<endl;

    fifo2 = fifo;

    fifo2[2] = 9;

    while(!fifo.isEmpty())
        cout<<fifo.remove()<<' ';
    cout<<endl;

    while(!fifo2.isEmpty())
        cout<<fifo2.remove()<<' ';
    cout<<endl;
    return 0;
}