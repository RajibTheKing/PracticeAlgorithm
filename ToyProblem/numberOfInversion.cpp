#include <iostream>
#include <vector>
#include <string.h>
using namespace std;

int I[100][100];
int D[100][100];


int Query(int start, int finish)
{
    //Complexity O(n)
    int inversions  = 0;
    for(int i=start; i<=finish; i++)
    {
        printf("i,j = %d,%d --> I[i][j] = %d\n", i,finish, I[i][finish] );
        inversions += I[i][finish];
    }
    return inversions;
}


void calculateInversions(vector<int> A)
{
    //Complexity O(n * n)
    for(int i=0; i<A.size()-1; i++)
    {
        I[i][i] = 0;
        for(int j=i+1; j<A.size(); j++)
        {
            if(A[i] > A[j])
            {
                I[i][j] = I[i][j-1] + 1;
            }
            else
            {
                I[i][j] = I[i][j-1];
            }
            
        }
    }
}


void calculateNumberOfInversions(vector<int> A)
{
    //Complexity O(n * n * n)
    for(int i=0; i<A.size()-1; i++)
    {
        D[i][i] = 0;
        for(int j = i + 1; j<A.size(); j++)
        {
            int start = i;
            int finish = j;
            D[i][j] = Query(i,j);
        }
    }
}



int QueryConstant(int start, int finish)
{
    return D[start][finish];
}

int main()
{
    vector<int> A{2, 4, 1, 3, 5};
    calculateInversions(A);
    calculateNumberOfInversions(A);
    int i, j;
    while(cin>>i>>j)
    {
        cout<<QueryConstant(i, j)<<endl;
    }

    return 0;
}