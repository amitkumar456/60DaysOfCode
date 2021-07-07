//cycle detection in undirected graph
#include<iostream>
#include<vector>
using namespace std;
vector<vector<int>> adj;
vector<bool> visited;
bool iscycle(int src,vector<vector<int>> &adj,vector<bool> &visited,int parent){
    visited[src]=true;
    for(auto i:adj[src]){
        if(i!=parent){
            if(visited[i])
                return true;
            if(!visited[i] and iscycle(i,adj,visited,src)){
                return true;
            }
        }
    }
    return false;
}
int main(){
    int n,m;
    cin>>n>>m;
    adj=vector<vector<int>>(n+1);
    visited=vector<bool>(n+1,false);
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    bool cycle=false;
    
    for(int i=1;i<=n;i++){
        if(!visited[i] and iscycle(i,adj,visited,-1)){
            cycle=true;
            break;
        }

    }
    if(cycle)
    cout<<"NO\n";
    else
    cout<<"YES\n";

    return 0;
}