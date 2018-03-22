#include<iostream>
using namespace std;
struct node{
    int value;
    node *next;
};
node *head=NULL;
int count=0;
void display(){
    node *temp,*prev;
    prev=head;
    temp=prev->next;
    while(temp!=head){
        cout<<prev->value<<" ";
        prev=temp;
        temp=temp->next;

    }
    cout<<prev->value<<" ";
}
void delete_val(int pos){
    if(pos<=count){

        int i=1;
        node *temp;
        temp=head;
        if(pos==1){
            node *prev;
            prev=head;
            temp=prev->next;
            while(temp!=head){
                prev=temp;
                temp=temp->next;

            }
            prev->next=head->next;
            head=prev->next;
        }
        else{
            while(i<pos-1){
                temp=temp->next;
            }
            temp->next=(temp->next)->next;
        }
        count--;
    }
    else{
        cout<<"\nInvalid position";
    }
}
void enter_val(int val,int pos){
    if(pos<=(count+1)){
        if(head==NULL){
            node *n1=new node;
            n1->value=val;
            n1->next=n1;
            head=n1;
        }
        else{
                if(pos==1){
                    node *n1=new node;
                    n1->value=val;
                    n1->next=head;

                    node *temp,*prev;
                    prev=head;
                    temp=prev->next;
                    while(temp!=head){

                        prev=temp;
                        temp=temp->next;

                    }
                    prev->next=n1;
                    head=n1;
                }
                else{
                    int i=1;
                    node *temp;
                    temp=head;
                    while(i<pos-1){

                        temp=temp->next;
                        i++;
                    }

                node *n1=new node;
                n1->value=val;
                n1->next=temp->next;
                temp->next=n1;


                    }
            }

        count++;
    }
    else{
        cout<<"Invalid position";
    }

}
void disp_part(int pos){
    if(pos<=count){
        node *temp;
        temp=head;
        int i=1;
        while(i<pos){
            temp=temp->next;
            i++;
        }
        cout<<temp->value<<" ";
    }
    else{
        cout<<"Invalid position";
    }
}
int main(){
    int ch,val,pos;
    while(1){
        cout<<"\nnumber of nodes: "<<count;
        cout<<"\n1.Enter value at position\n2.Delete value from a position\n3.Display the list\n4.Display particular element\n5.Exit\nEnter your choice:  ";
        cin>>ch;
        if(ch==1){
            cout<<"\nEnter the value: ";cin>>val;
            cout<<"\nEnter the position: ";cin>>pos;
            enter_val(val,pos);
        }
        else if(ch==2){
            cout<<"\nEnter the position: ";cin>>pos;
            delete_val(pos);
        }
        else if(ch==3){
            display();

        }
        else if(ch==4){
            cout<<"Enter the position: ";
            cin>>pos;
            disp_part(pos);
        }
        else if(ch==5){
            break;
        }
        else{
            cout<<"\nWrong option";
        }
    }
}
