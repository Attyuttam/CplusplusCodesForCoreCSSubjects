#include<iostream>
#include<malloc.h>
using namespace std;
void BFS(int v,int **g){
    cout<<"The adjacency matrix: \n";
    for(int i=0;i<v;i++){
        for(int j=0;j<v;j++){
            cout<<" "<<g[i][j];
        }
        cout<<endl;
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
