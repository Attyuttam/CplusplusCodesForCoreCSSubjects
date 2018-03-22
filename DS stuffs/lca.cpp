#include<iostream>
using namespace std;
struct node{
    int data;
    node *left;
    node *right;
};
int flag=0;
node *root=NULL;
int front_q=-1;
int rear_q=-1;
node* q[20];
node* pa=NULL;
node* delnode=NULL;
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
void pre(node *temp){
    if(temp){
        cout<<temp->data<<" ";
        pre(temp->left);
        pre(temp->right);
    }
}
node *LCA(node *temp,int c1,int c2){
    if(!temp){
            return NULL;
    }
    else{
        if(temp->data==c1 ||temp->data==c2){
            return temp;
        }
        node *lf=LCA(temp->left,c1,c2);
        node *rf=LCA(temp->right,c1,c2);
        if(lf!=NULL && rf!=NULL){
            return temp;
        }
        else if(lf!=NULL && rf==NULL){
            return lf;
        }
        else{

            return rf;
        }


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
    pre(root);
    int c1,c2;
    cout<<"Enter child 1: ";
    cin>>c1;
    cout<<"Enter child 2: ";
    cin>>c2;
    node *t=LCA(root,c1,c2);
    cout<<"LCA: "<<t->data;

}
