#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Graph
{
    map<int,list<pair<int,int>>> mp;
public:
    void addEdge(int a,int b,int w)
    {
        mp[a].push_back({b,w});
    }
    void printAdj()
    {
        for(auto it:mp)
        {
            cout<<it.first<<" ->";
            for(auto it2:it.second)
            {
                cout<<it2.first<<" "<<it2.second<<" ";
            }
            cout<<"\n";
        }
    }
    void dijkstra(int src)
    {
        map<int,int> dist;
        for(auto it:mp)
        {
            dist[it.first]=INT_MAX;
        }
        dist[src]=0;
        set<pair<int,int>> s;
        s.insert({dist[src],src});
        while(!s.empty())
        {
            auto p = *(s.begin());
            s.erase(s.begin());
            int node= p.second;
            int dist_node= p.first;
            for(auto it2:mp[node])
            {
                if(dist_node+it2.second<dist[it2.first])
                {
                    int dest=it2.first;
                    int dist_dest = dist[it2.first];
                    auto nd = s.find({dist_dest,dest});
                    if(nd!=s.end())
                    {
                        s.erase({dist_dest,dest});
                    }
                    dist[it2.first]=dist_node+it2.second;
                    s.insert({dist[it2.first],it2.first});
                }
            }
        }
        for(auto it3:dist)
        {
            cout<<it3.first<<" "<<it3.second<<endl;
        }
    }
};
int main()
{
        Graph g;
    g.addEdge(1,2,2);
    g.addEdge(1,3,4);
    g.addEdge(3,2,-3);
    cout<<"SDFDSF\n";
    g.printAdj();
    g.dijkstra(1);
}
