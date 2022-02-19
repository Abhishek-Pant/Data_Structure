#include<bits/stdc++.h>
using namespace std;

template<typename T>
class Graph
{
    unordered_map<T,list<pair<T,int>>> m;
public:
    void addedge(T u,T v,int dist)
    {
        m[u].push_back(make_pair(v,dist));
        m[v].push_back(make_pair(u,dist));
    }
    void printlist()
    {
        for(auto i:m)
        {
            cout<<i.first<<"-->";
            for(auto j:i.second)
            {
                cout<<"("<<j.first<<","<<j.second<<") ";
            }
            cout<<endl;
        }
    }
    void ddiksha(T src)
    {
        unordered_map<T,int> dist;
        for(auto i:m)
        {
            dist[i.first]=INT_MAX;
        }
        set<pair<int,T>> s;
        dist[src]=0;
        //Make set to find a out node with he minimum distance
        s.insert(make_pair(0,src));

        while(!s.empty())
        {
            //find the pair at the front.
            auto p=*(s.begin());
            T node=p.second;
            int nodedist=p.first;
            s.erase(s.begin());
            // iterate over neighbours/childern of the current node
            for(auto childpair :m[node])
            {
                if(nodedist+childpair.second<dist[childpair.first])
                {
                    //cout<<nodedist<<" + "<<childpair.second<<" < "<<dist[childpair.first]<<endl;
                    // IN the set updation of a particular node is not possible
                    // we have to remove the old pair, and insert the new pair to simulation updation
                    T dest=childpair.first;
                    auto f=s.find(make_pair(dist[dest],dest));
                    if(f!=s.end())
                        s.erase(f);
                    dist[dest]=nodedist+childpair.second;
                    s.insert(make_pair(dist[dest],dest));
                }
            }
        }
        for(auto d:dist)
        {
            cout<<d.first<<" is located at distance of "<<d.second<<endl;
        }
    }
};
int main()
{

    Graph<int> g;
    g.addedge(1,2,1);
    g.addedge(1,3,4);
    g.addedge(2,3,1);
    g.addedge(3,4,2);
    g.addedge(1,4,7);
    //g.printlist();
    g.ddiksha(1);
    /*
    Graph<string> india;
    india.addedge("Amitsar","Delhi",1);
    india.addedge("Amitsar","Jaipur",4);
    india.addedge("Jaipur","Delhi",2);
    india.addedge("Jaipur","Mumbai",8);
    india.addedge("Bhopal","Agra",2);
    india.addedge("Mumbai","Bhopal",3);
    india.addedge("Agra","Delhi",1);
    //india.printlist();
    india.ddiksha("Amitsar");
    */
    return 0;
}
