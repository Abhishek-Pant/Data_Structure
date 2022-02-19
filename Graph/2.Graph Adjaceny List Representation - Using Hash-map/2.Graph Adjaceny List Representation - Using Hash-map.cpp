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
    unordered_map<string,list<pair<string,int>>> l;
public:
    void addedge(string x,string y,bool bidirectional,int wt)
    {
        l[x].push_back(make_pair(y,wt));
        if(bidirectional)
        {
            l[y].push_back(make_pair(x,wt));
        }
    }
    void printGraph()
    {
        for(auto p:l)
        {
            string city=p.first;
            cout<<"city "<<city<<"->";
            list<pair<string ,int>> nbrs=p.second;
            for(auto nbr:nbrs)
            {
                string destination=nbr.first;
                int distance=nbr.second;
                cout<<destination<<" "<<distance<<",";
            }
            cout<<en;
        }
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Graph g;
    g.addedge("A","B",true,20);
    g.addedge("B","D",true,40);
    g.addedge("A","C",true,10);
    g.addedge("C","D",true,30);
    g.addedge("A","D",false,50);
    g.printGraph();

    return 0;
}
