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

Node* splitMid(Node* head){
    if (head == NULL || head->next == NULL) {
         return head;  // list is empty or has only one element
        } 

    Node *slow = head;
    Node *fast = head;
    Node *prevSlow = NULL;

    while(fast!=NULL && fast->next != NULL){
        prevSlow = slow;
        slow = slow->next;
        fast = fast->next->next; 
    }
    if(prevSlow != NULL){
        prevSlow->next = NULL;
    }
    return slow;  // right head
}

Node *merge(Node* left, Node* right){
    List ans;
    Node *i = left;
    Node *j = right;

    while(i != NULL && j != NULL){
        if(i->data <= j->data){
            ans.push_back(i->data);
            i = i->next;
        }
        else{
            if(i->data >= j->data){
                ans.push_back(j->data);
                j = j->next;
            }
        }
    }

    while(i != NULL){
        ans.push_back(i->data);
        i = i->next;
    }

    while(j != NULL){
        ans.push_back(j->data);
        j = j->next;
    }

    return ans.head;
}

Node* mergeSort(Node *head){
    if(head==NULL || head->next == NULL){
        return head;
    }

    Node *rightHead = splitMid(head);

    Node* left = mergeSort(head); // left side
    Node* right = mergeSort(rightHead);  // right side

    return merge(left, right );
}

int main()
{
   List ll;
   ll.push_back(4);
   ll.push_back(3);
   ll.push_back(2);
   ll.push_back(1);

   ll.printList();
   cout<<endl;
   ll.head = mergeSort(ll.head);
   ll.printList();
   
   return 0;
}