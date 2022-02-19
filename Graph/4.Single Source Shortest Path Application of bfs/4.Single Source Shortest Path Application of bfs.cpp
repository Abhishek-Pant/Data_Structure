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
        l[x].push_back(y);
        l[y].push_back(x);
    }
    void printlist()
    {
        for(auto i:l)
        {
            int f=i.first;
            cout<<f<<"->";
            list<int> l2=i.second;
            for(auto j:l2)
            {
                cout<<j<<",";
            }
            cout<<en;
        }
    }
    void bfs(T src)
    {
        map<T,int> dis;
        queue<T> q;
        for(auto i:l)
        {
            T node=i.first;
            dis[node]=INT_MAX;
        }
        q.push(src);
        dis[src]=0;

        for(auto i:dis)
            cout<<i.first<<" "<<i.second<<en;
        cout<<en;

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
                    cout<<nbr<<" "<<dis[nbr]<<" "<<node<<en;
                }
            }
        }
        cout<<en;
        for(auto i:dis)
        {
            T node=i.first;
            int d=dis[node];
            cout<<"Node "<<node<<" Dist form src "<<d<<en;
        }
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    /*
    (2)----(1)
     |      |
     |      |
    (3-----(0)
     |
     |
    (4)----(5)
    */
    Graph<int> g;
    g.addedge(0,1);
    g.addedge(1,2);
    g.addedge(0,3);
    g.addedge(3,4);
    g.addedge(4,5);
    g.addedge(2,3);

    g.printlist();
    g.bfs(0);// sortest distance form the source

    return 0;
}
