#include<iostream>
#include<vector>
#include<queue>

using namespace std;
#define mod 1000000007
#define ll long long
const int N=1e4+1;
vector<int> adj[N];
//bool vis[N];
int memo[N];
ll dfs(int src,int t){
//vis[src]=1;
//cout<<src<<endl;
if(src==t)
return 1;
if(memo[src]!=-1)
return memo[src];
ll ways=0;
for(int child:adj[src]){
    ways+=dfs(child,t);
    ways%=mod;
}
memo[src]=ways;
return memo[src];
}
void solve(){
int c,b,s,t;cin>>c>>b>>s>>t;
for(int i=0;i<c;i++){
    adj[i].clear();
//   vis[i]=0;
    memo[i]=-1;
}
for(int i=0;i<b;i++){
    int x,y;cin>>x>>y;
    adj[x].push_back(y);
}
cout<<dfs(s,t)<<endl;
}

int main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
    int test=1;
    cin>>test;
    while(test--){
        solve();
    }
    return 0;
}

