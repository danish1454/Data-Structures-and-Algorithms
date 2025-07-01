#include<iostream>
#include<vector>
using namespace std;
class Node{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int data){
        this->data = data;
        left = right = NULL;
    }
};

static int idx = -1;

Node* makeTree(vector<int> nodes){
    idx++;
    if(nodes[idx] == -1){
        return NULL;
    }

    Node* currNode = new Node(nodes[idx]);

    currNode->left = makeTree(nodes);  //left subtree
    currNode->right = makeTree(nodes); // right subtree

    return currNode;
}

void KthHelper(Node* root, int k,  int currLevel){
    if(root == NULL){
        return;
    }
    if(currLevel == k){
        cout<<root->data<<" ";
        return;
    }
    KthHelper(root->left, k, currLevel+1);
    KthHelper(root->right, k, currLevel+1);
}

void KthLevel(Node* root, int k){
    KthHelper(root, k, 1);
    cout<<endl;
}

int main()
{
   vector<int> nodes = {1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};
    Node* root = makeTree(nodes);
    KthLevel(root, 3);
    return 0;
}