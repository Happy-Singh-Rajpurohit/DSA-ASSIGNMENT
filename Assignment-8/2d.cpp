#include<iostream>
#include<stack>
#include<vector>
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
    else{
        root -> left = createBST(root->left,data);
    }
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
vector<int> inorderBSTelements(Node* &root){
    vector<int> v;
    stack<Node*> st;
    Node* temp = root;

    while(temp != NULL || !st.empty()){
        while(temp!=NULL){
            st.push(temp);
            temp = temp -> left;
        }
        temp = st.top();
        v.push_back(temp -> data);
        st.pop();
        temp = temp -> right;
    }
    return v;
}
int inorderSuccessor(Node* &root,int value){
    vector<int> eles = inorderBSTelements(root);
    int size = eles.size();
    int low = 0 ;
    int high = size - 1;
    int ans;
    while(low <= high){
        int mid = (low+high)/2;
        if(eles[mid]==value){
            if(mid == size - 1){
                ans = -1;
            }
            ans = eles[mid+1];
            break;
        }
        if(value > eles[mid]){
            low = mid +1;
        }
        if(value < eles[mid]){
            high = mid -1;
        }
    }
    return ans;
}
int main(){
    Node* n1 = NULL;
    takeInput(n1);
    int x;
    cout<<"enter whose successor is to be searched : ";
    cin>>x;
    int suc = inorderSuccessor(n1,x);
    if(suc==-1){
        cout<<"no such element exists "<<endl;
    }
    else{
        cout<<suc<<endl;
    }
}
