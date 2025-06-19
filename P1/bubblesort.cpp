#include <iostream>

using namespace std;

int main()
{
    // aqui vai ordenar o array, vamos usar bubble sort para isso
            //  0 1 2 3 4 5 6 7 8 9 
    int a[] = { 4,1,5,8,9,0,2,7,3,6};

    int lenght = 10;

    for(int i = 0; i < lenght; i++)
    {
        for(int j = 0; j < lenght - 1; j++)
        {
            if(a[j] > a[j + 1])
            {
                int temp = a[j];
                a[j] = a[j+1];
                a[j + 1] = temp;
            }
        }
    }

    for(int i = 0; i < lenght; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl << endl;

    return 0;
}