#include<iostream>
using namespace std;

class Node{
    public :
    int data;
    Node* left;
    Node* right;

    Node(int data){
        this -> data = data;
        this -> left = NULL;
        this -> right = NULL;
    }
};
Node* createBST(Node* root, int d){
    if(root == NULL ){
        root = new Node(d);
        return root;
    }
    else{
        if( d > root -> data){
            root -> right = createBST(root->right,d);
        }
        else{
            root -> left = createBST(root -> left,d);
        }
    }
    return root;
}
void Preorder(Node* &root){
    //nlr
    if(root == NULL){
        return ;
    }
    else{
        cout<<root->data<<" ";
        Preorder(root->left); 
        Preorder(root->right);
    }
}
void Inorder(Node* &root){
    // lnr
    if(root == NULL){
        return ;
    }
    else{
        Inorder(root -> left);
        cout<<root->data<<" ";
        Inorder(root->right);
    }
}
void Postorder(Node* &root){

    //lrn
    if(root == NULL){
        return ;
    }
    else{
        Postorder(root->left);
        Postorder(root->right);
        cout<<root->data<<" ";
    }
}
void takeInput(Node* &root){

    int data;
    cout<<"enter data : ";
    cin >> data;

    while(data != -1){
        root = createBST(root,data);
        cin>>data;
    }
}
int main(){
    Node* root1 = NULL;
    takeInput(root1);
    cout<<"preorder : ";
    Preorder(root1);
    cout<<endl;
    cout<<"inorder : ";
    Inorder(root1);
    cout<<endl;
    cout<<"postorder : ";
    Postorder(root1);   
    cout<<endl;
}