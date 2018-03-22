#include<iostream>
#include<malloc.h>
#include<stack>
using namespace std;

void BFS(int v,int **g){
    stack<int> s;
    cout<<"The adjacency matrix: \n";
    for(int i=0;i<v;i++){
        for(int j=0;j<v;j++){
            cout<<" "<<g[i][j];
        }
        cout<<endl;
    }
    //the algorithm
    int *visited=(int*)malloc(sizeof(int)*v);
    for(int j=0;j<v;j++){
            visited[j]=0;
        }
    s.push(0);
    while(!s.empty()){
        int x=s.top();
        s.pop();
        if(visited[x]==0){
            cout<<(char)(65+x)<<" ";
            visited[x]=1;
        }
        for(int i=0;i<v;i++){
            if(g[x][i]==1 && visited[i]==0){
                s.push(i);
            }
        }
    }
}
int main(){
    int v;
    cout<<"Enter the number of vertices in the graph: ";
    cin>>v;
    int **g;
    g=(int**)malloc(sizeof(int*)*v);
    for(int j=0;j<v;j++){
            g[j]=(int *)malloc(sizeof(int)*v);;
    }
    cout<<"Enter the adjacency matrix: \n";
    for(int i=0;i<v;i++){
        for(int j=0;j<v;j++){
            cin>>g[i][j];
        }
    }

    BFS(v,g);
}
