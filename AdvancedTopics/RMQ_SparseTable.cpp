#include <iostream>
#include <vector> 
#include <cmath>
#include <stdio.h>
#include <string.h>

using namespace std;
#define SZ 1000 

int M[SZ][SZ];

void preCalculation(vector<int> A)
{
    //O(nLgn) solution

    int i, j;
    int N = A.size();
    //initialize M for the intervals with length 1
    
    for (i = 0; i < N; i++) 
        M[i][0] = i;

    //compute values from smaller to bigger intervals
    for (j = 1; 1 << j <= N; j++)
    {
        for (i = 0; i + (1 << j) - 1 < N; i++)
        {
            if (A[M[i][j - 1]] < A[M[i + (1 << (j - 1))][j - 1]])
                M[i][j] = M[i][j - 1];
            else
                M[i][j] = M[i + (1 << (j - 1))][j - 1];
        }
    }

}

int query(int L, int R, vector<int> A)
{
    //O(1) solution
    int j = (int)log2(R-L+1);
    if(M[L][j]  <=  M[R-(1<<j)+1][j])
        return A[M[L][j]];
    else
        return A[ M[R-(1<<j)+1][j]];
    
}
int main()
{
    //vector<int> A{10, 5, 12, 3, 9, 15, 20, 45, 1, 55};
    vector<int> A{7, 2, 3 , 0, 5 , 10, 3, 12, 18};
    preCalculation(A);

    int L, R;
    while(cin>>L>>R)
    {
        cout<<"Minimum in range: ["<<L<<","<<R<<"]  =  "<< query(L, R, A)<<endl;
    }
    return 0;
}

