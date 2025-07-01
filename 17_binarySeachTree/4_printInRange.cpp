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

void printInRange(Node* root, int start, int end){
    if(root == NULL){
        return;
    }
    if(start <= root->data && root->data <= end){
        printInRange(root->left, start, end);  // we printed later so that we can get sorted value     // inorder logic
        cout<<root->data<<" ";
        printInRange(root->right, start, end);
    }
    else if(root->data < start){
        printInRange(root->right, start, end);
    }
    else{
        printInRange(root->left, start, end);
    }
}

int main()
{
    vector<int> arr = {5, 1 , 3, 4, 2, 7};  
    Node* root = buildTree(arr);
    printInRange(root, 2, 7);
    return 0;
}