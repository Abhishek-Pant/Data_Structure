#include<bits/stdc++.h>
using namespace std;

class dus
{
    int *parent;
    int *rankset;
public:
    dus(int n)
    {
        parent =new int[n];
        rankset=new int[n];
        for(int i=0;i<n;i++)
        {
            parent[i]=-1;
            rankset[i]=1;
        }
    }
    int findset(int i)
    {
        if(parent[i]==-1)
        {
            return i;
        }
        else
        {
            return parent[i]=findset(parent[i]);
        }
    }
    void unionset(int i,int j)
    {
        int s1=findset(i);
        int s2=findset(j);

        if(s1!=s2)
        {
            if(rankset[s1]<rankset[s2])
            {
                parent[s1]=s2;
                rankset[s2]+=rankset[s1];
            }
            else
            {
                parent[s2]=s1;
                rankset[s1]+=rankset[s2];
            }
        }
    }
};
class Graph
{
    int v;
    vector<vector<int>> edgelist;
public:
    Graph(int v)
    {
        this->v=v;
    }
    void addedge(int w,int x,int y)
    {
        edgelist.push_back({w,x,y});
    }
    int kruskal()
    {
        sort(edgelist.begin(),edgelist.end());

        dus s(v);

        int ans=0;
        for(auto i:edgelist)
        {
            int w=i[0];
            int x=i[1];
            int y=i[2];

            int s1=s.findset(x);
            int s2=s.findset(y);

            if(s1!=s2)
            {
                s.unionset(s1,s2);
                ans+=w;
            }
        }
        return ans;
    }
};
int main()
{
    Graph g(6);
    g.addedge(0,1,1);
    g.addedge(1,3,3);
    g.addedge(3,2,4);
    g.addedge(2,0,2);
    g.addedge(0,3,2);
    g.addedge(1,2,2);
    /*
    int n,m;
    cin>>n>>m;
    Graph g(n);
    for(int i=0;i<m;i++)
    {
        int a,b,c;
        cin>>a>>b>>c;
        g.addedge(c,a-1,b-1);
    }
    */
    cout<<g.kruskal()<<endl;
    return 0;
}
