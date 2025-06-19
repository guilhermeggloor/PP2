#include <iostream>
#include <stdlib.h>
#include <string>
#include <cstring>
#include <stdio.h>
#include <memory>

#define MAX 10
using namespace std;

class DinamicArray
{
    // int V[MAX];
    int *V;
    unsigned arraySize;

public:
    DinamicArray(unsigned ArraySize = 10) : arraySize(arraySize),
                                            V(new int[arraySize])
    {
    } // a partir do momento que alocar um objeto de uma classe tem q usar o new,
    // para que o construtor e o destrutor seja chamado

    // const int *getV()    //Não faça isso
    // {
    //     return V;
    // }

    ~DinamicArray()
    {
        delete[] V;
    }

    void reserve(unsigned newArraySize)
    {
        int *vAux;

        if (newArraySize == 0)
            throw string("tamanho invalido");

        vAux = new int[newArraySize];
        memcpy(vAux, V, sizeof(int) * (arraySize < newArraySize ? arraySize : newArraySize));

        delete[] V;
        V = vAux;
        arraySize = newArraySize;
    }

    unsigned getArraySize()
    {
        return arraySize;
    }

    int getElementAt(unsigned i)
    {
        if (i >= MAX)
        {
            throw string("Acesso invalido de memória"); // Estudar sobre excessões
        }
        else
        {
            return V[i];
        }
    }

    void setElementAt(unsigned i, int element)
    {
        if (i >= MAX)
        {
            throw string("Acesso invalido de memoria");
        }
        else
        {
            V[i] = element;
        }
    }
};

int main()
{
    // string s1, s2("alguma coisa"), s3("outra coisa");
    // s1 = s2 + ' ' + s3;
    // cout << s1 << endl;

    // s1.c_str()[1] = 'u';

    // DinamicArray da;

    // try
    // {
    //     cout << da.getElementAt(10) << endl;
    // }
    // catch (char c)
    // {
    //     cout << endl
    //          << c << endl;
    // }
    // catch (...)
    // {
    //     cout << endl
    //          << "..." << endl;
    // }
    // DA.getV()[1] = 9;
    // cout << DA.getV()[1] << endl;

    // cout << da.getElementAt(9) << endl;

    // cout << "passou da exception" << endl;

    // printf(s1.c_str());

    DinamicArray da(2);
    int i;
    for (int i = 0; i < da.getArraySize(); i++)
        da.setElementAt(i, 0);
    da.reserve(4);

    for (int i = 0; i < da.getArraySize(); i++)
    {
        cout << da.getElementAt(i) << ' ';
        da.setElementAt(i, 1);
    }
    cout << endl;
    da.reserve(2);
    for (int i = 0; i < da.getArraySize(); i++)
        cout << da.getElementAt(i) << ' ';
    cout << endl;

    system("pause");
    return 0;
}