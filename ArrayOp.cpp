#include <iostream>

using namespace std;

class ArrayOpIndex { 
    int V[10];
    int myMap;
    public:
        int operator [](unsigned index) {
            return V[index];
        }
        myMap.insert(p)
};

int main() {
    ArrayOpIndex A;
    unsigned i;
    for(i=0;i<10;i++)
        A[i] = i;
    
    for(i=0;i<10;i++)
        cout << A[i] << " ";

    return 0;

}