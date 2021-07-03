/*=============================================================================
#  Author:             amit meena
#  FileName:           test.cpp
#  Description:        /
=============================================================================*/

#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;
#define ll long long 

const int N=1e5+1;
vector<ll> adj[N];
bool vis[N];

ll size =0;
void dfs(int i){
    vis[i]=true;
    size++;
    //cout<<i<<" ";
    for(ll child:adj[i]){
        if(vis[child]==false)
        dfs(child);
    }
}

void solve(){
ll n,m;cin>>n>>m;

for(int i=1;i<=n;i++){
vis[i]=false;
adj[i].clear();
}


for(int i=0;i<m;i++){
    int u,v;cin>>u>>v;
    adj[u].push_back(v);
    adj[v].push_back(u);
}
ll c=0,r=1;
for(int i=1;i<=n;i++){
    size=0;
    if(vis[i]==false){
        dfs(i);
        c++;
        r=(r*size)%(1000000007); 
    }
}
cout<<c<<" "<<r<<endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
    ll test=1;
    cin>>test;
    while(test--){
        solve();
    }
    return 0;
}
