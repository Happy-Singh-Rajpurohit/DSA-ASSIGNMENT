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
bool SearchRecursive(Node* &root, int value){

    if(root == NULL){
        return false;
    }
    if(root -> data == value){
        return true;
    }
    if(value > root -> data){
        return SearchRecursive(root->right,value);
    }
    return SearchRecursive(root->left,value);

}
bool SearchIterative(Node* &root, int value){
    Node* temp = root;
    while(temp != NULL){
        if(temp -> data == value){
            return true;
        }
        if(value > temp -> data){
            temp = temp -> right;
        }
        if(value < temp -> data){
            temp = temp -> left;
        }
    }
    return false;
}
int main(){
    Node* n1 = NULL;
    takeInput(n1);
    if(SearchRecursive(n1,32)){
        cout<<"yes"<<endl;
    }
    else{
        cout<<"no"<<endl;
    }
    if(SearchRecursive(n1,28)){
        cout<<"yes"<<endl;
    }
    else{
        cout<<"no"<<endl;
    }
    if(SearchIterative(n1,32)){
        cout<<"yes"<<endl;
    }
    else{
        cout<<"no"<<endl;
    }
    if(SearchIterative(n1,28)){
        cout<<"yes"<<endl;
    }
    else{
        cout<<"no"<<endl;
    }

    return 0;
}