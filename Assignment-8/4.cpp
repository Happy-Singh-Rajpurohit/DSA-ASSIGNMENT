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
bool checkBST(Node* &root, int min, int max){
    if(root==NULL){
        return true;
    }
    if(root -> data >= min && root -> data <= max){

        bool left = checkBST(root->left, min, root -> data);
        bool right = checkBST(root->right, root -> data, max);
        return left && right;
    }
    return false;
}