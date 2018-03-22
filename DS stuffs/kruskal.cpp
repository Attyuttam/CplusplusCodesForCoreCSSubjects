#include<iostream>
#include<malloc.h>

using namespace std;

void krus(int v,int **g){
    int fresh[v][v];
    cout<<"The adjacency matrix: \n";
    for(int i=0;i<v;i++){
        for(int j=0;j<v;j++){
            cout<<" "<<g[i][j];
            fresh[i][j]=1000;
        }
        cout<<endl;
    }
     int n=1;
     while(n<v){
        //finding the minimum weight
        int min=g[0][0];
        int mini=0;
        int minj=0;
        for(int i=0;i<v;i++){
            for(int j=0;j<v;j++){
                if(g[i][j]<min){
                   // cout<<i<<" "<<j<<endl;
                    min=g[i][j];
                    mini=i;
                    minj=j;
                }
            }
        }
        fresh[mini][minj]=g[mini][minj];
        fresh[minj][mini]=g[minj][mini];
        g[mini][minj]=1000;
        g[minj][mini]=1000;

        n++;
     }
     //the adjacenecy matrix after making the changes
     cout<<"The spanning tree: \n";
    for(int i=0;i<v;i++){
        for(int j=0;j<v;j++){

            cout<<" "<<fresh[i][j];
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

    krus(v,g);
}
