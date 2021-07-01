#include<iostream>
#include<vector>
#include<stack>
#include<queue>
using namespace std;
bool iscycle(int src, vector<vector<int>> &adj,vector<bool> &visited,vector<int> &stack){
    stack[src]=true;
    if(!visited[src]){
        visited[src]=true;
        for(auto i:adj[src]){
            if(!visited[i] and iscycle(i,adj,visited,stack))
                return true;
            if(stack[i])
             return true;  
}
}
stack[src]=false;
return false;
}



int main(){
    int n,m;
    cin>>n>>m;
    int u,v;
    vector<vector<int>> adj(n);
    for(int i=0;i<m;i++){
        cin>>u>>v;
        adj[u].push_back(v);
    }
    bool cycle=false;
    vector<int> stack(n,0);
    vector<bool> visited(n,0);

   for(int i=0;i<n;i++){
       if(!visited[i] and iscycle(i,adj,visited,stack)){
           cycle=true;
           break;
       }
   }

    if(cycle)
    cout<<"cycle is present";
    else
    cout<<"cycle is not present";


    return 0;
}