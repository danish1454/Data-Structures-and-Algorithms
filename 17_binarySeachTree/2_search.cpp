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

bool search(Node* root, int key){
    if(root == NULL){
        return false;
    }
    if(root->data == key){
        return true;
    }
    if(root->data > key){
        search(root->left, key);
    }
    else{
        search(root->right, key);
    }
    return false;
}

int main()
{
    vector<int> arr = {5, 1 , 3, 4, 2, 7};  
    Node* root = buildTree(arr);
    //inOrder(root);
    cout<<search(root, 345);
    return 0;
}