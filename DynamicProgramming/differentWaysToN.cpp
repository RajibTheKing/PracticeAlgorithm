#include <iostream>
#include <vector>
#include <string.h>
using namespace std; 

vector<int> concat(vector<int> A, int v)
{
    A.push_back(v);
    return A;
}

int dp[1000];

int solve(vector<int> A, int curSum, int target, vector<int> combinations)
{
    if(curSum > target) return 0;
    if(curSum == target)
    {
        /*
        for(int i=0; i<combinations.size(); i++)
        {
            cout<<combinations[i]<<" ";
        }
        cout<<endl;
         */
        return 1;
    } 
    int &ret = dp[curSum];
    if(ret != -1) return ret;
    int numberOfWays = 0;
    for(int i=0; i<A.size(); i++)
    {
        numberOfWays += solve(A, curSum+A[i], target, concat(combinations, A[i]));
    }
    ret = numberOfWays;
    return ret;
}


int main()
{
    vector<int> A{1,2,5,10,20};
    vector<int> t;
    memset(dp, -1, sizeof(dp));
    t.clear();
    cout<<solve(A, 0, 27, t)<<endl;
    return 0;
}