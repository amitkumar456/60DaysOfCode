#include<iostream>
#include<vector>
#include<queue>
#include<bits/stdc++.h>
#include<math.h>
#define ll long long

using namespace std;
const int N=5e5+1;
vector<int> adj[N];
int dist[N]={0};
bool vis[N];
int ans=0;

void dfs(int src){
    vis[src]=true;
    for(int x:adj[src]){
        if(!vis[x])
        dfs(x);
    }
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
        q.push(i);
        vis[i]=1;
        dist[i]=dist[x]+1;
        }         
    }    
    }
ll co=max_element(dist,dist+500001)-dist;
ans=dist[co];
return co;
}
int main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
    int test;
    cin>>test;
    while(test--){
        int n;cin>>n;
        for(int i=0;i<n;i++){
            adj[i].clear();
            vis[i]=false;
        }
        for(int i=1;i<n;i++){
            int u,v;cin>>u>>v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        bfs(bfs(1));
        cout<<(ans+1)/2<<endl;
    }
    

    return 0;
}