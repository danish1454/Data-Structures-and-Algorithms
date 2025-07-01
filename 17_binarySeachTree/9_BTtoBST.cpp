#include<iostream>
#include<vector>
using namespace std;
class Node{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int val){
        data = val;
        left = right = NULL;
    }
};

Node* buildBST(vector<int> arr, int st, int end){
    if(st > end){
        return NULL;
    }
    int mid = st + (end-st)/2;
    Node *curr = new Node(arr[mid]);
    curr->left = buildBST(arr, st, mid-1);
    curr->right = buildBST(arr, mid+1, end);

    return curr;
} 

void getInorder(Node* root, vector<int> &nodes){
    if(root == NULL){
        return;
    }
    getInorder(root->left, nodes);
    nodes.push_back(root->data);
    getInorder(root->right, nodes);
}

Node* getBalanceBST(Node* root){
    vector<int>nodes;
    // get inorder
    getInorder(root, nodes);

    return buildBST(nodes, 0, nodes.size()-1);
}
void preOrder(Node* root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<" ";
    preOrder(root->left);
    preOrder(root->right);
}
int main(){
    Node* root = new Node(6);
    root->left = new Node(5);
    root->left->left = new Node(4);
    root->left->left->left = new Node(3);

    root->right = new Node(7);
    root->right->right = new Node(8);
    root->right->right->right = new Node(9);

    preOrder(root);
    cout<<endl;
    root = getBalanceBST(root);
    preOrder(root);

    return 0;
}