#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
using namespace std;

class Node{
    public:
    unordered_map<char, Node*> children;
    bool endOfWord;

    Node(){
        endOfWord = false;
    }

};

class Trie{
    public:
    Node* root;

    Trie(){
        root = new Node();
    }   

    void insert(string key){
        Node* temp = root;

        for(int i=0; i<key.size(); i++){
            if(temp->children.count(key[i]) == 0){
                temp->children[key[i]] = new Node();
            }
            temp = temp->children[key[i]];
        }
        temp->endOfWord = true;
    }

    bool search(string key){
        Node* temp = root;

        for(int i=0;i<key.size();i++){
            if(temp->children.count(key[i])){
                temp = temp->children[key[i]];
            }
            else{
                return false;
            }
        }
        return temp->endOfWord;
    }
};

int main()
{
   vector<string> words = {"the", "a", "thee", "their", "there", "any"};
   Trie trie;
   for(int i=0;i<words.size();i++){
    trie.insert(words[i]);
   }
   cout<<trie.search("any");
   return 0;
}