#include <iostream>
#include <cmath>

using namespace std;
struct Node{
    int value;
    struct Node *lchild;
    struct Node *rchild;
    int height;
    Node(int v):value(v), lchild(NULL), rchild(NULL),height(1){}
};

int getHeight(Node * root){
    if(root == NULL)
        return 0;
    else
        return root->height;
}
bool isBalanced(Node *left, Node *right)
{
    return abs(getHeight(left) - getHeight(right)) < 2;
}
Node *singleRotateR(Node *root)
{
    Node *t;
    t = root ->rchild; 
    root->rchild = t->lchild;
    t->lchild = root;
    
    root->height = max(getHeight(root->lchild), getHeight(root->rchild)) + 1;
    t->height = max(getHeight(t->lchild), getHeight(t->rchild)) + 1;

    return t;
}
Node *singleRotateL(Node *root)
{
    Node *t;
    t = root ->lchild; 
    root->lchild = t->rchild;
    t->rchild = root;
    
    root->height = max(getHeight(root->lchild), getHeight(root->rchild)) + 1;
    t->height = max(getHeight(t->lchild), getHeight(t->rchild)) + 1;

    return t;
}

Node *doubleRotateRL(Node *root)
{
    root->rchild = singleRotateL(root->rchild);
    return singleRotateR(root);
}
Node *doubleRotateLR(Node *root)
{
    root -> lchild = singleRotateR(root->lchild);
    return singleRotateL(root);
}
Node *insert(int value, struct Node *root)
{
    if(root == NULL)
    {
        root = new Node(value);
        return root;
    }
    else
    {
        if(value > root->value)
        {
            root->rchild = insert(value, root -> rchild);
            if(!isBalanced(root->lchild, root->rchild))
            {
                if(value > root->rchild->value)
                    root = singleRotateR(root);
                else
                    root = doubleRotateRL(root);
            }
        }
        else
        {
            root->lchild = insert(value,root->lchild);
            if(!isBalanced(root->lchild, root->rchild))
            {
                if(value < root ->lchild ->value)
                    root = singleRotateL(root);
                else
                    root = doubleRotateLR(root);
            }
        }
        root->height = max(getHeight(root->lchild), getHeight(root->rchild)) + 1;
        return root;
    }
}
void putout(Node *root)
{
    if(root == NULL)
        return;
    printf("%d ",root->value);
    putout(root->lchild);
    putout(root->rchild);
}
int main()
{
    int N;
    cin >> N;
    int t;
    struct Node * root = NULL;
    for(int i = 0; i<N; i++)
    {
        cin  >> t;
        root = insert(t, root);
       // putout(root);
      //  cout << endl;
    }
    cout << root -> value<<endl;

    return 0;

}