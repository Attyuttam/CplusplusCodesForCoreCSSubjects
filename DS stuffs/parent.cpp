#include<iostream>
using namespace std;
struct node{
    int data;
    node *lchild;
    node *mid;
    node *rchild;
};
node *root=NULL;
int frontp=-1;
int rear=-1;
node *Q[100];
int fparent=0;
int flag=0;
node* lookup[100];
int ltop=-1;

node* search(node *temp,int el){
    if(root->data==el){
        return NULL;//because root has no parent
    }
    if(temp!=NULL && flag==0 ){

            if(temp->lchild->data==el || temp->rchild->data==el){
                flag=1;
                return temp;
            }
            node *t;
            t=search(temp->lchild,el);
            if(flag==1){
                return t;
            }
            t=search(temp->rchild,el);
            if(flag==1){
                return t;
            }
            return NULL;
        }


    else{
        return NULL;
    }
}
int queuenotempty(){
    if(frontp!=-1){
        return 1;
    }
    else{
        return 0;
    }
}
void enqueue(node *temp){
    if(rear!=99){

        Q[++rear]=temp;
        if(frontp==-1){
            frontp++;
        }
    }
}
node* pop(){
    node *t=NULL;
    if(queuenotempty()){
        t=Q[frontp];
        frontp++;
        if(frontp>rear){
            frontp=-1;
            rear=-1;

        }

    }
       return t;

}
void create_tree(node *n){
    if(root==NULL){
        root=n;
    }
    else{

        enqueue(root);

        while(queuenotempty()){

            node *temp=pop();
           //cout<<temp->data;
            if(temp->lchild==NULL){
                temp->lchild=n;
                break;
            }
            else{
                enqueue(temp->lchild);
            }
            if(temp->rchild==NULL){
                temp->rchild=n;
                break;
            }
            else{
                enqueue(temp->rchild);
            }
        }
    }
}
void pre(node *temp){
    if(temp!=NULL){
        cout<<temp->data<<" ";
        pre(temp->lchild);
        pre(temp->rchild);
    }
}

void makeroot(node *parent,node *child){

    if(parent){

        flag=0;
        node* gparent=search(root,parent->data);

        if(child->lchild==NULL){
            child->lchild=parent;
            if(parent->lchild==child){
                parent->lchild=NULL;
            }
            else{
                parent->rchild=NULL;
            }
            child=parent;
            parent=gparent;
        }
        else if(child->rchild==NULL){
            child->rchild=parent;
            if(parent->lchild==child){
                parent->lchild=NULL;
            }
            else{
                parent->rchild=NULL;
            }
            child=parent;
            parent=gparent;
        }
        else if(child->mid==NULL){
            child->mid=parent;
            if(parent->lchild==child){
                parent->lchild==NULL;
            }
            else{
                parent->rchild==NULL;
            }
            child=parent;
            parent=gparent;
        }
        if(parent!=NULL)
            makeroot(parent,child);
    }
    else{
        return;
    }
}
void searchnode(node *temp,int el){
    if(temp){
        if(temp->data==el){

            flag=1;

        }
        searchnode(temp->lchild,el);
        searchnode(temp->rchild,el);
    }

}
int main(){
    int n,el;
    cout<<"Enter the number of nodes: ";
    cin>>n;
    for(int i=1;i<=n;i++){
        cout<<"Enter the data: ";
        cin>>el;
        node *n= new node;
        n->data=el;
        n->rchild=NULL;
        n->lchild=NULL;
        n->mid=NULL;
         frontp=-1;
        rear=-1;
        create_tree(n);
    }
    pre(root);
    cout<<"\nEnter the node that you want to make as root: ";
    cin>>el;
    searchnode(root,el);
    if(flag==1){
        flag=0;
        node *temp=search(root,el);
        if(temp){
            node *child;
            if(temp->lchild->data==el){
                child=temp->lchild;
                makeroot(temp,temp->lchild);
            }
            else if(temp->rchild->data==el){
                child=temp->rchild;
                makeroot(temp,temp->rchild);
            }
            root=child;
            pre(root);
        }
        else{
            cout<<"parent does not exist";
        }
    }
    else{
        cout<<"invalid node";
    }
}
