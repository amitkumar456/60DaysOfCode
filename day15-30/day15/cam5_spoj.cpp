#include<iostream>
#include<vector>
using namespace std;
const int N=1e5+5;
vector<int> adj[N];
bool vis[N];

void dfs(int src){
    vis[src]=1;
    for(int x:adj[src]){
        if(!vis[x])
        dfs(x);
    }
}
int main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
    int test=1;
    cin>>test;
    while(test--){
        int n,m;cin>>n>>m;
        
        for(int i=0;i<n;i++){
        vis[i]=false;
        adj[i].clear();
        }

        for(int i=0;i<m;i++){
            int u,v;cin>>u>>v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        int cnt=0;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(i);
                cnt++;
            }
        }
        cout<<cnt<<endl;
    }
}