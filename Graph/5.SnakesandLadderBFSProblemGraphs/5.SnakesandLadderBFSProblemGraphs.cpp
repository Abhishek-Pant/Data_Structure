#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")

#include <bits/stdc++.h>

using namespace std;

#define ll long long int
#define llu long long unsigned int
#define ld long double
#define ff first
#define ss second
#define mp(x,y) make_pair(x,y)
#define pll pair<ll,ll>
#define pb push_back
#define sz size
#define en '\n'

#define repi(i,n) for(ll i=0;i<n;i++)
#define repn(i,a,n) for(ll i=a;i<n;i++)
#define repan(i,a,n) for(ll i=0;i<=n;i++)


ll inf = 1e18;
ll mod = 1e9 + 7 ;

template<typename T>
class Graph
{
    map<T,list<T>> l;
public:
    void addedge(int x,int y)
    {
        l[x].push_back(y);// undirectional graph
    }
    int bfs(T src,T dist)
    {
        map<T,int> dis;// for calculating distance
        map<T,T> parent;// for creation path
        queue<T> q;
        for(auto i:l)
        {
            T node=i.first;
            dis[node]=INT_MAX;
        }
        q.push(src);
        dis[src]=0;
        parent[src]=src;
        while(!q.empty())
        {
            T node=q.front();
            q.pop();
            for(int nbr:l[node])
            {
                if(dis[nbr]==INT_MAX)
                {
                    q.push(nbr);
                    dis[nbr]=dis[node]+1;
                    parent[nbr]=node;
                }
            }
        }
        // Sortest Path form source to the distination
        T temp=dist;
        while(temp!=src)
        {
            cout<<temp<<"<--";
            temp=parent[temp];
        }
        cout<<src<<en;
        //Sortest distance between source and distination
        return dis[dist];
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int boardjump[43]={0};//36+6+1
    boardjump[2]=13;
    boardjump[5]=2;
    boardjump[9]=18;
    boardjump[18]=11;
    boardjump[17]=-13;
    boardjump[20]=-14;
    boardjump[24]=-8;
    boardjump[25]=10;
    boardjump[32]=-2;
    boardjump[34]=-22;

    Graph<int> g;
    for(int i=0;i<=36;i++)
    {
        for(int dice=1;dice<=6;dice++)
        {
            int j=i+dice;
            j+=boardjump[j];
            if(j<=36)
                g.addedge(i,j);
        }
    }
    g.addedge(36,36);
    cout<<g.bfs(0,36);
    return 0;
}
