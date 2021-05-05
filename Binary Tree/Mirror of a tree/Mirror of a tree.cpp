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
void mirror(node *root)
{
    if(root==NULL) return;
    mirror(root->left);
    mirror(root->right);
    swap(root->left,root->right);
}
void levelorder(node *root)
{

     queue<node*> q;
     q.push(root);
     if(root==NULL)
        return;
     while(!q.empty())
     {
         node *p=q.front();
         q.pop();
         cout<<p->data<<" ";
         if(p->left)
         q.push(p->left);
         if(p->right)
         q.push(p->right);
     }
}
int main()
{
    node *root=buildtree();
    levelorder(root);
    cout<<"\n";
    mirror(root);
    levelorder(root);
}
