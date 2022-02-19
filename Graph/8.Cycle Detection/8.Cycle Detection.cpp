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

class Graph
{
    map<ll,list<ll>> m;
public:
    void addedge(ll x,ll y)
    {
        m[x].pb(y);
        m[y].pb(x);
    }
    bool cycle_helper(int node,map<int,bool> &visited,int parent)
    {
        visited[node]=true;
        for(auto i:m[node])
        {
            if(!visited[i])
            {
                bool cycle_mila=cycle_helper(i,visited,node);
                if(cycle_mila)
                    return true;
            }
            else if(i!=parent)
            {
                return true;
            }
        }
        return false;
    }
    bool contains_cycle()
    {
        map<int,bool> visited;
        for(auto i:m)
        {
            visited[i.first]=false;
        }
        return cycle_helper(0,visited,-1);
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Graph g;
    g.addedge(0,1);
    g.addedge(1,2);
    g.addedge(2,3);
    g.addedge(3,4);
    g.addedge(4,0);
    cout<<g.contains_cycle();
    return 0;
}
