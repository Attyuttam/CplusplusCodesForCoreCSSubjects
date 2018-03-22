#include<iostream>
using namespace std;
struct node{
    int data;
    node* lchild;
    node *rchild;
};
node *root1=NULL;
node *root2=NULL;
void pre(node *temp){
    if(temp){
        cout<<temp->data<<" ";
        pre(temp->lchild);
        pre(temp->rchild);
    }
}
bool check(node *temp1,node *temp2){
    if(temp1==NULL && temp2==NULL){

        return 1;
    }
    if(temp1==NULL && temp2!=NULL){
        return 0;
    }
    if(temp1!=NULL && temp2==NULL){
        return 0;
    }
    return (temp1->data==temp2->data)&&check(temp1->lchild,temp2->lchild)&&check(temp1->rchild,temp2->rchild);
}
int main(){

    //1 st binary tree
    node *n=new node;
    n->data=1;
    n->lchild=NULL;
    n->rchild=NULL;
    root1=n;
    n=new node;
    n->data=2;
    n->lchild=NULL;
    n->rchild=NULL;
    root1->lchild=n;
    n=new node;
    n->data=3;
    n->lchild=NULL;
    n->rchild=NULL;
    root1->rchild=n;
    pre(root1);
    //2nd binary tree
    n=new node;
    n->data=1;
    n->lchild=NULL;
    n->rchild=NULL;
    root2=n;
    n=new node;
    n->data=2;
    n->lchild=NULL;
    n->rchild=NULL;
    root2->lchild=n;
    n=new node;
    n->data=3;
    n->lchild=NULL;
    n->rchild=NULL;
    root2->rchild=n;
    n=new node;
    n->data=3;
    n->lchild=NULL;
    n->rchild=NULL;
    root2->rchild->rchild=n;
    cout<<endl;
    pre(root2);
    bool t=check(root1,root2);
    cout<<endl;
    if(t==1){
        cout<<"same";
    }
    else{
        cout<<"not same";
    }
}
