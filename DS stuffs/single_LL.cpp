#include<iostream>
using namespace std;
struct node{
    int value;
    node *next;
};
node *head=NULL;
int count=0;
void display(){

    node *temp;
    temp=head;
    if(temp!=NULL){
            while(temp!=NULL){
                cout<<temp->value<<" ";
                temp=temp->next;
            }
    }
    else{
        cout<<"The list is empty";
    }

}
void delete_val(int pos){
    if(pos<=count){
        int i=1;
        node *temp;
        temp=head;
        if(pos==1){
            head=head->next;
        }
        else{
                while(i<(pos-1)){
                temp=temp->next;
                i++;
                }
                temp->next=(temp->next)->next;
        }

        count--;
    }
    else{
        cout<<"Invalid position";
    }
}
void enter_val(int val,int pos){
            node *temp;
            if(pos<=(count+1)){

                    if(head==NULL){
                        node *n1=new node;
                        n1->value=val;
                        n1->next=NULL;
                        head=n1;

                    }
                    else{
                        if(pos==1){
                                node *n1=new node;
                                n1->next=head;
                                n1->value=val;
                                head=n1;
                        }
                        else{
                            temp=head;
                            int i=1;

                            while(i<(pos-1)){
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
                cout<<"\n number of nodes is: "<<count<<" so, max position can be "<<count+1;
            }


}
void disp_part(int pos){
    node *temp;
    temp=head;
    int i=1;
    if(temp!=NULL && pos<=count){
        while(i<pos){
            temp=temp->next;
            i++;
        }
        cout<<temp->value;
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
