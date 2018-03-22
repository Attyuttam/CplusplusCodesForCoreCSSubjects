#include<iostream>
#include<stdlib.h>
using namespace std;
struct node{
    int data;
    node *lchild;
    node *rchild;
};
node *root=NULL;
int preindex=0;
int FindPreinIn(int in[],int x){
    int j=0;
    while(in[j]!=x){
        j++;
    }

    return j;
}
node* maketree(int pre[],int in[],int beg,int end){
    if(beg<=end){

        node *n=new node;
        n->data=pre[preindex];

        int Inindex=FindPreinIn(in,pre[preindex]);
        preindex++;
        n->lchild=maketree(pre,in,beg,Inindex-1);
        n->rchild=maketree(pre,in,Inindex+1,end);
        return n;
    }
    else{
        return NULL;
    }
}
void post(node *temp){
    if(temp){

        post(temp->lchild);
        post(temp->rchild);
        cout<<temp->data<<" ";
    }
}
int  main(){
    int n;
    cout<<"\nEnter the number of nodes: ";
    cin>>n;
    int *pre=(int*)malloc(n*sizeof(int));
    int *in=(int*)malloc(n*sizeof(int));
    cout<<"\nEnter pre order traversal:\n";
    for(int i=0;i<n;i++){
        cin>>pre[i];
    }
    cout<<"\nEnter In order traversal:\n";
    for(int i=0;i<n;i++){
        cin>>in[i];
    }
    cout<<"\nThe pre order traversal is: ";
    for(int i=0;i<n;i++){
        cout<<pre[i]<<" ";
    }
    cout<<"\nThe In order traversal is: ";
    for(int i=0;i<n;i++){
        cout<<in[i]<<" ";
    }
    root=maketree(pre,in,0,n-1);
    cout<<endl;
    post(root);
}
