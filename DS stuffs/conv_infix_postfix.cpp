#include<iostream>
using namespace std;

int top=-1;
char stack[20];
int stack_empty()
{

    if(top==-1){
        return 1;
    }
    else{
        return 0;
    }
}
int stack_full(){
    if(top==19){
        return 1;
    }
    else{
        return 0;
    }
}
void push(char el){

    if(stack_full()){

        cout<<"Full";
    }
    else{

        stack[++top]=el;
    }
}
char pop(){
    if(stack_empty()){
        return 'a';
    }
    else{
        char el=stack[top];
        top--;
        return el;
    }
}
void disp(){
    for(int i=0;i<top;i++){
        cout<<stack[i];
    }
}
int priority(char op){
    if(op=='*'||op=='/'||op=='%'){
        return 13;
    }
    else if(op=='+'||op=='-'){
        return 12;
    }
   else
    return 0;

}
int main(){
        string inf;
        int len;
        cout<<"Enter an infix expression: ";
        cin>>inf;
        len=inf.length();
        int i=0;

        while(i<len){
                if(inf[i]=='('){
                    push(inf[i]);
                   }
            else if(inf[i]=='+'||inf[i]=='-'||inf[i]=='/'||inf[i]=='*'||inf[i]=='%'){
                while(top!=-1 && priority(inf[i])<=priority(stack[top]) && stack[top]!='('){
                        char el=pop();
                        if(el!='a'){
                         cout<<el;
                        }

                }
                push(inf[i]);
            }
            else if(inf[i]==')'){
                while(stack[top]!='('){
                    char el=pop();
                    if(el!='a'){
                         cout<<el;
                    }
                }
                char el=pop();
            }
            else{
                cout<<inf[i];
            }

            i++;
        }
        cout<<"The postifix expression: \n";
        while(!stack_empty()){
            char el=pop();
            cout<<el;
        }
        return 0;
}
