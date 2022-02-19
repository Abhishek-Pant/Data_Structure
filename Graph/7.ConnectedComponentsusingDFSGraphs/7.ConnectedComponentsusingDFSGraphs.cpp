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
    void dfs_helper(T src,map<T,bool> &visited)
    {
        visited[src]=true;
        cout<<src<<" ";
        for(T nbr:l[src]){
            if(!visited[nbr]){
               dfs_helper(nbr,visited);
            }
        }
    }
    void dfs()
    {
        map<T,bool> visited;
        for(auto p:l)
        {
            T node=p.first;
            visited[node]=false;
        }
        int c=0;
        for(auto p:l)
        {
            T node=p.first;
            if(!visited[node]){
                cout<<c<<"-->";
                dfs_helper(node,visited);
                c++;
                cout<<en;
            }
        }
        cout<<c<<en;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    /*
    (4)          (5)-----(6)       (8)
     |                    |
     |                    |
    (0)----(3)           (7)
     |      |
     |      |
    (1)----(2)
    */
    Graph<int> g;

    g.addedge(0,1);
    g.addedge(0,3);
    g.addedge(0,4);
    g.addedge(1,2);
    g.addedge(2,3);

    g.addedge(5,6);
    g.addedge(6,7);

    g.addedge(8,8);

    g.dfs();
    return 0;
}
