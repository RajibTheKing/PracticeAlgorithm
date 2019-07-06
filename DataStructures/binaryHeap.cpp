#include <iostream>
#include <cmath>
using namespace std;

void ShowArray(int A[], int n)
{
    for(int i=1; i<=n; i++)
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

void MAX_HEAPIFY(int A[], int maxIndex, int indx)
{
    int l = LEFT(indx);
    int r = RIGHT(indx);
    int largest;
    if (l <= maxIndex && A[l] > A[indx])
        largest = l;
    else
        largest = indx;

    if(r <= maxIndex && A[r] > A[largest])
        largest = r;
    
    if (largest != indx)
    {
        int temp = A[indx];
        A[indx] = A[largest];
        A[largest] = temp;
        MAX_HEAPIFY(A, maxIndex, largest);
    }
}


void BUILD_MAX_HEAP(int A[], int maxIndex)
{
    for(int i = maxIndex; i>=1; i--)
    {
        MAX_HEAPIFY(A, maxIndex, i);
    }
    
}

void HEAP_SORT(int A[], int maxIndex)
{
    BUILD_MAX_HEAP(A, maxIndex);
    for(int i=maxIndex; i>=1; i--)
    {
        int temp = A[1];
        A[1] = A[i];
        A[i] = temp;
        maxIndex = maxIndex - 1;
        MAX_HEAPIFY(A, maxIndex, 1);
    }
    ShowArray(A, maxIndex);
}

int HEAP_EXTRACT_MAX(int A[], int &maxIndex)
{
    ShowArray(A, maxIndex);
    if (maxIndex <= 0)
    {
        cout<<"No values"<<endl;
        return INT32_MIN;
    }
    int res = A[1];
    A[1] = A[maxIndex];
    maxIndex--;
    MAX_HEAPIFY(A, maxIndex, 1);
    return res;
}

void HEAP_INCREASE_KEY(int A[],  int indx, int  key)
{
    A[indx] = key;
    while(indx > 1 && A[PARENT(indx)] < A[indx])
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
    //to implement Binary heap, I am considering 1 indexed array
    //Benifit: parent child calculation will be bugfree
    int arrOneIndexed[len+1];
    int maxIndex = len;
    for(int i=1; i<=maxIndex; i++)
        arrOneIndexed[i] = arr[i-1];
    
    BUILD_MAX_HEAP(arrOneIndexed, len);
    while(maxIndex)
    {
        cout<<HEAP_EXTRACT_MAX(arrOneIndexed, maxIndex)<<endl;
    }
   
    return 0;
}