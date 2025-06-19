#include <iostream>

using namespace std;

template <typename T, typename U>
T f(T a, U b, int i){
    T aux;
    U auxU;
    return a+b;

}
template <typename T>
void ordena(T V[], unsigned n)
{
    // unsigned i, j;
    // for(int i=1; i<n; i++) {
    //     if(V[i]>V[i +1]) {
    //         T tmp = V[i];
    //         V[i] = V[i+1];
    //         V[i+1] = tmp;
    //     }
    // }    

    // unsigned i, j, aux, menor;
    // for(i = 0; i < n-1; i++) {
    //     menor = i;
    //     for(j=i+1; j < n; ++j)
    //         if(V[menor]>V[j])
    //             menor = j;
    //     aux = V[i];
    //     V[i] = V[menor];
    //     V[menor] = aux;
    // }

    T *pi, *pj, *pmenor;
    T aux;
    
    for(pi = V; pi < V+(n-1); ++pi) {
        pmenor = pi;
        for(pj=pi+1; pj < V+n; ++pj)
            if(*pmenor > *pj)
                pmenor = pj;
        aux = *pi;
        *pi = *pmenor;
        *pmenor = aux;
    }
    


}

int main() {

    int V[] = {3, 1, 6, 8, 4, 9, 2, 25, 12, 13, 17};
    int i;

    ordena(V, 11);
    for(i = 0; i < 11; i++)
    {
        cout << V[i] << ' ';
    }

}