#include<iostream>
using namespace std;
void push(int);
int pop();
int *tos,*p1,stack[5];
int main(){
    int value;
    tos=stack;
    p1=stack;
    do{
        cout<<"Enter a value: ";
        cin>>value;
        if(value==0){
            cout<<"value on top of stack is: "<<pop();
        }
        else{
            push(value);
        }
    }while(value!=-1);
}
void push(int value){
    tos++;
    if(tos>=(stack+5)){
            tos--;
        cout<<"cannot push, stack is full";
    }
    else{
        *tos=value;
    }
}
int pop(){
    if(p1==tos){
       cout<<"The stack is empty";
       return -1;
    }
    else{
        tos--;
        return *(tos+1);
    }
}
