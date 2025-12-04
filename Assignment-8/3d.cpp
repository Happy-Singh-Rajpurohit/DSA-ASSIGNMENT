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
int minDepth(Node* &root){
    if(root==NULL){
        return 0;
    }
    int left = minDepth(root->left);
    int right = minDepth(root -> right);
    int ans = min(left,right)+1;
    return ans;
}
int main(){
    Node* n1 = NULL;
    takeInput(n1);
    cout<<"Maximum Depth of the tree is : "<<minDepth(n1)<<endl;
    return 0;
}