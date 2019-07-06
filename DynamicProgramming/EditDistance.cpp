//Reference: https://www.geeksforgeeks.org/edit-distance-dp-5/

#include <iostream>
#include <string>
#include <string.h>
using namespace std;

int dp[1000][1000];

int Edit_Distance(string A, string B, int i, int j)
{
    //Constructing B from A

    if(i == A.size()) return (B.size() - j);
    if(j == B.size()) return (A.size() - i);

    int &ret = dp[i][j];
    if(ret != -1) return ret;
    
    ret = 1<<30; //initialize int max

    if(A[i] == B[j]) ret = Edit_Distance(A, B, i+1, j+1);
    else
    {
        ret = min(ret, 1 + Edit_Distance(A, B, i+1, j));   //remove from A
        ret = min(ret, 1 + Edit_Distance(A, B, i, j+1));   //insert into A
        ret = min(ret, 1 + Edit_Distance(A, B, i+1, j+1)); //replace A[i] = B[i]        
    }
    return ret;
}

int main()
{
    string A = "abdc";
    string B = "bcd";
    memset(dp, -1, sizeof(dp));
    cout<<"Edit Distance = "<<Edit_Distance(A, B, 0, 0)<<endl;
    return 0;
}