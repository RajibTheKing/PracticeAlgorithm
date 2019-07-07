// Kadane's Algorithm
// Complexity O(n)

#include <iostream> 
#include <climits>
#include <vector>
#include <map>
using namespace std; 

bool ThreeSum(vector<int> A, int target)
{
    map<int, bool> mp;
    mp.clear();
    bool ret = false;
    for(int i=0; i<A.size()-2; i++)
    {
        int curSum = target - A[i];
        mp.clear();
        for(int j=i+1; j<A.size(); j++)
        {
            if(mp[curSum - A[j]] == true)
            {
                printf("Found: %d + %d + %d = %d\n", A[i], A[j], curSum - A[j], target);
                ret = true;
            }
            else
            {
                mp[A[j]] = true;
            }
            
        }
    }
    return ret;
}
int main() 
{ 
    vector<int> A{ 1, 4, 45, 6, 10, 8 }; 
    int sum = 22; 
	bool found = ThreeSum(A, sum);
	cout << "3 SUM Found:  " << found << endl; 
	return 0; 
} 
