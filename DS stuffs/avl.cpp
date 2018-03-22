#include<iostream>
#include<cmath>
using namespace std;
struct node{
    int data;
    node *lchild;
    node *rchild;
};
node *root=NULL;
node *unbal=NULL;
node *pa=NULL;
int flag=0;
int flagp=0;
void insert_BST(node *n,node *temp){

    if(n->data<temp->data){
        if(temp->lchild)
            insert_BST(n,temp->lchild);
        else
            temp->lchild=n;
    }
    else if(n->data>temp->data){
        if(temp->rchild)
            insert_BST(n,temp->rchild);
        else
            temp->rchild=n;
    }
}
int max(int a,int b){
    if(a>b){
        return a;
    }
    else{
        return b;
    }
}
int height(node *temp){
        if(!temp)
            return 0;
        else{
            return max(height(temp->lchild),height(temp->rchild))+1;
        }

}
void check_balance(node *temp){
    if(!temp){
        return;
    }
    int lh=height(temp->lchild);
    int rh=height(temp->rchild);
    //cout<<"\nlh= "<<lh<<" and rh= "<<rh;
    if(abs(lh-rh)<=1 && flag!=1){
        check_balance(temp->lchild);
        if(flag!=1){
               // cout<<"\n temp is: "<<temp->data;
            check_balance(temp->rchild);
        }
    }
    else{
        if(flag==0){
            unbal=temp;
            flag=1;
        }
    }
}
void search_parent(int el,node *temp){
    if(temp && flagp==0){
       if(temp->lchild || temp->rchild) {
            if(temp->lchild!=NULL && flagp==0){
                if((temp->lchild)->data==el){
                    pa=temp;
                    flagp=1;
                }
            }
            if(temp->rchild!=NULL && flagp==0){
                if((temp->rchild)->data==el){
                    pa=temp;
                    flagp=1;
                }
            }
       }
        if(flagp==0)
            search_parent(el,temp->lchild);
        if(flagp==0)
            search_parent(el,temp->rchild);
    }
}
void right_rot(node *axle){
    flagp=0;
    search_parent(axle->data,root);
    pa->lchild=NULL;
    pa->lchild=axle->rchild;
    axle->rchild=pa;
    if(pa==root){
        root=axle;
    }
    else{
            node *temp=pa;
            flagp=0;
            search_parent(pa->data,root);

            if(pa->lchild==temp){
                pa->lchild=axle;
            }
            else{
                pa->rchild=axle;
            }
    }
    pa=NULL;
}
void left_rot(node *axle){
    flagp=0;
    search_parent(axle->data,root);
    pa->rchild=NULL;
    pa->rchild=axle->lchild;
    axle->lchild=pa;
    if(pa==root){
        root=axle;
    }
    else{
            node *temp=pa;
            flagp=0;
            search_parent(pa->data,root);
            if(pa->lchild==temp){
                pa->lchild=axle;
            }
            else{
                pa->rchild=axle;
            }
    }
    pa=NULL;
}
void pre(node *temp){
    if(temp){

        cout<<temp->data<<" ";
        pre(temp->lchild);
        pre(temp->rchild);
    }
}
void insert_AVL(node *n){
    insert_BST(n,root);
    cout<<endl;pre(root);cout<<endl;
    unbal=NULL;
    flag=0;
    check_balance(root);
    if(unbal!=NULL)
        cout<<"unbal: "<<unbal->data<<endl;
    while(unbal!=NULL){

        int lh=height(unbal->lchild);
        int rh=height(unbal->rchild);
        //the left left and right left condition
        if(lh>rh){
            //cout<<unbal->data;
            node *axle=unbal->lchild;
            lh=height(axle->lchild);
            rh=height(axle->rchild);
            if(lh>rh){//left-left condition
                right_rot(axle);
            }
            else{//right-left condition
                left_rot(axle->rchild);
                flagp=0;
                search_parent(axle->data,root);
                right_rot(pa);
                 //cout<<endl<<"yo: ";pre(root);cout<<endl;
            }
        }
        else{
            //the right right and left right condition
            node *axle=unbal->rchild;
            lh=height(axle->lchild);
            rh=height(axle->rchild);
            if(lh<rh){//left-left condition
                left_rot(axle);
            }
            else{//right-left condition
                right_rot(axle->lchild);
                flagp=0;
                search_parent(axle->data,root);
                left_rot(pa);
                 //cout<<endl<<"yo: ";pre(root);cout<<endl;
            }
        }
        unbal=NULL;
        flag=0;
        check_balance(root);
           /* pre(root);
            if(unbal->data==7)
                    break;*/
    }

}

int main(){
    int el;
    char ch;
    cout<<"Enter the root data: ";
    cin>>el;
    node *n =new node;
    n->data=el;
    n->lchild=NULL;
    n->rchild=NULL;
    root=n;
    while(1){

        cout<<"Continue: ?(y)";
        cin>>ch;
        if(ch=='y'||ch=='Y'){

            cout<<"Enter the data: ";
            cin>>el;
            node *n=new node;
            n->data=el;
            n->lchild=NULL;
            n->rchild=NULL;
            insert_AVL(n);
        }
        else{
            break;
        }
    }
    pre(root);
}
