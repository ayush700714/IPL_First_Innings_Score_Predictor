#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Graph
{
    map<int,list<int>> mp;
public:
    void addEdge(int a,int b)
    {
        mp[a].push_back(b);
    }
    void printEdge()
    {
        for(auto it:mp)
        {
            cout<<it.first<<"-> ";
            list<int> lp=it.second;
            for(auto it:lp)
            {
                cout<<it<<" ";
            }
            cout<<"\n";
        }
    }
    void dfs_helper(int src,map<int,bool> &visited)
    {
        visited[src] =true;
        list<int> nbrs = mp[src];
        cout<<src<<" ";
        for(auto it:nbrs)
        {
            if(!visited[it])
            {
                dfs_helper(it,visited);
            }
        }
    }
    void dfs()
    {
        map<int,bool> visited;
        for(auto it:mp)
        {
            visited[it.first]=false;
        }
        int count=0;
        for(auto it:mp)
        {
            if(!visited[it.first])
            {
                count++;
                        dfs_helper(it.first,visited);
            }
        }

        cout<<"\n";
        cout<<count<<endl;
    }
};
int main()
{
            Graph g;
    g.addEdge(0,1);
      g.addEdge(1,2);
      g.addEdge(2,3);
            g.addEdge(0,3);
      g.addEdge(0,4);
      g.addEdge(5,6);
      g.addEdge(6,7);
      g.addEdge(8,8);
      g.printEdge();
      g.dfs();
}
