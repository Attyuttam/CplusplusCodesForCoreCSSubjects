#include<iostream>
using namespace std;
struct node{
    int data;
    node *left;
    node *right;
};
node *root=NULL;
void insBST(int val){
    node *n=new node;
        n->data=val;
        n->left=n->right=NULL;
    if(root==NULL){

        root=n;
    }
    else{
           node* root1=root;
        while(1){
            if(root1->data>val){
                if(!root1->left){
                    root1->left=n;
                    break;
                }
                else{
                    root1=root1->left;
                }
            }
            else{
                if(!root1->right){
                    root1->right=n;
                    break;
                }
                else{
                    root1=root1->right;
                }
            }
        }
    }
}
void disp(node *r){
    if(r){
        cout<<r->data<<" ";
        disp(r->left);
        disp(r->right);
    }
}
int main(){
    insBST(5);
    insBST(6);
    insBST(8);
    insBST(7);
    insBST(9);

    disp(root);
}
