#include <iostream>
using namespace std;

class Node 
{
public:
    Node *parent;
    Node *child;
    Node *left;
    Node *right;
    bool marked;
    int degree;
    int value;
    Node()
    {
        initializePointer();
    }
    Node(int val)
    {
        value = val;
        initializePointer();
    }
    void initializePointer()
    {
        parent = nullptr;
        child = nullptr;
        left = nullptr;
        right = nullptr;
    }

};

class FibHeap
{
public:
    Node *minNode;
    Node *leftMost;
    Node *rightMost;
    int n;
    FibHeap()
    {
        minNode = nullptr;
        leftMost = nullptr;
        rightMost = nullptr;
        n = 0;
    }
};

FibHeap* MAKE_HEAP()
{
    FibHeap *heap = new FibHeap();
    return heap;
}
FibHeap* FIB_HEAP_INSERT(FibHeap *H, Node *x)
{
    x->degree = 0;
    x->parent = nullptr;
    x->child = nullptr;
    x->marked = false;
    x->left = x;
    x->right = x;

    if(H->minNode == nullptr)
    {
        //managing root list
        H->minNode = x;
        H->leftMost = x;
        H->rightMost = x;
        H->n = H->n +1;
    }
    else
    {
        H->leftMost->left = x;
        x->right = H->leftMost;
        H->leftMost = x;
        H->rightMost->right = x;
        x->left = H->rightMost;
        //There exists a bug here
        if(x->value < H->minNode->value)
        {
            H->minNode = x;
        }
        H->n = H->n +1;
    }
    
}
int FIB_EXTRACT_MIN(FibHeap *H)
{
    return H->minNode->value;
}
void display(FibHeap *H)
{
    Node *ptr = H->leftMost;
    for(int i=0; i < H->n; i++)
    {
        cout<<ptr->value<<endl;
        ptr = ptr->right;
    }

    Node *ptrTwo = H->rightMost;
    for(int i=0; i < H->n; i++)
    {
        cout<<ptr->value<<endl;
        ptrTwo = ptrTwo->left;
    }
    cout<<"Done"<<endl;
}
int main()
{
    FibHeap *H = MAKE_HEAP();
    Node *x = new Node(50);
    H = FIB_HEAP_INSERT(H, x);

    Node *y = new Node(25);
    H = FIB_HEAP_INSERT(H, y);

    Node *z = new Node(100);
    H = FIB_HEAP_INSERT(H, z);
    display(H);

    cout<<FIB_EXTRACT_MIN(H)<<endl;
    return 0;
}