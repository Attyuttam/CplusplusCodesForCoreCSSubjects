#include<iostream>
using namespace std;
struct node{
    int data;
    node *lchild;
    node *rchild;
};
node *root=NULL;
node *pa=NULL;
int flag=0;
void search(int el,node *temp){
    if(temp && flag==0){
        if(temp->data==el){
            pa=temp;
            flag=1;
        }
        else{
            search(el,temp->lchild);
            if(flag==0){
            search(el,temp->rchild);
            }

        }
    }
}
void pre(node *temp){
    if(temp){
        cout<<temp->data<<" ";
        pre(temp->lchild);
        pre(temp->rchild);
    }
}
int main(){
    int el,i,n1;
    char ch;
    cout<<"Enter parent node data: ";
        cin>>el;
        node *n=new node;
        n->data=el;
        n->lchild=NULL;
        n->rchild=NULL;
        root=n;
    while(1){

        cout<<"\nEnter the node whose siblings you want to create: ";
        cin>>el;
        flag=0;
        search(el,root);
        node *temp=pa;
        if(pa!=NULL){


            if(temp->lchild!=NULL){
                temp=temp->lchild;
                while(temp->rchild!=NULL){
                    temp=temp->rchild;
                }

            }
            else{
                cout<<"\nThis parent has no children yet, enter data of first child: ";
                cin>>el;
                node *n=new node;
                n->data=el;
                n->lchild=NULL;
                n->rchild=NULL;
                pa->lchild=n;
                temp=pa->lchild;
            }
            cout<<"\nEnter the number of siblings that you want to enter: ";
            cin>>n1;
            int i=1;
            while(i<=n1){
                cout<<"\nEnter the data: ";
                cin>>el;
                node *n=new node;
                n->data=el;
                n->lchild=NULL;
                n->rchild=NULL;
                temp->rchild=n;
                temp=temp->rchild;
                i++;
            }
        }
        else{
            cout<<"\nNo such node exists";
        }
        cout<<"\nEnter y to continue: ";
        cin>>ch;
        if(ch=='y'||ch=='Y'){
            continue;
        }
        else{
            cout<<endl<<"The generic tree in binary form: \n";
            pre(root);
            cout<<endl;

            cout<<"\nEnter the node whose siblings is to be found: ";
            cin>>el;
            flag=0;
            search(el,root);
            if(pa!=NULL){
                node *t=pa;
                int c=1;
                while(t->rchild!=NULL){
                    t=t->rchild;
                    c++;
                }

                cout<<"\nThe number of siblings of "<<pa->data<<" is: "<<c;

            }
            else{
                cout<<"No such node exists";
            }

            break;
        }
    }
}
