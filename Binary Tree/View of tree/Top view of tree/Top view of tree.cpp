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
void topview(node *root,map<int,pair<int,int>>& m,int dist,int level)
{
   if(root==NULL)
        return;
   if(m.count(dist)==0||m[dist].second>level)
    m[dist]=make_pair(root->data,level);
   topview(root->left,m,dist-1,level+1);
   topview(root->right,m,dist+1,level+1);
}
void topviewiterative(node *root)
{
    if(root==NULL)
        return;
    queue<pair<node *,int>> q;
    q.push({root,0});
    map<int,int> m;
    while(!q.empty())
    {
        node *curr=q.front().first;
        int dist=q.front().second;
        q.pop();
        if(m.count(dist)==0)
            m[dist]=curr->data;
        if(curr->left)
            q.push({curr->left,dist-1});
        if(curr->right)
            q.push({curr->right,dist+1});
    }
    for(auto i:m)
        cout<<i.second<<" ";
}
int main()
{
    node *root=buildtree();
    map<int,pair<int,int>> m;
    topview(root,m,0,0);
    for(auto i:m)
        cout<<i.second.first<<" ";
    cout<<"\n";
    topviewiterative(root);
    return 0;
}
