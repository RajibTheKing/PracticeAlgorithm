//problem 1: (Complexity 2^n)
//-------------
//given an ordered array A with n integers , count the number of subsequences of A that 
//contains only distinct numbers.
//subsequences ... < A[i1], A[i2], A[i3],.....,A[ip] >
//i1 < i2 < .. <ip , p>=1 
//
//of A[i1] , ... A[ip] with A[ix] /= A[iy] , all x,y belongs to [p] , x/=y
//
//1, 1, 2
//
//1 
//   1
//      2
//1     2
//   1  2
//Answer is 5 

#include <iostream>
#include <vector>
#include <string.h>
using namespace std;

bool isFound(vector<int> B, int n)
{
    for(int i=0; i<B.size(); i++)
    {
        if (n == B[i]) return true;
    }
    return false;
}
vector<int> concat(vector<int> A, int v)
{
    A.push_back(v);
    return A;
}
int dp[1000];
int distinctSubset(vector<int> A, int cur,  vector<int> ans)
{
    if(cur == A.size())
    {
        if(ans.size() == 0) return 0;
        for(int i=0; i<A.size(); i++)
        {
            if(isFound(ans, i))
                cout<<A[i]<<"  ";
            else
                cout<<"   ";
        }
        cout<<endl;
        return 1;
    }
    int &ret = dp[cur];
    //if(ret != -1) return ret;
    ret = 0;
    if(ans.size() == 0)
    {
        ret = ret + distinctSubset(A, cur+1, ans);
        ret = ret + distinctSubset(A, cur+1, concat(ans, cur));
    }
    else
    {
        int prevIndx = ans[ans.size()-1];
        if(A[prevIndx] == A[cur])
            ret = ret + distinctSubset(A, cur+1, ans);
        else
        {
            ret = ret + distinctSubset(A, cur+1, ans);
            ret = ret + distinctSubset(A, cur+1, concat(ans, cur));
        }
    }
    return ret;
}

int main()
{
    vector<int> A{1,1,2};
    vector<int> ans;
    memset(dp, -1, sizeof(dp));
    cout<<distinctSubset(A, 0, ans)<<endl;
    return 0;
}