#include <iostream>
#include <algorithm>
using namespace std;


int exponentMod(int A, int B, int C) 
{ 
    if (A == 0)  return 0; 
    if (B == 0)  return 1; 
    long y; 

    if (B % 2 == 0) 
    { 
        y = exponentMod(A, B / 2, C); 
        y = (y * y) % C; 
    } 
    else 
    { 
        y = A % C; 
        y = (y * exponentMod(A, B - 1, C) % C) % C; 
    } 
  
    return (int)((y + C) % C); 
} 

bool PSeudoPrime_Fermat(int n)
{
    
    for(int i=2; i<n; i++)
    {
        int a = i;
        if(__gcd(a,n) != 1)
        {
            //it's not a coprime
            return false;
        }
        int M = exponentMod(a, n-1, n);
        printf("a = %d, power(a,n-1) = %d, M = %d\n", a, exponentMod(a, n-1, n), M);
        if(M != 1) return false;
    }
    return true;
}

pair<int, int> calculate(int n)
{
    int t = 0;
    while(n%2==0)
    {
        t++;
        n/=2;
    }
    return make_pair(t, n);
}

bool Witness(int a, int n)
{
    pair<int,int> ret = calculate(n-1);
    int t = ret.first;
    int u = ret.second;
    int M = exponentMod(a, u, n);
    int x = M;
    for(int i=0; i<t; i++)
    {
        x = (x * x) % n;
    }
    printf("a = %d, t = %d, u = %d, M = %d\n", a, t, u, x);
    if(x != 1) return true;
    return false;
}

bool PseudoPrime_MillarRabin(int n, int s)
{
    for(int i=0; i<s; i++)
    {
       int a = 1 + rand() % (n-1);
       
       if(Witness(a,n))
       {
           return false;
       }
    }
    return true;
}
int main()
{
    int n;
    while(cin>>n)
    {
        if(PseudoPrime_MillarRabin(n, 100))
            cout<<"PRIME"<<endl;
        else
            cout<<"COMPOSITE"<<endl;
        
    }
    return 0;
}