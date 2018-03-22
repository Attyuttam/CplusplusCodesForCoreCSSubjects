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
node* levelorder(){
    node *temp=root;
    delete_q();
    enqueue(root);
    cout<<endl;
    while(queuenotempty()){
        temp=dequeue();
        cout<<temp->data<<" ";
        if(temp->left!=NULL){
            enqueue(temp->left);
        }
        if(temp->right!=NULL){
            enqueue(temp->right);
        }
    }
    return temp;
}
void pre(node *temp){
    if(temp!=NULL){
        cout<<temp->data<<" ";
        pre(temp->left);
        pre(temp->right);
    }
}
void search(int el,node *temp){
    if(temp!=NULL && flag==0){
        if(temp->data==el){
            delnode=temp;
            flag=1;
        }
        else{
            search(el,temp->left);
            if(flag==0){
            search(el,temp->right);
            }

        }
    }
}
void search_parent(int el,node *temp){
    if(temp && flag==0){
       if(temp->left || temp->right) {
        if(temp->left!=NULL && flag==0){

                if((temp->left)->data==el){
                    pa=temp;
                    flag=1;
                }
        }
        if(temp->right!=NULL && flag==0){

                if((temp->right)->data==el){

                    pa=temp;
                    flag=1;
                }
        }
       }
            if(flag==0)
                search_parent(el,temp->left);
            if(flag==0)
                search_parent(el,temp->right);



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
    node* temp=levelorder();
     flag=0;
    // cout<<"this: "<<temp->data;
    pa=NULL;
    search_parent(temp->data,root);//pa has the parent of the last node;
    //cout<<pa->data;
    if(pa->left==temp){pa->left=NULL;}
    else if(pa->right==temp){pa->right=NULL;}
    cout<<"Enter the data that you want to delete: ";
    cin>>el;

    flag=0;
    search(el,root);//delnode has the node to be deleted
   flag=0;
    search_parent(delnode->data,root);//pa will have the parent of the node to be deleted
    //cout<<"parent of the node to be deleted: "<<pa->data;
    //cout<<"the node to be deleted: "<<delnode->data;
    if(pa->left==delnode)
        pa->left=temp;
    else
        pa->right=temp;
    temp->left=delnode->left;
    temp->right=delnode->right;
    temp=levelorder();

}
