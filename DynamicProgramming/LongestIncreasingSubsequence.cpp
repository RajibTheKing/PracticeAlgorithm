//https://www.geeksforgeeks.org/longest-increasing-subsequence-dp-3/
/* Dynamic Programming C++ implementation of LIS problem */
#include<bits/stdc++.h>  
using namespace std; 
    
/* lis() returns the length of the longest increasing  
  subsequence in arr[] of size n */
int lis( int arr[], int n )  
{  
    int lis[n]; 
   
    lis[0] = 1;
    
    vector<int> val[n];
    val[0].push_back(arr[0]);    
  
    /* Compute optimized LIS values in bottom up manner */
    for (int i = 1; i < n; i++ )  
    { 
        lis[i] = 1;
        val[i].push_back(arr[i]);
        for (int j = 0; j < i; j++ )   
        {
            if ( arr[i] > arr[j] && lis[i] < lis[j] + 1)  
            {
                lis[i] = lis[j] + 1;  
                val[i] = val[j];
                val[i].push_back(arr[i]);
            }
        }
    } 
  
    // Return maximum value in lis[] 
    int length = INT_MIN;
    int ansIndx = 0;
    for(int i=0; i<n;i++)
    {
        if(lis[i] > length)
        {
            length = lis[i];
            ansIndx = i;
        }
    }
    for(int i=0; i<val[ansIndx].size(); i++)
    {
        cout<<val[ansIndx][i]<<" ";
    }
    cout<<endl;

    return *max_element(lis, lis+n); 
}  
    
/* Driver program to test above function */
int main()  
{  
    int arr[] = { 10, 22, 9, 33, 21, 50, 41, 60 };  
    int n = sizeof(arr)/sizeof(arr[0]);  
    printf("Length of lis is %d\n", lis( arr, n ) );  
    return 0;  
}