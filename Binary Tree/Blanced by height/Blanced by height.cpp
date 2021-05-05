#include<bits/stdc++.h>
using namespace std;
class node
{
public:
    int data;
    node* left;
    node* right;
    node(int d)
    {
        data=d;
        left=NULL;
        right=NULL;
    }
};
node *buildtree()
{
    int d;
    cin>>d;
    if(d==-1)
    {
        return NULL;
    }
    node* root=new node(d);
    cout<<"enter left child "<<root->data<<" :";
    root->left=buildtree();
    cout<<"enter right child "<<root-> data<<":";
    root->right=buildtree();
    return root;
}
bool f=true;
int solve(node *root)
{
    if(root==NULL)
        return 0;
    else
    {
        int l=solve(root->left);
        int r=solve(root->right);
        if(abs(l-r)>1)
            f=false;
        return max(l,r)+1;
    }
}
bool isbalanced(node *root)
{
    f=true;
    solve(root);
    return f;
}
int main()
{
    node *root=buildtree();
    cout<<isbalanced(root);
}
