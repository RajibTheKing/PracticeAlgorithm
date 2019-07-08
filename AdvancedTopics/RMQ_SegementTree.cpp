#include <iostream>
#include <vector>
using namespace std;
#define SZ 128

int arr[SZ];
int segmentTree[SZ * 2 - 1];

//createSegment Tree focusing on finding Range Minimum
//complexity O(n)
int createSegmentTree(int curNode, int left, int right)
{
    
    if(left == right)
    {
        segmentTree[curNode] = arr[left];
    }
    else
    {
        int mid = (left + right) / 2;
        int leftMinimum = createSegmentTree(2 * curNode + 1, left, mid);
        int rightMinimum = createSegmentTree(2 * curNode + 2, mid+1, right);
        if(leftMinimum < rightMinimum)
        {
            segmentTree[curNode] = leftMinimum;
        }
        else
        {
            segmentTree[curNode] = rightMinimum;
        }
        
        
    }
    return segmentTree[curNode];
    
}

//Query complexity O(lgn)
int query(int curNode, int left, int right, int i, int j)
{
    if(i <= left && right <= j)
    {
        return segmentTree[curNode];
    }
    
    if(right < i || j < left) return INT32_MAX;
    

    int mid = (left + right) / 2;
    int leftMinimum = query(2 * curNode + 1, left, mid, i, j);
    int rightMinimum = query(2 * curNode + 2, mid + 1, right, i, j);
    if(leftMinimum < rightMinimum)
        return leftMinimum;
    else
        return rightMinimum;
    
}

int main()
{
    vector<int> input{100, 15, 17, 84, 65, 12, 41, 10, 54};
    int N = input.size();
    for(int i=0; i<N; i++)
    {
        arr[i] = input[i];
    }
    int ret = createSegmentTree(0, 0, N - 1);
    int b, e;
    while(cin>>b>>e)
    {
        printf("Minimum [%d,%d] = %d\n", b, e, query(0, 0, N-1, b, e));
    }
    return 0;
}