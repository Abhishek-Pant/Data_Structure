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
void diagonal(node *root)
{
    queue<node *> q;
    q.push(root);
    if(root==NULL) return;
    vector<int> v;
    while(!q.empty())
    {
        node *tem=q.front();
        q.pop();
        while(tem)
        {
            v.push_back(tem->data);
            if(tem->left) q.push(tem->left);
            tem=tem->right;
        }
    }
    for(int i=0;i<v.size();i++)
        cout<<v[i]<<" ";
}
int main()
{
    node *root=buildtree();
    diagonal(root);
}
