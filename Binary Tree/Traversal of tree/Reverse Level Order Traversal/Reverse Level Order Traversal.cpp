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
void reverselevelorder(node *root)
{
    if(root==NULL) return;
    vector<int>  v;
    queue<node *> q;
    q.push(root);
    while(!q.empty())
    {
        node *p=q.front();
        v.push_back(p->data);
        q.pop();
        if(p->right)
            q.push(p->right);
        if(p->left)
            q.push(p->left);
    }
    for(int i=v.size()-1;i>=0;i--)
        cout<<v[i]<<" ";
}
int main()
{
    node *root=buildtree();
    reverselevelorder(root);
}
