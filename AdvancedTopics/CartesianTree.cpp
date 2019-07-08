//Reference1: https://www.techiedelight.com/construct-cartesian-tree-from-inorder-traversal/
//Reference2: https://www.geeksforgeeks.org/cartesian-tree/
#include <iostream>
#include <vector>
using namespace std;

class Node 
{
public:
    int value;
    Node *left;
    Node *right;
    Node(int newVal)
    {
        value = newVal;
        left  = nullptr;
        right = nullptr;
    }
};

//Complexity O(n)
int findIndexOfMinimumInRange(vector<int> A, int i, int j)
{
    int minVal = A[i];
    int ret = i;
    while(i<=j)
    {
        if(minVal < A[i])
        {
            minVal = A[i];
            ret = i;
        }
        i++;
    }
    return ret;
}

//Worst case complexity O(n * n)
Node *constructTree(vector<int> A, int low, int high)
{
    if (low > high) return nullptr;
    int minIndex = findIndexOfMinimumInRange(A, low, high);
    Node *curRoot = new Node(A[minIndex]);
    curRoot-> left = constructTree(A, low, minIndex-1);
    curRoot-> right = constructTree(A, minIndex+1, high);
    return curRoot;
}

// Recursive function to perform inorder traversal of a Cartesian tree
void inorderTraversal(Node* root)
{
	if (root == nullptr)
		return;

	inorderTraversal(root->left);
	cout << root->value << ' ';
	inorderTraversal(root->right);
}
int main()
{
	vector<int> inorder = { 9, 3, 7, 1, 8, 12, 10, 20, 15, 18, 5 };
	Node *root = constructTree(inorder, 0, inorder.size() - 1);
	cout << "Inorder Traversal of constructed Cartesian tree is:\n";
	inorderTraversal(root);

	return 0;
}
