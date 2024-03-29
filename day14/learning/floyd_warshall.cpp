//to final all pair shortes pahts.
//i.e. for every u,v in graph g, find the shortes path from u to v

#include<iostream>
#include<vector>
using namespace std; 
const int inf=1e9;


int main(){
    vector<vector<int>> graph={ {0,5,inf,10},
                                {inf,0,3,inf},
                                {inf,inf,0,1},
                                {inf,inf,inf,0}
    };

    int n=graph.size();
    vector<vector<int>> dist=graph;
    for(int k=0;k<n;k++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(dist[i][k]+dist[k][j]<dist[i][j]){
                    dist[i][j]=dist[i][k]+dist[k][j];
                }
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(dist[i][j]==inf)
            cout<<"INF ";
            else
            cout<<dist[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}