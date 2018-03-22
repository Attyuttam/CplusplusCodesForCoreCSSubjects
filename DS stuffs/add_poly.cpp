#include<iostream>
using namespace std;
struct node{
    int coeff;
    node *next;
};
node *deg1=NULL;
node *deg2=NULL;
node *deg3=NULL;
node* create_poly(int co,node *deg){
    node *n=new node;
    n->coeff=co;
    n->next=deg;
    deg=n;
    return deg;
}
void display_poly(node *deg){
    node *temp;
    temp=deg;
    int i=-1;

    while(temp!=NULL){
        i++;
        temp=temp->next;
    }

    temp=deg;
    while(temp->next!=NULL){

        cout<<temp->coeff<<"*x^"<<i<<"+";
        temp=temp->next;
        i--;
    }
    cout<<temp->coeff;
}
void add-poly(node*deg1)
int main(){
    int deg,co;
    cout<<"Enter the degree of the first polynomial: ";
    cin>>deg;
    int i=0;
    while(i<=deg){
        cout<<"\nEnter the coeffecient of x^"<<i<<" : ";
        cin>>co;
        deg1=create_poly(co,deg1);

        i++;
    }
    cout<<"\nThe first polynomial you have created is: ";
    display_poly(deg1);
    cout<<"\nEnter the degree of the second polynomial: ";
    cin>>deg;
    i=0;
    while(i<=deg){
        cout<<"\nEnter the coeffecient of x^"<<i<<" : ";
        cin>>co;
        deg2=create_poly(co,deg2);
        i++;
    }
    cout<<"\nThe second polynomial you have created is: ";
    display_poly(deg2);
    add_poly(deg1,deg2);
    return 0;
}
