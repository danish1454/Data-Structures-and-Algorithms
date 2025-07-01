#include<iostream>
#include<vector>
#include<string>
using namespace std;
class Node{
    public:
    string key;
    int val;
    Node* next;
    
    Node(string key, int val){
        this->key = key;
        this->val = val;
        next = NULL;
    }
    ~Node(){
        if(next != NULL){
            delete next;
        }
    }
};

class Hashtable{
    int totalSize;
    int currSize;
    Node** table;        // like int *table,   data type her is 'Node*'

    int hashFunction(string key){
        int idx=0;
        for(int i=0;i<key.size();i++){
            idx = idx + (key[i] * key[i]) % totalSize; 
        }
        return idx % totalSize;
    }
     void rehash(){
        int oldSize = totalSize;
        Node** oldTable = table;

        totalSize = 2*totalSize;
        currSize = 0;
        table = new Node*[totalSize];

        for(int i=0;i<totalSize;i++){
            table[i] = NULL;
        }

        //copy old table values
        for(int i=0;i<oldSize;i++){
            Node* temp = oldTable[i];
            while(temp!=NULL){
                insert(temp->key, temp->val);
                temp = temp->next;
            }
            if(oldTable[i] != NULL){
                delete oldTable[i];
            }
        }
        delete[] oldTable;
    }
    
    public :
    Hashtable(int size){
        totalSize = size;
        currSize = 0;

        table = new Node*[totalSize];                // check brackets 

        for(int i=0;i<totalSize;i++){
            table[i] = NULL;
        }
    }

    void insert(string key, int val){
        int idx = hashFunction(key);

        Node* newNode = new Node(key, val);

        newNode->next = table[idx];
        table[idx] = newNode;
        
        currSize++;

        double lamda = currSize/(double)totalSize;
        if(lamda >1 ){
            rehash(); //O(n) -- worst case
        } 
    }

    bool isExist(string key){
        int idx = hashFunction(key);
        Node* temp = table[idx];

        while(temp != NULL){
            if(temp->key == key){
                return true;
            }
            temp = temp->next;
        }  
        return false;
    }

    int search(string key){
        int idx = hashFunction(key);
        Node* temp = table[idx];

        while(temp != NULL){
            if(temp->key == key){
                return temp->val;
            }
            temp = temp->next;
        }  
        return -1;
    }
};
int main()
{
   Hashtable ht(10);
   ht.insert("india", 150); 
    ht.insert("russia", 160);
    ht.insert("china", 250);
    ht.insert("japan", 90);
    ht.insert("USA", 100);

    if(ht.isExist("india")){
        cout<<ht.search("india")<<endl;
    }
   return 0;
}