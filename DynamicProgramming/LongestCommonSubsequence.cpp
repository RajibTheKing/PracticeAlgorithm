#include <iostream>
#include <string>
using namespace std;
#define SZ 100

int c[SZ][SZ];
int b[SZ][SZ];

int LCS_Length(string A, string B)
{
    int m = A.size();
    int n = B.size();
    A = "#" + A;
    B = "#" + B;
    for(int i = 1; i<=m; i++)    c[i][0] = 0;
    for(int j = 1; j<=n; j++)    c[0][j] = 0;
    c[0][0] = 0;

    for(int i=1; i<=m; i++)
    {
        for(int j=1; j<=n; j++)
        {
            if(A[i] == B[j])
            {
                c[i][j] = c[i-1][j-1] + 1;
                b[i][j] = 1;
            }
            else
            {
                if(c[i][j-1] > c[i-1][j])
                {
                    c[i][j] = c[i][j-1];
                    b[i][j] = 2;
                }
                else
                {
                    c[i][j] = c[i-1][j];
                    b[i][j] = 3;
                }
                
            }
            
            
        }
    }

    return c[m][n];
    
}

string get_LCS(int i, int j, string A, string B)
{
    if(i<0) return "";
    if(j<0) return "";
    if(b[i][j] == 1)
    {
        return  get_LCS(i-1,j-1, A, B) + A[i-1];
        
    }
    else if(b[i][j] == 2)
        return get_LCS(i,j-1, A, B);
    else 
        return get_LCS(i-1,j, A, B); 
}

int main()
{

    string A = "ABCBDAB";
    string B = "BDCABA";
    cout<<LCS_Length(A, B)<<endl;
    cout<<get_LCS(A.size(), B.size(), A, B)<<endl;
    
    return 0;
}