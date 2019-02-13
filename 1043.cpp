#include <iostream>
#include <stdlib.h>
using namespace std;
//15:46
struct BST{
    int value;
    struct BST *left;
    struct BST *right;
};

void push(struct BST* &root, int value)
{
    struct BST *t = (struct BST *) malloc(sizeof(struct BST));
    t->left = NULL;
    t->right = NULL;
    t->value = value;
    if(root == NULL)
    {
        root = t;
        //cout << root->value << " 1 ";
    }
    else
    {
        if(value < root->value)
        {
            if(root->left == NULL)
                root->left = t;
            else   
            {
                //free(t);
                push(root->left, value);
            }
                
        }
        else
        {
            if(root->right == NULL)
                root->right = t;
            else
                push(root->right, value);
        }
           
    }
}
int cnt = 0;
int pre_order[1008];
int flag1 = true, flag2 = true;

void check_pre_order(struct BST * root)
{
    if(root != NULL)
    {
       //cout << root->value << " ";
        if(root->value == pre_order[cnt])
        {
            cnt++;
        }
        else
        {
            flag1 = false;
        }   
        check_pre_order(root->left);
        check_pre_order(root->right);
    }
}
void check_post_order(struct BST * root)
{
    if(root != NULL)
    {
        //cout << root->value << " ";
        if(root->value == pre_order[cnt])
        {
            cnt++;
        }
        else
        {
            flag2 = false;
        }     
        check_post_order(root->right);
        check_post_order(root->left);
  
         
    }
}
void get_post_order(struct BST *root)
{
    if(root != NULL)
    {
        get_post_order(root->left);
        get_post_order(root->right);
        if(flag1)
        {
            cout << root->value;
            flag1 = false;
        }
        else
            cout << " " << root->value;
    }
}
void get_post_order2(struct BST *root)
{
    if(root != NULL)
    {  
        get_post_order2(root->right);
        get_post_order2(root->left);
     
        if(flag2)
        {
            cout << root->value;
            flag2 = false;
        }
        else
            cout << " " << root->value;
    }
}
int main()
{
    int N;

    struct BST *root = NULL;
    cin >> N;
    for(int i = 0; i<N; i++)
    {
        cin >> pre_order[i];
        push(root, pre_order[i]);
    }    

    check_pre_order(root);
    cnt = 0;
    check_post_order(root);
    
    if(flag1)
    {
        cout << "YES" << endl;
        get_post_order(root);
    }
    else if(flag2)
    {
        cout << "YES" << endl;
        get_post_order2(root);
    }
       
    else
        cout << "NO";
    

}