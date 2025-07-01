#include<iostream>
using namespace std;
class Node{
public: 
    int data;
    Node* next;
    Node(int val){
        data = val;
        next = NULL;
    }

    ~Node(){
        if(next!=NULL){
            delete next;
            next = NULL;
        }
    }
};

class List{
    Node *head;
    Node *tail;
 public:

    List(){
        head = NULL;
        tail = NULL;
    }

    void push_front(int val){
        Node* n = new Node(val);
        if(head == NULL){
            head = tail = n;
        }
        else{
            n->next = head;
            head = n;
        }
    }

    void push_back(int val){
        Node* n = new Node(val);
        if(head == NULL){
            head = tail = n;
        }
        else{
            tail->next = n;
            tail = n;
        }
    }

    void printList(){
        Node* temp = head;
        while(temp!=NULL){
            cout<<temp->data<<"->";
            temp = temp->next;
        }
        cout<<"NULL";
    }

    ~List(){
        if(head!=NULL){
            delete head;
            head = NULL;
        }
    }

    void pop_front(){
        Node* temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;
    }
    
    void insert(int val, int pos){
        Node* n = new Node(val);

        Node* temp = head;
        for(int i=0;i<pos-1;i++){
            if(temp==NULL){
                cout<<"invalid";
                return;
            }
            temp = temp->next;
        }
        n->next = temp->next;         // make before make
        temp->next = n;
    }

     
    void pop_back(){
        Node* temp = head;
        while(temp->next->next != NULL){
            temp = temp->next;
        }
        temp->next = NULL;
        delete tail;
        tail = temp;
    }

    int serch(int key){
        Node* temp = head;
        int count = 0;
        while(temp!=NULL){
            if(temp->data == key){
                return count; 
            }
            temp = temp->next;
            count++;
        }
        return -1;
    }

    void reverse(){
        Node* prev =  NULL;
        Node* curr = head;

        while(curr != NULL){
            Node* next = curr->next;
            curr->next = prev;
            
            // updations
            prev = curr;
            curr = next;
        } 
        head = prev;
    }

};

int main()
{
   List ll;
   ll.push_front(3);
   ll.push_front(2);
   ll.push_front(1);
   ll.push_back(4);
   ll.push_back(5);
   ll.push_back(6);
   ll.insert(34,3);
   
   ll.pop_front();
   ll.pop_back();
   
   ll.printList();

   cout<<endl;
   ll.reverse();
   ll.printList();
   return 0;
}