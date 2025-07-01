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
   
Node* lca(Node* root, int n1, int n2){
    if(root==NULL){
        return NULL;
    }
    if(root->data == n1 || root->data == n2){
        return root;
    }

    Node* leftLCA = lca(root->left, n1, n2); 
    Node* rightLCA = lca(root->right, n1, n2);

    if(leftLCA != NULL && rightLCA != NULL){
        return root;
    }
    return leftLCA == NULL ? rightLCA : leftLCA;
}

int dist(Node* root, int n){
    if(root == NULL){
        return -1;
    }
    if(root->data == n){
        return 0;
    }

    int leftDist = dist(root->left, n);
    if(leftDist != -1){
        return leftDist + 1;  // +1 because upar wale level ko bhej rha hai, toh apna bhe add karega 
    }
    int rightDist = dist(root->right, n);
    if(rightDist != -1){
        return rightDist + 1;
    }

    return -1;
}

int minDist(Node* root, int n1, int n2){
    Node* LCA = lca(root, n1, n2);

    int dist1 = dist(LCA, n1);
    int dist2 = dist(LCA, n2);

    return dist1 + dist2;
}

int main()
{
   vector<int> nodes = {1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};
    Node* root = makeTree(nodes);

    int n1= 4, n2 = 6;
    cout<<minDist(root, n1, n2);
   return 0;
}
