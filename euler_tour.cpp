#include<iostream>
#include<bits/stdc++.h>
using namespace std;
vector<int> gr[100001];
    int timer=0;
int tin[10001],tout[10001];
void euler_tour1(int cur,int par)
{
    cout<<cur<<" ";
      tin[cur]=++timer;
    for(auto it:gr[cur])
    {
        if(it!=par)
        {
            euler_tour1(it,cur);
            cout<<cur<<" ";
        }
    }
      tout[cur]=++timer;
}
void euler_tour2(int cur,int par)
{
    cout<<cur<<" ";
    tin[cur]=++timer;
    for(auto it:gr[cur])
    {
        if(it!=par)
        {
            euler_tour2(it,cur);
        }
    }
    tout[cur]=++timer;
    cout<<cur<<" ";
}
void euler_tour3(int cur,int par)
{
        cout<<cur<<" ";
        tin[cur]=++timer;
    for(auto it:gr[cur])
    {
        if(it!=par)
        {
            euler_tour3(it,cur);
        }
    }
    tout[cur]=timer;
}
bool is_ancestor(int a,int b)
{
    if(tin[a]<=tin[b] && tout[a]>=tout[b])
    {
        cout<<"yes\n";
        return true;
    }
    else
    {
        cout<<"false\n";
        return false;
    }
}
int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n-1;i++)
    {
        int a,b;
        cin>>a>>b;
        gr[a].push_back(b);
        gr[b].push_back(a);
    }

    euler_tour3(1,0);
    cout<<"\n";
    for(int i=1;i<=n;i++)
    {
        cout<<i<<" "<<tin[i]<< " "<<tout[i]<<endl;
    }
    cout<<is_ancestor(1,8);
}
