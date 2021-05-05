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
void zigzag(node *root)
{
    if(root==NULL) return;
    queue<node *> q;
    q.push(root);
    int f=1;
    while(!q.empty())
    {
        vector<int> tem;
        int s=q.size();
        while(s--)
        {
            node *t=q.front();
            tem.push_back(t->data);
            q.pop();
            if(t->left) q.push(t->left);
            if(t->right) q.push(t->right);
        }
        if(f%2==0)
        {
            for(int i=tem.size()-1;i>=0;i--)
               cout<<tem[i]<<" ";
            f=1;
        }
        else
        {
            for(int i=0;i<tem.size();i++)
               cout<<tem[i]<<" ";
            f=0;
        }
    }
}
int main()
{
    node *root=buildtree();
    zigzag(root);
}
