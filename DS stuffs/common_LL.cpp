#include<iostream>
using namespace std;
struct node{
    int value;
    node *next;
};
node *head1=NULL;
node *head2=NULL;
node *head3=NULL;

void display(node *head){

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
node* enter_val(int val,int pos,node *head){
    node *n1=new node;

    if(head==NULL){

            n1->value=val;
            n1->next=NULL;
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
        n1->value=val;
        n1->next=NULL;
        temp->next=n1;
    }
    return head;
}
int disp_part(int pos,node *head){
    node *temp;
    temp=head;
    int i=1;
    if(temp!=NULL){
        while(i<pos){
            temp=temp->next;
            i++;
        }
        return temp->value;
    }
}



int main(){
    int n1,n2,val;
    cout<<"Enter the number of terms you want to enter into the first list: ";
    cin>>n1;
    for(int i=1;i<=n1;i++){
        cout<<"Enter term "<<i<<" : ";
        cin>>val;
        head1=enter_val(val,i,head1);
    }
    cout<<"Enter the number of terms you want to enter into the second list: ";
    cin>>n2;
    for(int i=1;i<=n2;i++){
        cout<<"Enter term "<<i<<" : ";
        cin>>val;
        head2=enter_val(val,i,head2);
    }
    cout<<"\nThe first list that you have entered is: \n";
    display(head1);
    cout<<"\nThe second list that you have entered is: \n";
    display(head2);
    int i=1,j=1,x=1;
    for(i=1;i<=n1;i++){
            for(j=1;j<=n2;j++){
                    if(disp_part(i,head1)==disp_part(j,head2)){
                        head3=enter_val(disp_part(i,head1),x,head3);
                        x++;
                        break;
                    }
            }

    }
    cout<<"\nThe final list is: \n";
    display(head3);
}

