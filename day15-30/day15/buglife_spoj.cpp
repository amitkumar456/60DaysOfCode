#include<iostream>
#include<vector>
using namespace std;

#define ll long long
vector<vector<int>> adj;
vector<bool> vis;
bool bipart;
vector<int> col;

void color(int u,int curr){
    if(col[u]!=-1 and col[u]!=curr){
        bipart=false;
        return ;
    }
    col[u]=curr;
    if(vis[u])
    return;
    vis[u]=1;
    for(auto i:adj[u]){
    color(i,curr xor 1);
    }
}

void solve(){
ll t=0;
ll test;
cin>>test;
while(t++<test){
int n,m;cin>>n>>m;
adj=vector<vector<int>>(n+1);
vis=vector<bool>(n+1,false);
col=vector<int>(n+1,-1);
for(int i=1;i<=m;i++){
    int u,v;cin>>u>>v;
    adj[u].push_back(v);
    adj[v].push_back(u);
}
bipart=true;
for(int i=1;i<=n;i++){
    if(!vis[i])
        color(i,0);
}
cout<<"Scenario #"<<t<<":\n";
if(bipart)
cout<<"No suspicious bugs found!\n";
else
cout<<"Suspicious bugs found!\n";
}
}
int main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
solve();

return 0;
}