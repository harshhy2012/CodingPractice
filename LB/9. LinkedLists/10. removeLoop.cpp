#include<bits/stdc++.h>

using namespace std;

class Node{
public:
    int data;
    Node*next;

    Node(){
        this->data = 0;
        this->next = NULL;
    }
    Node(int data){
        this->data = data;
        this->next = NULL;
    }
};

void insertAtTail(Node*&head, Node*&tail, int data){
    if(!head){
        Node *newNode = new Node(data);
        head = newNode;
        tail = newNode;
        return;
    }
    Node *newNode = new Node(data);
    tail->next = newNode;
    tail = newNode;
}

void printList(Node* head){
    while(head){
        cout<<head->data<<" ";
        head = head->next;
    }
    cout<<endl;
}

bool isLooped(Node*head){
    if(!head || !head->next){
        return false;
    }
    Node* slow = head, *fast = head->next;
    while(fast!=NULL){
        fast = fast->next;
        if(fast){
            fast = fast->next;
            slow = slow->next;
            if(slow == fast){ 
                return true;
            }
        }
    }
    return false;
}


void breakLoop(Node*&head){
    if(!head || !head->next){
        return;
    }
    Node* slow = head, *fast = head, *temp;
    while(fast){
        // cout<<"Slow->data: "<<slow->data<<endl;
        // cout<<"Fast->data: "<<fast->data<<endl;
        // cout<<"!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n";
        fast = fast->next;
        if(fast){
            fast = fast->next;
            slow = slow->next;
            
            if(slow == fast){
                
                slow = head;
                break;
            }
        }
    }
    cout<<"Slow matched fast\n";
    while(slow!=fast){
        slow = slow->next;
        fast = fast->next;
    }
    cout<<"Loop point found\n";
    temp = slow->next;
    while(temp->next!=slow){
        temp = temp->next;
    }
    temp->next = NULL;
}

int main(){
    // Node*head = NULL, *tail = NULL;
    Node*one = new Node(1);
    Node*two = new Node(2);
    Node*three = new Node(3);
    Node*four = new Node(4);
    Node*five = new Node(5);
    Node*six = new Node(6);
    Node*seven = new Node(7);
    Node*eight = new Node(8);
    Node*nine = new Node(9);
    Node*ten = new Node(10);
    Node*eleven = new Node(11);
    Node*twelve = new Node(12);

    one->next = two;
    two->next = three;
    three->next = four;
    four->next = five;
    five->next = six;
    six->next = seven;
    seven->next = eight;
    eight->next = nine;
    nine->next = ten;
    ten->next = eleven;
    eleven->next = twelve;
    twelve->next = seven;
    
    if(isLooped(one)){
        cout<<"Loop Found!\n";
        cout<<"breaking Loop...\n";
        breakLoop(one);
        cout<<"Loop Broken :D\n";
        printList(one);
    }
    else{
        cout<<"No Loops :D\n";
    }

    return 0;
}