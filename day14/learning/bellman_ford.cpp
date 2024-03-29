//shortest distance to all other nodes in the graph
//also uses for negative nodes
//detect negative cycles as well

#include<iostream>
#include<bits/stdc++.h>
using namespace std;
const int inf=1e7;

int main(){

    int n,m;cin>>n>>m;
    vector<vector<int>> edges;
    for(int i=0;i<m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        edges.push_back({u,v,w});
        
    }
    int src;cin>>src;
    vector<int> dist(n,inf);
    dist[src]=0;
    for(int iter=0;iter<n-1;iter++){
        for(auto e:edges){
            int u=e[0];
            int v=e[1];
            int w=e[2];
            dist[v]=min(dist[v],w+dist[u]);
        }
    }
    for(auto i: dist)
        cout<<i<<" ";
    cout<<"\n";
    return 0;
}