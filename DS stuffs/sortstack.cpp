#include<iostream>
using namespace std;
int stack[4]={-10,8,2,-3};
int top=3;
void display(){
    int i=top;
    cout<<endl;
    while(i>=0){
        cout<<stack[i]<<endl;
        i--;
    }
}
void push(int x){
    stack[++top]=x;
}
int pop(){
    int x=stack[top];
    top--;
    return x;
}
void ins(int v){
    if(top==-1)
        push(v);
    else if(v>stack[top]){
        push(v);
    }
    else{
        int valint=pop();
        ins(v);
        push(valint);
    }
}
void reverse(){
    if(top!=-1){
        int val=pop();
        reverse();
        ins(val);
    }
}

int main(){
    display();
    reverse();
      display();
}

