#include<iostream>
using namespace std;
struct node{
    int data;
    node *left;
    node *right;
};
node *root=NULL;
int front_q=-1;
int rear_q=-1;
node* q[20];
int queuenotempty(){
    if(front_q!=-1){
        return 1;
    }
    else{
        return 0;
    }
}
int queuefull(){
    if(rear_q==19){
        return 1;
    }
    else{
        return 0;
    }
}
void enqueue(node* temp){
    if(queuefull()){
        cout<<"Cannot insert";
    }
    else{
        q[++rear_q]=temp;
        if(front_q==-1){
            front_q++;
        }
    }
}
node* dequeue(){
    if(queuenotempty()){
       node *temp=q[front_q];
       front_q++;
       if(front_q>rear_q){
            front_q=-1;
            rear_q=-1;
       }
       return temp;
    }
}
delete_q(){
    front_q=-1;
    rear_q=-1;
}
void insert_node(int el){
    node *n=new node;
    n->data=el;
    n->left=NULL;
    n->right=NULL;
    if(root==NULL){
        root=n;
    }
    else{
        enqueue(root);
        while(queuenotempty()){
            node *temp=dequeue();
            if(temp->left==NULL){
                temp->left=n;
                delete_q();
                cout<<"inserted value: "<<(temp->left)->data<<endl;
                break;
            }
            else{
                enqueue(temp->left);
            }
            if(temp->right==NULL){
                temp->right=n;
                delete_q();
                cout<<"inserted value: "<<(temp->right)->data<<endl;
                break;
            }
            else{
                enqueue(temp->right);
            }
        }
    }
}
void levelorder(){
    node *temp=root;
    delete_q();
    enqueue(root);
    enqueue(NULL);
    cout<<endl;
    while(queuenotempty()){
        temp=dequeue();
        if(temp==NULL && queuenotempty()){
            cout<<endl;
            enqueue(NULL);
        }
        else if(queuenotempty()){
            cout<<temp->data<<" ";
            if(temp->left!=NULL){
                enqueue(temp->left);
            }
            if(temp->right!=NULL){
                enqueue(temp->right);
            }

        }

    }
}
void pre(node *temp){
    if(temp!=NULL){
        cout<<temp->data<<" ";
        pre(temp->left);
        pre(temp->right);
    }
}
int main(){
    int n,el;
    cout<<"Enter the number of children that you want to enter: ";
    cin>>n;
    for(int i=0;i<n;i++){
        cout<<"Enter the data of the node: ";
        cin>>el;
        insert_node(el);
    }
    cout<<"levelorder: "<<endl;
    levelorder();
    cout<<"preorder"<<endl;
    pre(root);
}
