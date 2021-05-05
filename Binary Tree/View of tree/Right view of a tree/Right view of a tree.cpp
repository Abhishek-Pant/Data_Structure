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
int maxlevel=-1;
void rightview(node *root,int level)
{
    if(root==NULL) return;
    if(maxlevel<level)
    {
        cout<<root->data<<" ";
        maxlevel=level;
    }
    rightview(root->right,level+1);
    rightview(root->left,level+1);
}
void rightviewiteratively(node *root)
{
    queue<node *> q;
    if(root==NULL) return;
    q.push(root);
    while(!q.empty())
    {
        int n=q.size();
        for(int i=0;i<n;i++)
        {
            node *p=q.front();
            q.pop();
            if(i==n-1)
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
    rightview(root,0);
    cout<<"\n";
    rightviewiteratively(root);
    return 0;
}
