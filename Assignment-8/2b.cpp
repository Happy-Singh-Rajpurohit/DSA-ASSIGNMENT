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

Node* createBST(Node* root, int data){
    if(root == NULL){
        root = new Node(data);
        return root;
    }
    if(data > root->data){
        root -> right = createBST(root->right,data);
    }
    root -> left = createBST(root->left,data);
    return root;
}
void takeInput(Node* &root){
    int data;
    cout<<"enter data : ";
    cin>>data;
    while(data != -1){
        root=createBST(root,data);
        cin>>data;
    }
}
Node* maximum(Node* &root){
    if(root == NULL){
        return root;
    }
    while(root -> right != NULL){
        root = root -> right;
    }
    return root;
}
void displayNode(Node* &root){
    if(root == NULL){
        cout<<"Node is empty "<<endl;
    }
    cout<<root->data<<endl;
}
int main(){
    Node* n1 = NULL;
    takeInput(n1);
    Node* max1 = maximum(n1);
    cout<<"maximum value of binary tree n1 is : ";
    displayNode(max1);
}