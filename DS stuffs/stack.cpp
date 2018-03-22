/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <iostream>
using namespace std;
int top=-1;
int stack[20];
void push(int el){
    if(top==19){
        cout<<"The stack is full";
    }
    else{
        stack[++top]=el;
    }
}
void pop(){
    if(top==-1){
        cout<<"The stack is empty";
    }
    else{
        cout<<"The popped element is : "<<stack[top];
        top--;
    }
}
void display(){
    for(int i=0;i<=top;i++){
        cout<<stack[i]<<" ";
    }
}
int main() {
	//code
	int el,ch;
	while(1){
	    cout<<"\n1.Push \n2.Pop \n3.Display \n4.Exit\nEnter your choice :";
	    cin>>ch;
	    if(ch==1){
	        cout<<"\nEnter the element: ";
	        cin>>el;
	        push(el);
	    }
	    else if(ch==2){
	        pop();
	    }
	    else if(ch==3){
	        display();
	    }
	    else if(ch==4){
	        break;
	   }
	   else{
	       cout<<"Wrong input";
	   }
	}
	return 0;
}
