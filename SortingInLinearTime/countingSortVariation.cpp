#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Data
{
public:
    //let's assume category ID is in range [0..10]
    //Therefore, We can use counting sort for array of Data
    int category;
    string name;
    Data(){}
    Data(int id, string str)
    {
        category = id;
        name = str;
    }
};

vector<Data> Counting_Sort(vector<Data> A)
{
    int k = 10; //maximum category
    vector<int> C(k+1,0);
    for(int i=0; i<A.size(); i++)
    {
        C[ A[i].category ] = C[ A[i].category ] + 1;
    }

    for(int i=1; i<=k; i++)
    {
        C[i] = C[i-1] + C[i];
    }

    vector<Data> B(A.size() + 1);
    for(int i = A.size()-1; i>=0; i--)
    {
        B [ C [ A[i].category ] ] = A[i];
        C [ A[i].category ] = C [ A[i].category ] - 1;
    }

    vector<Data> ans(B.begin()+1, B.end());
    return ans;
}

void Show(vector<Data> vals)
{
    for(Data val:vals) cout<<val.category<<"  "<<val.name<<endl;
}

vector<Data> inputData()
{
    int numberOfItems = 8;
    string productNames[] = {"Computer", "Shirt", "Bier", "Soap", 
                             "Laptop", "Vodka", "Lotion", "Whiskey"};
    int categoryID[] = {2,5,3,0,2,3,0,3};
    vector<Data> inData;
    for(int i=0; i<numberOfItems; i++)
    {
        Data data(categoryID[i], productNames[i]);
        inData.push_back(data);
    }
    return inData;
}
int main()
{
    vector<Data> A = inputData();
    cout<<"Unsorted Items --> "<<endl;
    Show(A);
    vector<Data> ans = Counting_Sort(A);
    cout<<"\n\nSorted Items --> "<<endl;
    Show(ans);
    return 0;
}