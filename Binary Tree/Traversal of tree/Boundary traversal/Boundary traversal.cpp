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
        return NULL;
    node *root=new node(d);
    cout<<"Enter left child of "<<root->data<<" :";
    root->left=buildtree();
    cout<<"Enter right child of "<<root->data<<" :";
    root->right=buildtree();
    return root;
}
void leftboundary(node *root)
{
    if(root==NULL) return;
    if(root->left)
    {
        cout<<root->data<<" ";
        leftboundary(root->left);
    }
    else if(root->right)
    {
        cout<<root->data<<" ";
        leftboundary(root->right);
    }
}
void leafnode(node *root)
{
    if(root==NULL) return;
    leafnode(root->left);
    if(root->left==NULL&&root->right==NULL)
        cout<<root->data<<" ";
    leafnode(root->right);
}
void rightboundary(node *root)
{
    if(root==NULL) return;
    if(root->right)
    {
        rightboundary(root->right);
        cout<<root->data<<" ";
    }
    else if(root->left)
    {
        rightboundary(root->left);
        cout<<root->data<<" ";
    }
}
void boundary(node *root)
{
    if(root==NULL) return;
    cout<<root->data<<" ";
    leftboundary(root->left);
    leafnode(root);
    rightboundary(root->right);
}
int main()
{
    node *root=buildtree();
    boundary(root);
}
