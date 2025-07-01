
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

void printPath(vector<int> path){
    cout<<"path : ";
    for(int i=0;i<path.size();i++){
        cout<<path[i]<<" ";
    }
    cout<<endl;
}

void pathHelper(Node* root, vector<int> &path){
    if(root == NULL){
        return;
    }
    path.push_back(root->data);
    if(root->left == NULL && root->right == NULL){
        printPath(path);
        path.pop_back();
        return;
    }
    pathHelper(root->left, path);
    pathHelper(root->right, path);
    path.pop_back();
}

void rootToLeaf(Node* root){
    vector<int> path;
    pathHelper(root, path);
}

int main()
{
    vector<int> arr = {8, 5, 3, 1, 4, 6, 10, 11, 14};  
    Node* root = buildTree(arr);
   // inOrder(root);
   rootToLeaf(root);
    return 0;
}