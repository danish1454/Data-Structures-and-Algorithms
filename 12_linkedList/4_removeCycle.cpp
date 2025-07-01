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
 public:
    Node *head;
    Node *tail;

    List(){
        head = NULL;
        tail = NULL;
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



};
    
bool isCycle(Node *head){
    Node *slow = head; 
    Node *fast = head;

    while(fast != NULL && fast->next != NULL){
        fast = fast->next->next;
        slow = slow->next;
        
        if(slow == fast){
            return true;
        }
    }
    return false;
}

void removeCycle(Node *head){
    Node* slow = head;
    Node *fast = head;
    bool isCycle = false;

    while(fast != NULL && fast->next != NULL){
        fast = fast->next->next;
        slow = slow->next;

        if(slow == fast){
            isCycle = true;
            break;
        }
    }

    if(!isCycle){
        cout<<"no cycle";
        return;
    }

    slow = head;
    if(slow == fast){
        while(fast->next != slow){
            fast = fast->next;
        }
        fast->next = NULL;
    }
    else{
        Node *prevFast = fast;
        while(slow != fast){
            slow = slow->next;
            prevFast = fast;
            fast = fast->next;
        }
        prevFast->next = NULL;
    }
}

int main()
{
   List ll;
   ll.push_back(1);
   ll.push_back(2);
   ll.push_back(3);
   ll.push_back(4);
   ll.tail->next = ll.head->next;

   cout<<isCycle(ll.head);
   removeCycle(ll.head);
   ll.printList();
   
   return 0;
}