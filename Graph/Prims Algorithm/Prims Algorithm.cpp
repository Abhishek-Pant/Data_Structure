#include<bits/stdc++.h>
using namespace std;

class Graph
{
    //Adjacency list
    vector<pair<int,int>> *l;
    int v;
public:
    Graph(int n)
    {
        v=n;
        l=new vector<pair<int,int>>[n];
    }
    void addedge(int x,int y,int w)
    {
        l[x].push_back({y,w});
        l[y].push_back({x,w});
    }
    int prims()
    {
        //initialize min heap
        priority_queue<pair<int,int> ,vector<pair<int,int>>, greater<pair<int,int>>> pq;
        // visited array that denotes whether a node is visited or not
        bool visited[v];
        for(int i=0;i<v;i++)
            visited[i]=0;
        //begin
        pq.push({0,0});//weight, node
        int ans=0;
        while(!pq.empty())
        {
            auto best=pq.top();
            pq.pop();

            int to=best.second;
            int weight=best.first;

            if(visited[to])
            {
                //discard the edge,and continue
                continue;
            }
            //otherwise take the current edge
            ans+=weight;
            visited[to]=1;
            //add the new edge in the queue
            for(auto i:l[to])
            {
                if(visited[i.first]==0)
                {
                    pq.push({i.second,i.first});
                }
            }
        }
        return ans;
    }
};
int main()
{
    /*
    Graph g(6);
    g.addedge(0,1,1);
    g.addedge(1,3,3);
    g.addedge(3,2,4);
    g.addedge(2,0,2);
    g.addedge(0,3,2);
    g.addedge(1,2,2);
    */
    int n,m;
    cin>>n>>m;
    Graph g(n);
    for(int i=0;i<m;i++)
    {
        int a,b,c;
        cin>>a>>b>>c;
        g.addedge(a-1,b-1,c);
    }
    cout<<g.prims()<<endl;
    return 0;
}
