#include<iostream>
#include<bits/stdc++.h>
using namespace std;
vector<int> bellman_ford(int n,int src,vector<vector<int>> v)
{
    vector<int> dist(n+1,INT_MAX);
    dist[src]=0;
    for(int i=0;i<n-1;i++)
    {
      for(auto it:v)
      {
          int a=it[0],b=it[1],c=it[2];
          if(dist[b]>dist[a]+c)
          {
              dist[b]=dist[a]+c;
          }
      }
    }
    for(auto it3:v)
    {
                int a=it3[0],b=it3[1],c=it3[2];
          if(dist[b]>dist[a]+c)
          {
              cout<<"negative cycle detected\n";
          }
    }
    return dist;
}
int main()
{
    int n,m;
    cin>>n>>m;
    vector<vector<int>> v(m);
    for(int i=0;i<m;i++)
    {
        int a,b,w;
        cin>>a>>b>>w;
        v[i]={a,b,w};
    }
    vector<int> dist = bellman_ford(n,1,v);
    for(int i=1;i<=n;i++)
    {
        cout<<i<< " "<<dist[i]<<endl;
    }
}
