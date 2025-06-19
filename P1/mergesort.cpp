#include <iostream>

using namespace std;

void merge(int A[], int low, int high, int mid)
{
    int i, j, k, c[50];
    i = low;
    k = low;
    j = mid + 1;

    while (i <= mid && j <= high)
    {
        if (A[i] < A[j])
        {
            c[k] = A[i];
            k++;
            i++;
        }
        else
        {
            c[k] = A[j];
            k++;
            j++;
        }
    }
    while (i <= mid)
    {
        c[k] = A[i];
        k++;
        i++;
    }
    while (j <= high)
    {
        c[k] = A[j];
        k++;
        j++;
    }
    for (i = low; i < k; i++)
    {
        A[i] = c[i];
    }
}

void merge_sort(int A[], int low, int high)
{
    if( low < high) {
         
        int mid;

        mid = (low + high) / 2;

        merge_sort(A, low, mid);
        merge_sort(A, mid+1, high);

        merge(A, low, high, mid);
    }
}

int main()
{
    int length = 7;

    int A[7] = {38, 27, 43, 3, 9, 82, 10};

    int low = 0;
    int high = length - 1;

    merge_sort(A, low, high);

    for(int i = 0; i < length; i ++)
    {
        cout << A[i] << " ";
    }
    cout << endl << endl;

    return 0;
}