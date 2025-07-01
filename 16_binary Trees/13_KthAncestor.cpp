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

bool rootToNodePath(Node* root, int n, vector<int> &path){
    if(root == NULL){
        return false;
    }
    path.push_back(root->data);
    if(root->data == n){
        return true;
    }

    int isLeft = rootToNodePath(root->left, n, path);
    int isRight = rootToNodePath(root->right, n, path);

    if(isLeft || isRight){
        return true;
    }
    path.pop_back();
    return false;

}

int KthAnsector(Node* root, int node, int k){
    if(root == NULL){
        return -1;
    }
    if(root->data == node){
        return 0;
    }
    int leftDist = KthAnsector(root->left, node, k);
    int rightDist = KthAnsector(root->right, node, k);
    
    if(leftDist == -1 && rightDist == -1){
        return -1;
    }
    int validDist = leftDist == -1 ? rightDist : leftDist;
    if(validDist + 1 == k){
        cout<<"Kth ancestor = "<<root->data<<endl; 
    }

    return validDist + 1;
}

int main()
{
   vector<int> nodes = {1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};
    Node* root = makeTree(nodes);

    int node= 5, k = 2;
    KthAnsector(root, node, k);
   return 0;
}
