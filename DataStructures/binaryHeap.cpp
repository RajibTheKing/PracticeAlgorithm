#include <iostream>
#include <cmath>
using namespace std;

int heapSize = 0;

void ShowArray(int A[], int len)
{
    for(int i=0; i<len; i++)
    {
        cout<<A[i]<<" ";
    }
    cout<<endl;
}

int PARENT (int i)
{
    return floor(i/2);
}
int LEFT(int i)
{
    return 2 * i;
}
int RIGHT(int i)
{
    return 2 * i + 1;
}

void MAX_HEAPIFY(int A[], int indx)
{
    int l = LEFT(indx);
    int r = RIGHT(indx);
    int largest;
    if (l < heapSize && A[l] > A[indx])
        largest = l;
    else
        largest = indx;

    if(r < heapSize && A[r] > A[largest])
        largest = r;
    
    if (largest != indx)
    {
        int temp = A[indx];
        A[indx] = A[largest];
        A[largest] = temp;
        MAX_HEAPIFY(A, largest);
    }
}


void BUILD_MAX_HEAP(int A[], int len)
{
    heapSize = len;
    for(int i = len - 1; i>=0; i--)
    {
        MAX_HEAPIFY(A, i);
    }
}

void HEAP_SORT(int A[], int len)
{
    BUILD_MAX_HEAP(A, len);
    heapSize = len;
    for(int i=len-1; i>=0; i--)
    {
        int temp = A[0];
        A[0] = A[i];
        A[i] = temp;
        heapSize = heapSize - 1;
        MAX_HEAPIFY(A, 0);
    }
    ShowArray(A, len);
}

int HEAP_EXTRACT_MAX(int A[])
{
    if (heapSize <= 0)
    {
        cout<<"No values"<<endl;
        return INT32_MIN;
    }
    int res = A[0];
    A[0] = A[heapSize-1];
    heapSize--;
    MAX_HEAPIFY(A, 0);
    return res;
}

void HEAP_INCREASE_KEY(int A[],  int indx, int  key)
{
    A[indx] = key;
    while(indx > 0 && A[PARENT(indx)] < A[indx])
    {
        int temp = A[indx];
        A[indx] = A[PARENT(indx)];
        A[PARENT(indx)] = temp;
        indx = PARENT(indx);
    }
}

int main()
{
    int arr[] = {34, 12, 76, 35, 90, 112, 56, 60, 99};
    int len = 9;
    BUILD_MAX_HEAP(arr, len);
    for(int i=0; i<len;i++)
    {
        cout<<HEAP_EXTRACT_MAX(arr)<<endl;
    }
   
    return 0;
}