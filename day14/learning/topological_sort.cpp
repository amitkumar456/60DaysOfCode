#include<iostream>
#include<vector>
#include<unordered_map>
#include<queue>
using namespace std;

const int N=1e5+2;
vector<int> adj[N];
bool vis[N];
unordered_map<int,int>in_deg;
int n,m;

void topological_sort(){
queue<int> pq;
for(int i=0;i<n;i++){
    if(in_deg[i]==0)
    pq.push(i);
}
int cnt=0;
while(!pq.empty()){
    cnt++;
    int x=pq.front();
    pq.pop();
    cout<<x<<" ";
    for(auto it:adj[x]){
        in_deg[it]--;
        if(in_deg[it]==0)
        pq.push(it);

    }
}
}
int main(){
    cin>>n>>m;
    for(int i=0;i<n;i++)
    vis[i]=0;
    int u,v;
    for(int i=0;i<m;i++){
        cin>>u>>v;
        adj[u].push_back(v);
        in_deg[v]++;
    }
    topological_sort();

    return 0;
}