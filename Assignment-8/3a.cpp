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
        this -> right= NULL;
    }
};
Node* createBST(Node* root, int data){
    if(root==NULL){
        root = new Node(data);
        return root;
    }
    if(data > root -> data){
        root -> right = createBST(root ->right,data);
    }
    else if(data < root -> data){
        root ->left = createBST(root->left,data);
    }
    return root;
}
Node* insertintoBST(Node* root, int value){
    if(root == NULL){
        root = new Node(value);
        return root;
    }
    if(root -> data == value){
        cout<<"Node with this data value already exsists ! "<<endl;
        return root;
    }
    if(value > root -> data){
        root -> right = insertintoBST(root->right,value);
    }
    else if(value < root -> data){
        root -> left = insertintoBST(root->left,value);
    }
    return root;
}
void takeInput(Node* &root){
    int data;
    cout<<"enter data : ";
    cin>>data;
    while(data != -1){
        root= createBST(root,data);
        cin>>data;
    }
}
void printInorder(Node* &root){
    if(root == NULL){
        return ;
    }
    printInorder(root->left);
    cout<<root->data<<" ";
    printInorder(root->right);
}
int main(){
    Node* n1 = NULL;
    takeInput(n1);
    cout<<"before insertion ";
    printInorder(n1);
    n1 = insertintoBST(n1,10);
    cout<<"after insertion ";
    printInorder(n1);
    return 0;
}