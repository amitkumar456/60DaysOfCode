#include<iostream>
#include<vector>

using namespace std;
int n,m;
const int N=1e5+2;
vector<int> adj[N];
bool vis[N];

void dfs(int node){
    vis[node]=1;
    cout<<node<<" ";
    
    vector<int> ::iterator it;
    for(it =adj[node].begin();it!=adj[node].end();it++)
    if(!vis[*it])
    dfs(*it);


}

void connected_component(){

    for(int i=0;i<n;i++)
        if(!vis[*adj[i].begin()]){
            dfs(*adj[i].begin());
            cout<<endl;
        }
}

int main(){

    cin>>n>>m;
    int u,v;
    for(int i=0;i<n;i++)
    vis[i]=0;
    for(int i=0;i<m;i++){
        cin>>u>>v;
        adj[v].push_back(u);
        adj[u].push_back(v);
    }

    connected_component();


    return 0;
}