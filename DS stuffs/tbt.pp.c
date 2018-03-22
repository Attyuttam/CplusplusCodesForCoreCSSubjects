#include<iostream>
using namespace std;

struct node{
    char data;
    node *lchild;
    node *rchild;
    bool lm;
    bool rm;
};

node *header=NULL;
node *findsuc(node *temp){
    if(temp->rm==1)
        return temp->rchild;
    else{
        t=temp->rchild;
        while(t->lm==0){
            t=t->lchild;
        }
        return t;
    }
    return NULL;
}
void searchparent(int el){
    node *temp=header->lchild;
    while(temp->lm==0){
        temp=temp->lchild;
    }
    while(temp!=header){
        if(temp->lchild->data==el || temp->rchild->data==el ){
            return temp;
        }
        else{
            temp=findsuc(temp);
        }
    }
    return NULL;

}
void display(){
    node *temp=header->lchild;
    while(temp->lm==0){
        temp=temp->lchild;
    }
    while(temp!=header){
        cout<<temp->data;
        temp=findsuc(temp);
    }
}
int main(){
    header=new node;
    header->data=NULL;
    header->lm=0;
    header->rm=0;
    header->rchild=header;
    header->lchild=NULL;

    int el,ch;
    int pa;
    while(1){
        cout<<"Enter the value of the node: ";
        cin>>el;
        cout<<"Enter the value of the parent node: ";
        cin>>pa;
        node *p=searchparent(pa);
        if(p){
            node *n=new node;
            n->data=el;
            n->lchild=NULL;
            n->rchild=NULL;
            if(p->lchild && p->rchild){
                cout<<"Enter 1 for insertion at first child, 2. for insertion at second child: ";
                cin>>ch;
            }
            else if(p->lchild){
                cout<<"Inserting at left child"<<endl;
                ch=1;
            }
            else if(p->rchild){
                cout<<"Inserting at right child"<<endl;
                ch=2;
            }
            //insertion
            if(ch==1){
                    //case 1: if left child is a thread
                    if(p->lm==1){
                        n->lchild=p->lchild;
                        n->lm=1;
                        p->lm=0;
                        n->rm=1;
                        n->rchild=p;
                    }
                    else{//case 2: if left child is a link
                        n->lchild=pa->lchild;
                        pa->lchild=n;
                        n->lm=0;
                        n->rm=1;
                        node *temp=n->lchild;
                        while(temp->rchild){
                            temp=temp->rchild;
                        }
                        temp->rchild=n;
                        n->rchild=pa;

                    }

            }
            else if(ch==2){
                    //case 1: if right child is a thread
                    if(p->rm==1){
                        n->rchild=p->rchild;
                        n->rm=1;
                        p->rm=0;
                        n->lm=1;
                        n->lchild=p;
                    }
                    else{//case 2: if right child is a link
                        n->rchild=pa->rchild;
                        pa->rchild=n;
                        n->rm=0;
                        n->lm=1;
                        node *temp=n->rchild;
                        while(temp->lchild){
                            temp=temp->lchild;
                        }
                        temp->lchild=n;
                        n->lchild=pa;

                    }

            }
        }
        cout<<"Enter 1 to exit : ";
        cin>>ch;
        if(ch==1)
            break;
    }



    }
}
