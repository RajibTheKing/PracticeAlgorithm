#include <iostream>
#include <vector>
using namespace std;

vector<int> Counting_Sort(vector<int> A)
{
    //let's assuem range, k = 100
    int k = 100;
    vector<int> C(k+1,0);
    for(int i=0; i<A.size(); i++)
    {
        C[ A[i] ] = C[ A[i] ] + 1;
    }

    for(int i=1; i<=k; i++)
    {
        C[i] = C[i-1] + C[i];
    }

    vector<int> B(A.size() + 1, 0);
    for(int i = A.size()-1; i>=0; i--)
    {
        //cout<<"Calculating for position : "<<A[i]<<"  which is: "<<C [ A[i] ]<<endl;
        B [ C [ A[i] ] ] = A[i];
        C [ A[i] ] = C [ A[i] ] - 1;
    }

    vector<int> ans(B.begin()+1, B.end());
    return ans;
}

void Show(vector<int> vals)
{
    for(int val:vals)
    {
        cout<<val<<"  ";
    }
    cout<<endl;
}
int main()
{
    vector<int> A{2,5,3,0,2,3,0,3};
    Show(A);
    vector<int> ans = Counting_Sort(A);
    Show(ans);

    return 0;
}