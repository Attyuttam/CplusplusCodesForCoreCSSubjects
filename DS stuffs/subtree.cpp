#include<iostream>
using namespace std;
struct node{
    int data;
    node *left;
    node *right;
};

bool find(node *root1, node *root2){
    if(root1 && root2){
        if(root1->data == root2->data){
            if(root1->left && !root2->left)
                return 0;
            else if(!root1->left && root2->left)
                return 0;
            if(root1->right && !root2->right)
                return 0;
            else if(!root1->right && root2->right)
                return 0;
            else if(!root1->right && !root2->right && !root1->left && !root2->left)
                return 1;
            else
                return find(root1->left,root2->left)&&find(root1->right,root2->right);
        }
        else if(!root1)
            return 0;
        else
            return find(root1->left,root2)||find(root1->right,root2);
    }
}
void trav(node* root){
    if(root){
        cout<<root->data<<" ";
        trav(root->left);
        trav(root->right);
    }
}
int main(){
    node *root=NULL;
    node *n=new node;
    node *root2=NULL;

    n->data=1;
    n->left=NULL;
    n->right=NULL;
    root=n;

    n=new node;
    n->data=2;
    n->left=NULL;
    n->right=NULL;
    root->left=n;

    n=new node;
    n->data=3;
    n->left=NULL;
    n->right=NULL;
    root->right=n;

    n=new node;
    n->data=4;
    n->left=NULL;
    n->right=NULL;
    root->right->left=n;

    n=new node;
    n->data=5;
    n->left=NULL;
    n->right=NULL;
    root->right->right=n;

    n=new node;
    n->data=3;
    n->left=NULL;
    n->right=NULL;
    root2=n;

    n=new node;
    n->data=5;
    n->left=NULL;
    n->right=NULL;
    root2->right=n;

    n=new node;
    n->data=6;
    n->left=NULL;
    n->right=NULL;
    root2->left=n;
    cout<<endl;
    trav(root);
    cout<<endl;
    trav(root2);
    if(find(root,root2)){
        cout<<"yes";
    }
    else{
        cout<<"no";
    }
}
