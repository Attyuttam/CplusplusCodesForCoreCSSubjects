#include<iostream>
#include<malloc.h>
using namespace std;
int searchmin(int *d,int *vi,int v){
 int min=1000;
 int minpos=0;
 for(int i=0;i<v;i++){
    if(d[i]<min && vi[i]==0){
        min=d[i];
        minpos=i;
    }
 }
 return minpos;
}
void dijkstra(int v,int **g){
    cout<<"The adjacency matrix of the graph that you have entered is: \n";
    for(int i=0;i<v;i++){
        for(int j=0;j<v;j++){
            cout<<g[i][j]<<" ";
        }
        cout<<endl;
    }
    //the algorithm starts from here
    int *d=(int*)malloc(sizeof(int)*(v));
    int *vi=(int*)malloc(sizeof(int)*(v));
    for(int i=0;i<v;i++){
        d[i]=g[0][i];
        vi[i]=0;
    }
    vi[0]=1;
    int x=1;
    while(x<=v){
        int mind=searchmin(d,vi,v);
        vi[mind]=1;
        for(int i=0;i<v;i++){
            if(vi[i]!=1){
                if(d[i]>d[mind]+g[mind][i]){
                    d[i]=d[mind]+g[mind][i];
                }
            }
        }
        x++;
    }
    cout<<endl;
    for(int i=0;i<v;i++){
        cout<<" "<<d[i];
    }

}
int main(){
    int v;
    cout<<"Enter the number of vertices: ";
    cin>>v;
    int**g;
    g=(int**)malloc(sizeof(int*)*v);
    //g=(int* *)malloc(sizeof(int*)*v);
    for(int i=0;i<v;i++){
        g[i]=(int *)malloc(sizeof(int)*v);
    }
    cout<<"Enter the data of the adjacency matrix:\n";
    for(int i=0;i<v;i++){
        for(int j=0;j<v;j++){
            cin>>g[i][j];
        }
    }
    dijkstra(v,g);
    return 0;
}
