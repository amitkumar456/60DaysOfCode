#include<iostream>
#include<vector>
#include<queue>
using namespace std;

const int N=1e+2;
vector<int> adj[N];
bool vis[N];

void bfs(int node){
queue<int> q;
q.push(node);
vis[node]=true;
while(!q.empty()){
    int x=q.front();
    q.pop();
    cout<<x<<endl;
    vector<int> :: iterator it;
    for(it=adj[x].begin();it!=adj[x].end();it++)
        if(!vis[*it]){
            vis[*it]=1;
            q.push(*it);
            }
}
}

int main(){
int n,m;
cin>>n>>m;
for(int i=0;i<n;i++)
vis[i]=0;
int x,y;
for(int i=0;i<m;i++){
    cin>>x>>y;
    adj[x].push_back(y);
    adj[y].push_back(x);
}

bfs(1);
return 0;

}