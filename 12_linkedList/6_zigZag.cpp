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

void printList(Node* head){
        Node* temp = head;
        while(temp!=NULL){
            cout<<temp->data<<"->";
            temp = temp->next;
        }
        cout<<"NULL";
    }

Node* splitAtHead(Node* head){
    if (head == NULL || head->next == NULL) {
         return head;  // list is empty or has only one element
        } 
    Node *slow = head;
    Node *fast = head;
    Node *prevSlow = NULL;

    while(fast!=NULL && fast->next!=NULL){
        prevSlow = slow;
        slow = slow->next;
        fast = fast->next->next;
    }
    if(prevSlow !=  NULL){
        prevSlow->next = NULL;
    }
    return slow;    
}

Node* reverse(Node* head){
    Node* prev = NULL;
    Node* curr = head;

    while(curr!=NULL){
    Node* next = curr->next;
    curr->next = prev;

    prev = curr;
    curr = next;
    }
    return prev;
}

Node* zigZag(Node* head){
    Node* rightHead = splitAtHead(head);
    Node* rightHeadRev = reverse(rightHead);

    // alternate merging : 1st head = head   2nd head = rightHeadNode

    Node* left = head;
    Node* right = rightHeadRev;
    Node* tail = right;
    while(left!=NULL && right!=NULL){
        Node* nextLeft = left->next;
        Node* nextRight = right->next;

        left->next = right;
        right->next = nextLeft;
        tail = right;

        left = nextLeft;
        right = nextRight;
    }
    if(right!=NULL){
        tail->next = right;
    }
    return head;
}

int main()
{
   List ll;
   ll.push_back(1);
   ll.push_back(2);
   ll.push_back(3);
   ll.push_back(4);
   ll.push_back(5);
   printList(ll.head);
   cout<<endl;

   ll.head = zigZag(ll.head);
   printList(ll.head);
   
   return 0;
}