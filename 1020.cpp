#include <iostream>
#include <queue>
using namespace std;

struct Tree{
    int index;
    struct Tree *left;
    struct Tree *right;
}Tree;
int find_ln(int value, int *ln, int N)
{
    for(int i = 0; i<N; i++)
    {
        if(ln[i] == value)
            return i;
    }
    return -1;
}

struct Tree *rebuild_tree(int *post, int *ln, int N)
{
    struct Tree *root;
    if(N == 0)
        return NULL;
    root = (struct Tree *)malloc(sizeof(struct Tree));
    root->index = post[N-1];
    int t = find_ln(post[N-1], ln, N);
    root->left = rebuild_tree(post, ln, t);
    root->right = rebuild_tree(post + t, ln + t + 1, N - t - 1);
    return root;
}

void print_tree(struct Tree *root)
{

    if(root->left != NULL)
        print_tree(root->left);
            printf("%d ",root->index);
    if(root->right != NULL)
        print_tree(root->right);
}
int main()
{
    int N, lc, rc;
    int post[35], ln[35];
    struct Tree *t;
    queue<struct Tree *> result;
    scanf("%d", &N);
    for(int i = 0; i<N; i++)
    {
        scanf("%d", post + i);
    }
    for(int i = 0; i<N; i++)
    {
        scanf("%d", ln + i);
    }

    t = rebuild_tree(post, ln, N);
    //print_tree(t);
    result.push(t);
    bool head = true;
    while(!result.empty())
    {
        if(!head)
        {
            printf(" ");
        }
        else
            head = false;
        printf("%d", result.front()->index);
        struct Tree *tmp = result.front();
        if(tmp -> left != NULL)
            result.push(tmp ->left);
        if(tmp ->right != NULL)
            result.push(tmp ->right);
        result.pop();
    }
    return 0;
}
