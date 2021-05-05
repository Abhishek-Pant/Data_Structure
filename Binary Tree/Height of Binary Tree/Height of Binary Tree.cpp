#include<bits/stdc++.h>
using namespace std;
class node
{
public:
    int data;
    node *left;
    node *right;
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
int height(node *root)
{
    if(root==NULL) return 0;
    else return max(height(root->left),height(root->right))+1;
}
int main()
{
    node *root=buildtree();
    cout<<height(root);
}
