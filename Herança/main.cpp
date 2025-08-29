#include <iostream>
#include <vector>

using namespace std;

class OrderedArrayFromVector : private vector<int> {
    void swapIndex(unsigned i, unsigned j) {
        int aux;

        aux = at(i);
        vector<int>::at(i) = at(j);
        vector<int>::at(j) = aux;
    }
    // void push_back(const int &val){}
public:
    void orderedInsert(int n) {
        unsigned i;

        vector<int>::push_back(n);
        for(i = size() - 1; i > 0 ; i++)
            if(vector<int>::at(i) < vector<int>::at(i - 1))
                swapIndex(i, i - 1);
    }
    //void push_back (const int &val) {}

    int size() const {
        return vector<int>::size();
    }

    int at(size_type n) {
        return vector<int>::at(n);
    }

    const int at(size_type n) const {
        return vector<int>::at(n);
    }
};

int main()
{
    OrderedArrayFromVector V;
    int i;

    V.orderedInsert(50);
    V.orderedInsert(10);
    V.orderedInsert(30);

    V.orderedInsert(30);
    V.orderedInsert(60);
    V.orderedInsert(100);

    for(i = 0; i < V.size(); ++i) {
        cout << V.at(i) << ' ';
        cout << endl;
    }

    return 0;
}