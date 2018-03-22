 #include<iostream>
using namespace std;
struct node{
    char data;
    node *lchild;
    node *rchild;
};
node *root=NULL;
//first stack
int top_new=-1;
node* stack_new[20];

int stack_empty_new()
{

    if(top_new==-1){
        return 1;
    }
    else{
        return 0;
    }
}
int stack_full_new(){
    if(top_new==19){
        return 1;
    }
    else{
        return 0;
    }
}
void push_new(node* el){

    if(stack_full_new()){

        cout<<"Full";
    }
    else{

        stack_new[++top_new]=el;
    }
}
node* pop_new(){
    if(stack_empty_new()){
        return NULL;
    }
    else{
        node* el=stack_new[top_new];
        top_new--;
        return el;
    }
}
//second stack
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
void create_expressiontree(char arr[20],int n){
    cout<<endl;
    //the postfix expression is now in arr


    for(int i=0;i<n;i++){
            if(arr[i]-'0'>=0 && arr[i]-'0'<=9){
                node *n=new node;
                n->data=arr[i];
                n->lchild=NULL;
                n->rchild=NULL;
                push_new(n);
            }
            else{
                node *n=new node;
                n->data=arr[i];
                n->lchild=NULL;
                n->rchild=NULL;
                root=n;
                node* b=pop_new();
                node* a=pop_new();
                n->lchild=a;
                n->rchild=b;
                push_new(root);
            }
    }
}
void pre(node *temp){
    if(temp){

        cout<<temp->data<<" ";
        pre(temp->lchild);
        pre(temp->rchild);
    }
}
int main(){
        string inf;
        char arr[20];
        int len;
        cout<<"Enter an infix expression: ";
        cin>>inf;
        len=inf.length();
        int i=0;
        int x=0;
        while(i<len){
                if(inf[i]=='('){
                    push(inf[i]);
                   }
            else if(inf[i]=='+'||inf[i]=='-'||inf[i]=='/'||inf[i]=='*'||inf[i]=='%'){
                while(top!=-1 && priority(inf[i])<=priority(stack[top]) && stack[top]!='('){
                        char el=pop();
                        if(el!='a'){
                         cout<<el;
                         arr[x]=el;
                         x++;
                        }

                }
                push(inf[i]);
            }
            else if(inf[i]==')'){
                while(stack[top]!='('){
                    char el=pop();
                    if(el!='a'){
                            arr[x]=el;
                            x++;
                         cout<<el;
                    }
                }
                char el=pop();
            }
            else{
                    arr[x]=inf[i];
                    x++;
                cout<<inf[i];
            }

            i++;
        }

        i=0;
        while(!stack_empty()){
            char el=pop();
            cout<<el;
            arr[x]=el;
            x++;
        }
        cout<<endl;
        cout<<endl<<"The postfix expression: ";
        create_expressiontree(arr,x);
        pre(root);
        return 0;
}
