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
int maxlevel=-1;
void leftviewrecursively(node *root,int level)
{
    if(root==NULL) return;
    if(maxlevel<level)
    {
        cout<<root->data<<" ";
        maxlevel=level;
    }
    leftviewrecursively(root->left,level+1);
    leftviewrecursively(root->right,level+1);
}
void leftview(node *root)
{
    queue<node *> q;
    q.push(root);
    while(!q.empty())
    {
        int n=q.size();
        for(int i=0;i<n;i++)
        {
            node *p=q.front();
            q.pop();
            if(i==0)
            {
                cout<<p->data<<" ";
            }
            if(p->left)
                q.push(p->left);
            if(p->right)
                q.push(p->right);
        }
    }
}
int main()
{
    node *root=buildtree();
    leftviewrecursively(root,0);
    cout<<"\n";
    leftview(root);
}
