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
void push(char el){

    if(top==19){

        cout<<"Parenthesis are not balanced";
    }
    else{
        stack[++top]=el;
    }
}
char pop(){
    if(top==-1){

        return 'a';
    }
    else{
        char el=stack[top];
        top--;
        return el;
    }
}



int main(){
    string s;
    int len,flag=0;
    cout<<"Enter an expression whose balance of parenthsis is to be checked: ";
    cin>>s;
    len=s.length();
    for(int i=0;i<=len-1;i++){
        if(s[i]=='(' || s[i]=='{' || s[i]=='['){
            push(s[i]);
        }
        else if(s[i]==')' || s[i]=='}' || s[i]==']'){
            char x=pop();
            if(x=='a'){
                flag=1;
                break;
            }
            if(s[i]==')' && x!='('){flag=1;break;}
            else if(s[i]==']' && x!='['){flag=1;break;}
            else if(s[i]=='}' && x!='{'){flag=1;break;}
        }
        else{
            continue;
        }
    }
    if(flag==1 || !stack_empty()){
        cout<<"Parenthesis are not balanced";
    }
    else{
        cout<<"Parenthesis are balanced";
    }
    return 0;
}
