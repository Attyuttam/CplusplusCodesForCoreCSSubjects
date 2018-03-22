#include<iostream>
using namespace std;
struct node{
    int coeff;
    node *next;
};
node *deg=NULL;
void create_poly(int co){
    node *n=new node;
    n->coeff=co;
    n->next=deg;
    deg=n;
}
void display_poly(){
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
int main(){
    int deg,co;
    cout<<"Enter the degree of the polynomial: ";
    cin>>deg;
    int i=0;
    while(i<=deg){
        cout<<"\nEnter the coeffecient of x^"<<i<<" : ";
        cin>>co;
        create_poly(co);
        i++;
    }

    display_poly();
    return 0;
}
