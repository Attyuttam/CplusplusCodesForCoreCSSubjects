
/*This program has a fault, the operands on which the operation will be performed
cannot be of more than one digit. That is what i am trying to solve.
*/

#include<iostream>
#include<cstdio>
using namespace std;
int top=-1;
int stack[20];
int topc=-1;
int cstack[20];

void push(int el){
    if(top!=19){
        stack[++top]=el;
    }
}
int pop(){
    if(top!=-1){
        int el=stack[top];
        top--;
        return el;
    }
}

void pushc(char el){
    if(topc!=19){
        cstack[++topc]=el;
    }
}
char popc(){
    if(topc!=-1){
        char el=cstack[topc];
        topc--;
        return el;
    }
}


int main(){
    int ch;
    int len;
    string postfix,prefix;
    while(1){
        cout<<"\n1.Postfix evaluation \n2.Prefix evaluation \n3.Exit\nEnter your choice: ";
        cin>>ch;
        if(ch==1){
            cout<<"Enter a postfix expression: ";
            cin>>postfix;
            len=postfix.length();
            int i=0;
            while(i<len){

                if(postfix[i]>=48 && postfix[i]<=57){
                    push(postfix[i]-48);
                }
                else{
                    if(postfix[i]=='+'){
                        int b=pop();
                        int a=pop();
                        int el=a+b;

                        push(el);
                    }
                    else if(postfix[i]=='-'){
                        int b=pop();
                        int a=pop();
                        int el=a-b;
                        push(el);
                    }
                    else if(postfix[i]=='*'){
                        int b=pop();
                        int a=pop();
                        int el=a*b;
                        push(el);
                    }
                    else if(postfix[i]=='/'){
                        int b=pop();
                        int a=pop();
                        int el=a/b;
                        push(el);
                    }
                    else if(postfix[i]=='+'){
                        int b=pop();
                        int a=pop();
                        int el=a%b;
                        push(el);
                    }
                }
            i++;
            }
            cout<<pop();
        }
        else if(ch==2){

            cout<<"Enter a prefix expression: ";
            cin>>prefix;
            len=prefix.length();
            int i=0;
            int a=10;
            while(i<len){
                    if(prefix[i]=='+'||prefix[i]=='-'||prefix[i]=='*'||prefix[i]=='/'||prefix[i]=='%'){
                        pushc(prefix[i]);
                    }
                    else{
                            //cout<<"\nvalue of a="<<a;
                            if(a!=10){
                                char op=popc();
                                if(op=='+'){
                                a=a+(prefix[i]-48);
                                }
                                else if(op=='-'){
                                a=a-(prefix[i]-48);
                                }
                                else if(op=='*'){
                                a=a*(prefix[i]-48);
                                }
                                else if(op=='/'){
                                a=a/(prefix[i]-48);
                                }
                                else if(op=='%'){
                                a=a%(prefix[i]-48);
                                }
                            }
                        else{

                            a=prefix[i]-48;
                        }


                    }
                    i++;
            }
            cout<<a;

        }
        else if(ch==3){
            break;

        }
        else{
            cout<<"Wrong option";
            fflush(stdin);
        }
    }
}
