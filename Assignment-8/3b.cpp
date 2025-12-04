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
void takeInput(Node* &root){
    int data;
    cout<<"enter data : ";
    cin>>data;
    while(data != -1){
        root= createBST(root,data);
        cin>>data;
    }
}
Node* maxValue(Node* root){
    if(root==NULL){
        return root;
    }
    while(root -> right != NULL){
        root = root ->right;
    }
    return root;
}
Node* deletefromBST(Node* root, int value){
    if(root == NULL){
        return root;
    }
    if(root -> data == value){

        if(root -> left == NULL && root -> right == NULL){
            delete root;
            return NULL;
        }

        if(root -> left != NULL && root -> right == NULL){
            Node* temp = root -> left;
            delete root;
            return temp;
        }
        if(root -> left == NULL && root -> right != NULL){
            Node* temp = root -> right;
            delete root;
            return temp;
        }

        if(root->left != NULL && root -> right != NULL){
            Node* max = maxValue(root -> left);
            root -> data = max -> data ;
            root -> left = deletefromBST(root -> left, max -> data);
            return root;
        }
    }
    if(value > root -> data){
        root -> right = deletefromBST(root -> right, value);
    }
    else if(value < root -> data){
        root -> left = deletefromBST(root -> left, value);
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
    cout<<"before deletion : ";
    printInorder(n1);
    n1 = deletefromBST(n1,5);
    cout<<"after deletion : ";
    printInorder(n1);
    return 0;
}