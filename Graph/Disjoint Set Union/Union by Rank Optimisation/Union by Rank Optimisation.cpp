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
            return parent[i]=findset(parent[i],parent);
    }
    //Union
    void unionset(int x,int y,int parent[],int rankset[])
    {
        int s1=findset(x,parent);
        int s2=findset(y,parent);

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
        return;
    }
    bool contains_cycle()
    {
        int parent[v],rankset[v];
        for(int i=0;i<v;i++)
        {
            parent[i]=-1;
            rankset[i]=1;
        }
        cout<<"Initial parent array : "<<endl;
        for(int i=0;i<v;i++)
        {
            cout<<parent[i]<<" ";
        }
        cout<<endl;
        cout<<"Initial rankset array : "<<endl;
        for(int i=0;i<v;i++)
        {
            cout<<rankset[i]<<" ";
        }
        cout<<endl;
        for(auto edge:l)
        {
            int i=edge.first;
            int j=edge.second;

            int s1=findset(i,parent);
            int s2=findset(j,parent);

            if(s1!=s2)
            {
                unionset(s1,s2,parent,rankset);
            }
            else
            {
                cout<<"Parent are same "<<endl;
                for(int i=0; i<v; i++)
                {
                    cout<<parent[i]<<" ";
                }
                cout<<endl;
                cout<<"Rankset :"<<endl;
                for(int i=0; i<v; i++)
                {
                    cout<<rankset[i]<<" ";
                }
                cout<<endl;
                return true;
            }
        }
        delete[] parent;
        delete[] rankset;
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
