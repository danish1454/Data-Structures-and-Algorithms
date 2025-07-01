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

Node* inOrderSucc(Node*root){
    while(root->left != NULL){
            root = root->left;
        }
    return root;
}

Node* deleteNode(Node* root, int val){
    if(root == NULL){
        return NULL;
    }
    if(root->data > val){
        root->left = deleteNode(root->left, val);
    }
    else if(root->data < val){
        root->right = deleteNode(root->right, val);
    }
    else{                          // root->data == val    delete val now
        if(root->left == NULL && root->right == NULL){
            delete root;
            return NULL;
        }
        else if(root->left == NULL || root->right == NULL){
            if(root->left == NULL){
                return root->right;
            }
            return root->left;
        }
        else{
            Node* IS = inOrderSucc(root->right);
            root->data = IS->data;
            root->right = deleteNode(root->right, IS->data);
        }
    }
    return root;
}

int main()
{
    vector<int> arr = {5, 1 , 3, 4, 2, 6, 7};  
    Node* root = buildTree(arr);
    inOrder(root);
    cout<<endl;
    deleteNode(root, 5);
    inOrder(root);
    return 0;
}