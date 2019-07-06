//n = 5
//1 2 5 10 20
//
//val = 39
//fewest possible coins



#include <iostream>
#include <vector>

using namespace std;
#define Max_Amount 10000

class Data 
{
public:
    int minimumCoins;
    vector<int> coins;

};
int dp[Max_Amount + 1];

int MinCoin(vector<int> C)
{
    for(int i=0; i<=Max_Amount; i++)
    {
        dp[i] = (1<<30);
    }

    dp[0] = 0;
    for(int i=0; i<C.size(); i++)
    {
        int curCoin = C[i];
        for(int j=1; j<=Max_Amount; j++)
        {
            int prevIndx = j - curCoin;
            if(prevIndx>=0)
            {
                dp[j] = min(dp[j], dp[prevIndx] + 1);
            }
        }
    }

}
int query(int amount)
{
    return dp[amount];
}
int main()
{
    vector<int> coins = {1,2,5,10,20};
    MinCoin(coins);
    int n;
    while(cin>>n)
    {
        cout<<query(n)<<endl;
    }
}