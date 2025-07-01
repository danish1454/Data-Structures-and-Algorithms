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

int lca(Node* root, int n1, int n2){
    vector<int> path1;
    vector<int> path2;

    rootToNodePath(root, n1, path1);
    rootToNodePath(root, n2, path2);

    int lca = -1;
    for(int i=0, j=0; i<path1.size() && j<path2.size(); i++, j++){
        if(path1[i] != path2[j]){
            return lca;
        }
        lca = path1[i];
    }
    return lca;
}

Node* lca2(Node* root, int n1, int n2){
    if(root==NULL){
        return NULL;
    }
    if(root->data == n1 || root->data == n2){
        return root;
    }

    Node* leftLCA = lca2(root->left, n1, n2); 
    Node* rightLCA = lca2(root->right, n1, n2);

    if(leftLCA != NULL && rightLCA != NULL){
        return root;
    }
    return leftLCA == NULL ? rightLCA : leftLCA;
}

int main()
{
   vector<int> nodes = {1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};
    Node* root = makeTree(nodes);

    int n1= 4, n2 = 3;
    cout<<lca(root, n1, n2)<<endl;
    cout<<lca2(root, n1, n2)->data;
   return 0;
}
