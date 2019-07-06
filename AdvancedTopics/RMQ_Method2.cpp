#include <iostream>
#include <vector> 
#include <stdio.h>

using namespace std;
#define SZ 1000 

pair<int,int> M[SZ][SZ];
void preCalculation(vector<int> A)
{
    int n = A.size(); 
    for(int i=0; i<n ; i++)
    {
        M[i][i] = make_pair(i, A[i]);
    }

    for(int i=0; i<n; i++)
    {
        for(int j=i+1; j<n; j++)
        {
            pair<int,int> prev = M[i][j-1];
            if(A[prev.first] < A[j])
            {
                M[i][j] = prev;
            }
            else
            {
                M[i][j] = make_pair(j, A[j]);
            }
            
        }
    }

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            printf("%3d", M[i][j].first);
        }
        printf("\n");
    }
    
}


int main()
{
    vector<int> A{10, 5, 12, 3, 9, 15, 20};
    preCalculation(A);

    int startingPoint, endingPoint;

    while(cin>>startingPoint >> endingPoint)
    {
        cout<<M[startingPoint][endingPoint].first<<", "<<M[startingPoint][endingPoint].second<<endl;
    }
    return 0;
}