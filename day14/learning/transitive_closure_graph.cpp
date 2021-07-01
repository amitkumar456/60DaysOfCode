#include<iostream>

using namespace std;
#define v 4

void printSolution(int reach[][v]){
for(int i=0;i<v;i++){
    for(int j=0;j<v;j++){
    if(i==j)
    cout<<"1 ";
    else 
    cout<<reach[i][j]<<" ";
    }
    cout<<endl;
}
}
void transitiveClosure(int graph[][v]){
int reach[v][v],i,j,k;

for(i=0;i<v;i++)
    for(j=0;j<v;j++)
    reach[i][j]=graph[i][j];

for(int k=0;k<v;k++){
    for(int i=0;i<v;i++){
        for(int j=0;j<v;j++){
        reach[i][j]=reach[i][j] || (reach[i][k] && reach[k][j]);
        }
    }
}


printSolution(reach);
}
int main(){

    int graph[v][v]={   {1, 1, 0, 1},
                        {0, 1, 1, 0},
                        {0, 0, 1, 1},
                        {0, 0, 0, 1}
                    };
    transitiveClosure(graph);
    return 0;
 
}