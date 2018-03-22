#include<iostream>
using namespace std;
int stack[10];
int top=-1;
void push(int x){
    if(top!=9){
        stack[++top]=x;
    }

}
int pop(){
    if(top!=-1){
        int c=stack[top];
        top--;
        return c;
    }
}
void rev(){
    if(top!=-1){

        int x=pop();
        rev();
        push(x);
    }
}
int main(){
        int ch,n;

        cout<<"press 0 to exit";

        while(top!=9 || n==0){

            cout<<"\nEnter value: ";
            cin>>n;
            if(n==0){
                break;
            }
            push(n);
        }
        cout<<"\nReversing the stack\n";
        rev();
        int i=top;
        while(i!=-1){
            cout<<stack[i]<<" ";
            i--;
        }
}
