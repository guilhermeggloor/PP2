#include <iostream>

using namespace std;

void insertion_sort(int a[], int lenght);

int main()
{
    int a[] = {8, 2, 7, 4, 5, 1, 9, 3};
    int lenght = 8;

    insertion_sort(a, lenght);

    for(int i = 0; i < lenght; i++)
    {
        cout << "a[" << i << "] = " << a[i] << endl;
    }

    return 0;
}

void insertion_sort(int a[], int length)
{

    for (int i = 1; i < length; i++)
    {
        int key = a[i];
        int j = i - 1;
        
        while( j >= 0 && a[j] > key)
        {
            a[j + 1] = a[j];
            j = j - 1;
        }
        a[j + 1] = key;


    }
}