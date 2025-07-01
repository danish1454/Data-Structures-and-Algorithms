#include<iostream>
#include<vector>
using namespace std;
class Node{
    public :
    Node* left;
    Node* right;
    int data;

    Node(int val){
        data = val;
        left = right = NULL;
    }
}; 

Node* insert(Node* root, int val){
    if(root == NULL){
        root = new Node(val);
        return root;
    }
    if(root->data > val){
        root->left = insert(root->left, val);
    }
    else{
        root->right = insert(root->right, val);
    }
    return root;
}

Node* buildTree(vector<int> arr){
    Node* root = NULL;
    for(int i=0;i<arr.size();i++){
        root = insert(root, arr[i]);
    }
    return root;
}

void inOrder(Node* root){
    if(root == NULL){
        return;
    }
    inOrder(root->left);
    cout<<root->data<<" ";
    inOrder(root->right);
}

bool validateHelper(Node* root, Node* min, Node* max){
    if(root == NULL){
        return true;
    }
    if(max != NULL && root->data > max->data){
        return false;
    }
    if(min != NULL && root->data < min->data){
        return false;
    }
    return validateHelper(root->left, min, root)
        &&  validateHelper(root->right, root, max);
}

bool validateBST(Node* root){
    return validateHelper(root,NULL ,NULL);
}

int main()
{
    vector<int> arr = {5, 1 , 3, 4, 2, 7};  
    Node* root = buildTree(arr);
    cout<<validateBST(root);
    return 0;
}
