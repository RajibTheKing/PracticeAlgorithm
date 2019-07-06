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
    void setCoins(vector<int> in)
    {
        coins = in;
    }

};
Data dp[Max_Amount + 1];

int MinCoin(vector<int> C)
{
    for(int i=0; i<=Max_Amount; i++)
    {
        dp[i].minimumCoins = (1<<30);
        dp[i].coins.clear();
    }

    dp[0].minimumCoins = 0;
    for(int i=0; i<C.size(); i++)
    {
        int curCoin = C[i];
        for(int j=1; j<=Max_Amount; j++)
        {
            int prevIndx = j - curCoin;
            if(prevIndx>=0)
            {
                //dp[j] = min(dp[j], dp[prevIndx] + 1);if
                if(dp[j].minimumCoins > dp[prevIndx].minimumCoins + 1) 
                {
                    vector<int> newcoins = dp[prevIndx].coins;
                    newcoins.push_back(curCoin);
                    dp[j].minimumCoins = dp[prevIndx].minimumCoins + 1;
                    dp[j].setCoins(newcoins);
                } 
            }
        }
    }

}
vector<int> query(int amount)
{
    return dp[amount].coins;
}
int main()
{
    vector<int> coins = {1,2,5,10,20, 50};
    MinCoin(coins);
    int n;
    while(cin>>n)
    {
        vector<int> ret = query(n);
        for(int val: ret)
        {
            cout<<val<<" ";
        }
        cout<<endl;
    }
}