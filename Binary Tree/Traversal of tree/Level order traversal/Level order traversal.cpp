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
    cout<<"\n";
    levelorder(root);
    return 0;
}
