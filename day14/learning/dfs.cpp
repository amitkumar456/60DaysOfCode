#include<iostream>
#include<vector>
using namespace std;

const int N=1e+2;
bool vis[N];
vector<int> adj[N];

void dfs(int node){
//preorder
vis[node]=1;
cout<<node<<" ";
vector<int> :: iterator it;
for(it =adj[node].begin();it!=adj[node].end();it++){
    if(!vis[*it]){
    dfs(*it);
    }
}
//power order
//cout<<node<<" ";
}

int main(){
    int n,m;
    cin>>n>>m;
    
    for(int i=0;i<=n;i++)
    vis[i]=false;
    int x,y;
    for(int i=0;i<m;i++){
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    dfs(1);
    return 0;
}