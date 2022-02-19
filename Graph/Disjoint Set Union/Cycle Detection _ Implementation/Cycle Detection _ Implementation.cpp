#include<bits/stdc++.h>
using namespace std;

class Graph
{
    int v;
    list<pair<int,int>> l;
public:
    Graph(int v)
    {
        this->v=v;
    }
    void addedge(int x,int y)
    {
        l.push_back(make_pair(x,y));
    }
    //Find
    int findset(int i,int parent[])
    {
        if(parent[i]==-1)
            return i;
        else
            return findset(parent[i],parent);
    }
    //Union
    void unionset(int x,int y,int parent[])
    {
        int s1=findset(x,parent);
        int s2=findset(y,parent);

        if(s1!=s2)
        {
            parent[s1]=s2;
        }
        return;
    }
    bool contains_cycle()
    {
        //DSU logic to check if graph contains cycle or not
        int parent[v];
        for(int i=0;i<v;i++)
        {
            parent[i]=-1;
        }
        for(int i=0; i<v; i++)
        {
            cout<<parent[i]<<" ";
        }
        cout<<endl;
        for(auto edge: l)
        {
            int i=edge.first;
            int j=edge.second;

            int s1=findset(i,parent);
            int s2=findset(j,parent);

            if(s1!=s2)
            {
                unionset(s1,s2,parent);
            }
            else
            {
                cout<<"Parent are same "<<s1<<" "<<s2<<" "<<endl;
                for(int i=0; i<v; i++)
                {
                    cout<<parent[i]<<" ";
                }
                cout<<endl;
                return true;
            }
        }
        delete[] parent;
        return false;
    }
};
int main()
{
    Graph g(4);
    g.addedge(0,1);
    g.addedge(1,2);
    g.addedge(2,3);
    g.addedge(3,0);
    cout<<g.contains_cycle();
    return 0;
}
