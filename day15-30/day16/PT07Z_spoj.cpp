#include<iostream>
#include<vector>
#include<queue>
#include<bits/stdc++.h>

using namespace std;
const int N=1e4+1;
vector<int> adj[N];
bool vis[N];
int dist[N]={0};
long long ans=0;

void dfs(int src){
    vis[src]=1;
    for(int x: adj[src])
    if(!vis[x])
    dfs(x);
}
int bfs(int src){
queue<int> q;
q.push(src);
memset(vis, 0,sizeof(vis));
memset(dist,0,sizeof(dist));
while(!q.empty()){
    int x=q.front();
    q.pop();
    vis[x]=1;
    for(int i:adj[x]){
        if(!vis[i]){
            vis[i]=1;
            q.push(i);
            dist[i]=dist[x]+1;
        }
    }
}
int co=max_element(dist+1,dist+10001)-dist;
ans=dist[co];
return co;
}
int main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
    int n;cin>>n;
        for(int i=1;i<=n;i++){
            adj[i].clear();
            vis[i]=false;
        }
       for(int i=1;i<n;i++){
        int u,v;cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    bfs(bfs(1));
    cout<<ans<<endl;
    return 0;
}