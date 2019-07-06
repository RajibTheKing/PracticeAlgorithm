#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> Counting_Sort(vector<int> A, int digitPosition)
{
    int k = 10; //number of digits in decimal
    vector<int> C(k+1,0);
    int exp = 1;
    
    for(int i=0; i<digitPosition; i++) exp*=10;

    for(int i=0; i<A.size(); i++)
    {
        C[ (A[i]/exp)%10 ] = C[ (A[i]/exp)%10 ] + 1;
    }

    for(int i=1; i<=k; i++)
    {
        C[i] = C[i-1] + C[i];
    }

    vector<int> B(A.size() + 1, 0);
    for(int i = A.size()-1; i>=0; i--)
    {
        //cout<<"Calculating for position : "<<A[i]<<"  which is: "<<C [ A[i] ]<<endl;
        B [ C [ (A[i]/exp)%10 ] ] = A[i];
        C [ (A[i]/exp)%10 ] = C [ (A[i]/exp)%10 ] - 1;
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
int findMaxDigit(vector<int> A)
{
    int maxDigits = 0;
    for(int val:A)
    {
        int temp = val;
        int count = 0;
        while(temp)
        {
            temp/=10;
            count++;
        }
        maxDigits = max(maxDigits , count);
    }
    return maxDigits;
}
vector<int> Radix_Sort(vector<int> A)
{
    int d = findMaxDigit(A);
    cout<<"MaxDigit = " <<d<<endl;
    vector<int> B = A;
    for(int i=0; i<d; i++)
    {
        B = Counting_Sort(B, i);
    }
    return B;
}
int main()
{
    vector<int> A{329,457,657,829,436,720,355};
    Show(A);
    vector<int> ans = Radix_Sort(A);
    Show(ans);

    return 0;
}

