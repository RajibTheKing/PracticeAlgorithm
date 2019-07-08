#include<iostream> 
#include<climits> 
using namespace std; 

void swap(int *a, int *b) 
{ 
    int temp = *a; 
    *a = *b; 
    *b = temp; 
} 

int partition(int arr[], int l, int r) 
{ 
    int x = arr[r], i = l; 
    for (int j = l; j <= r - 1; j++) 
    { 
        if (arr[j] >= x) 
        { 
            swap(&arr[i], &arr[j]); 
            i++; 
        } 
    } 
    swap(&arr[i], &arr[r]); 
    return i; 
} 

// This function returns k'th smallest element in arr[l..r] using 
// QuickSort based method.  ASSUMPTION: ALL ELEMENTS IN ARR[] ARE DISTINCT 
int kthLargest(int arr[], int l, int r, int k) 
{  
        int pos = partition(arr, l, r); 
        // If position is same as k 
        if (pos == k-1) 
            return arr[pos]; 
        if (pos > k-1)  // If position is more, recur for left subarray 
            return kthLargest(arr, l, pos-1, k); 
  
        // Else recur for right subarray 
        return kthLargest(arr, pos+1, r, k); 
} 


int main() 
{ 
    //nlogn 
    //O(n)
    int arr[] = {12, 3, 5, 7, 4, 19, 26}; 
    int n = sizeof(arr)/sizeof(arr[0]), k = 5; 
    cout << "K'th largest element is " << kthLargest(arr, 0, n-1, k) <<endl; 
    return 0; 
} 