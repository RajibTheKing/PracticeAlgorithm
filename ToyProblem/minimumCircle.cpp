//Problem 2: 
//We are given n points on the Axis X , and natural number K. 
//
//such that the point has the coordinate (0,Pi) 
//such that Pi-1 < Pi 
//
//find the minimum D such that the circle centered in (O,Pi) of radious D 
//that contains at least K points of the set. 
//complexity of my solution is: O(n * K)
//But this is also can be solved withing O(n)

#include <iostream>
#include <vector> 
using namespace std;

int getDiff(int a, int b)
{
    if (a < b) return (b-a);
    return a - b;
}

int findMinimumD(vector<int> A, int K)
{
    int M = 0;
    int left; 
    int right;
    int ans = __INT_MAX__;

    for(int i = 1; i+K-1<=A.size(); i++)
    {
        left = i-1;
        right = left + K - 1;
        int maxDiff = __INT_MAX__;
        int center = -1;
        for(int c = i; c<right; c++)
        {
            int leftDist = A[c] - A[left];
            int rightDist = A[right] - A[c];
            int diff = getDiff(leftDist, rightDist);
            if(maxDiff > diff)
            {
                center = c;
                maxDiff = diff;
            }
        }
        M = max(A[center] - A[left], A[right] - A[center] );
        printf("Left = %d, right = %d, center = %d, M = %d\n", A[left], A[right], A[center], M);
        ans = min(ans, M);
    }
    return ans;
}

int main()
{
    vector<int> A{3, 7, 11, 12, 13, 19, 25, 28, 30, 31, 32, 33, 40};
    cout<<"Answer: "<<findMinimumD(A,5)<<endl;
    return 0;
}