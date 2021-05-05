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
void preorder(node *root)
{
    if(root!=NULL)
    {
        cout<<root->data<<" ";
        preorder(root->left);

        preorder(root->right);
    }
}
void preorderiterative(node *root)
{
    stack<node *> s;
    while(root!=NULL||!s.empty())
    {
        if(root!=NULL)
        {
            cout<<root->data<<" ";
            s.push(root);
            root=root->left;
        }
        else
        {
            root=s.top();
            s.pop();
            root=root->right;
        }
    }
}
void inorder(node *root)
{
    if(root!=NULL)
    {
        inorder(root->left);
        cout<<root->data<<" ";
        inorder(root->right);
    }
}
void inorderiterative(node *root)
{
    stack<node *> s;
    while(root!=NULL||!s.empty())
    {
        if(root!=NULL)
        {
            s.push(root);
            root=root->left;
        }
        else
        {
            root=s.top();
            cout<<root->data<<" ";
            s.pop();
            root=root->right;
        }
    }
}
void postorder(node *root)
{
    if(root!=NULL)
    {
        postorder(root->left);
        postorder(root->right);
        cout<<root->data<<" ";
    }
}
void postorderiterativeusingonestack(node *root)
{
    node *curr=root;
    stack<node *> s;
    while(true)
    {
        if(curr!=NULL)
        {
            s.push(curr);
            curr=curr->left;
        }
        else
        {
            if(s.empty()) break;
            curr=s.top()->right;
            if(curr==NULL)
             {
                node *last=NULL;
                while(!s.empty()&&s.top()->right==last)
                {
                    last=s.top();
                    s.pop();
                    cout<<last->data<<" ";

                }
             }
        }
    }
}
void postorderiterativeusingtwostack(node *root)
{
    if(root==NULL) return;
    stack<node *> s,result;
    s.push(root);
    while(!s.empty())
    {
        node *curr=s.top();
        s.pop();
        result.push(curr);
        if(curr->left)
            s.push(curr->left);
        if(curr->right)
            s.push(curr->right);
    }
    while(!result.empty())
    {
        cout<<result.top()->data<<" ";
        result.pop();
    }
}
int main()
{
    node *root=buildtree();
    preorder(root);
    cout<<"\n";
    preorderiterative(root);
    cout<<"\n";
    inorder(root);
    cout<<"\n";
    inorderiterative(root);
    cout<<"\n";
    postorder(root);
    cout<<"\n";
    postorderiterativeusingonestack(root);
    cout<<"\n";
    postorderiterativeusingtwostack(root);
    cout<<"\n";
}
