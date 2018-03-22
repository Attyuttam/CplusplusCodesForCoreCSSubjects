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
node* findsuc(node *temp){
    if(temp->rm==1)
        return temp->rchild;
    else{
        node *t=temp->rchild;
        while(t->lm==0){
            t=t->lchild;
        }
        return t;
    }
    return NULL;
}
node* searchparent(int el){
    node *temp=header->lchild;

    while(temp->lm==0){

        temp=temp->lchild;
    }
    while(temp!=header){
        if((temp->lchild->data==el && temp->lm==0) || (temp->rchild->data==el && temp->rm==0)){
            return temp;
        }
        else{
            temp=findsuc(temp);
        }
    }
    return NULL;

}
node *searchnode(char el){
    node *temp=header->lchild;

    while(temp->lm==0){

        temp=temp->lchild;
    }
    while(temp!=header){

        if(temp->data==el ){
            //cout<<"ex"<<temp->data<<endl;
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
        cout<<temp->data<<" ";
        temp=findsuc(temp);
    }
}
int main(){
    header=new node;
    header->data='*';
    header->lm=0;
    header->rm=0;
    header->rchild=header;
    header->lchild=NULL;

    char el;
    int ch;
    char pa;
    while(1){
            int choice;
            cout<<"1.Insertion "<<endl<<"2.Deletion"<<endl;
            cin>>choice;
    if(choice==1){
        cout<<"Enter the value of the node: ";
        cin>>el;
        if(header->lchild==NULL){
            node *n=new node;
            n->data=el;
            n->lchild=header;
            n->rchild=header;
            header->lchild=n;
            n->lm=1;//1 means thread
            n->rm=1;
            //cout<<"value: "<<n->data;

        }
        else{
            cout<<"Enter the value of the parent node: ";
            cin>>pa;
            node *p=searchnode(pa);
            //cout<<p->data;
            if(p){
                node *n=new node;
                n->data=el;
                n->lchild=NULL;
                n->rchild=NULL;
                //if(p->lm==1 && p->rm==1){
                    cout<<"Enter 1 for insertion at first child, 2. for insertion at second child: ";
                    cin>>ch;
                //}

            //insertion
                if(ch==1){
                    //case 1: if left child is a thread
                    if(p->lm==1){
                        n->lchild=p->lchild;
                        n->lm=1;
                        p->lm=0;
                        n->rm=1;
                        p->lchild=n;
                        n->rchild=p;
                    }
                    else{//case 2: if left child is a link
                            cout<<"yo";
                        n->lchild=p->lchild;
                        p->lchild=n;
                        n->lm=0;
                        n->rm=1;
                        node *temp=n->lchild;
                        while(temp->rm==0){
                            temp=temp->rchild;
                        }
                        temp->rchild=n;
                        n->rchild=p;

                    }

                }
                else if(ch==2){
                    //case 1: if right child is a thread
                    if(p->rm==1){
                        n->rchild=p->rchild;
                        n->rm=1;
                        p->rm=0;
                        n->lm=1;
                        p->rchild=n;
                        n->lchild=p;
                    }
                    else{//case 2: if right child is a link
                        n->rchild=p->rchild;
                        p->rchild=n;
                        n->rm=0;
                        n->lm=1;
                        node *temp=n->rchild;
                        while(temp->lm==0){
                            temp=temp->lchild;
                        }
                        temp->lchild=n;
                        n->lchild=p;

                    }

                }
        }
        else{
            cout<<"NO SUCH PARENT";
        }
     }
    }
    else if(choice==2){
        cout<<"Enter the data to be deleted: ";
        cin>>el;
        node *no=searchnode(el);
        if(no){
            if(no->data==header->lchild->data){
                cout<<"Cannot delete root element"<<endl;
            }
            else{
                node *p=searchparent(no->data);

            }


        }
        else{
            cout<<"no such node exists ";
        }
    }
    else{
        cout<<endl<<"Invalid choice";
        continue;
    }
        cout<<"Enter 1 to exit : ";
        cin>>ch;
        if(ch==1){
            cout<<endl<<"The tree is as: "<<endl;
                display();
            break;
        }

      }
   }


