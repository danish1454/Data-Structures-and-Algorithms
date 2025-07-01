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

int height(Node* root){
    if(root == NULL){
        return 0;
    }
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);

    return 1+ max(leftHeight, rightHeight);
}

int diameter1(Node* root){   //O(n2)
    if(root==NULL){
        return 0;
    }
    int currDia = height(root->left) + height(root->right);
    int leftDia = diameter1(root->left); 
    int rightDia = diameter1(root->right);

    return max(currDia, max(leftDia, rightDia));
}

int main()
{
   vector<int> nodes = {1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};
    Node* root = makeTree(nodes);
    cout<<diameter1(root);
   return 0;
}