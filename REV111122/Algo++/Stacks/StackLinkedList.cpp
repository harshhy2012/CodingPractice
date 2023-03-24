#include<bits/stdc++.h>

using namespace std;

class node{
    public:
        int data;
        node* next;

        node(int d){
            data = d;
            next = NULL;
        }
};

class myStack{
    node*head;
    int size;
    int top;
    
    public:
    
    myStack(int x){
        head = NULL;
        size = x;
        top = -1;
    }               
    void push(int data){
        // if(top==size-1){
        //     cout<<"OVERFLOW!\n";
        //     return;
        // }
        node*newNode= new node(data);
        head->next = newNode;
        head = newNode;
    }                  

    void pop(){
        if(top==-1){
            cout<<"ALREADY EMPTY!\n";
            return;
        }
        node*temp = head;
        while(temp->next){
            temp = temp->next;
        }
        node*temp2 = temp->next;
        temp->next = NULL;
        delete temp2;
        top--;
    }

    int topValue(){
        if(top==-1){
            cout<<"NO DATA IN STACK!\n";
            return -1;
        }
        return head->data;
    }

    int length(){
        int len = 0;
        node*temp = head;
        while(head){
            head = head->next;
            len++;
        }
        return len;
    }

    bool isEmpty(){
        return (length()==0 || top==-1);
    }

    bool isFull(){
        return (top>=size-1);
    }

    void print(){
        node *temp = head;
        while(temp){
            cout<<temp->data;
            if(temp->next!=NULL)
                cout<<"->";
            temp = temp->next;
        }
    }

};

int main(){
    myStack stk(10);
    if(stk.isEmpty())
            cout<<"KHALI!\n";
        else
            cout<<"NOT KHALI!\n";
    stk.pop();
    stk.push(1);
    stk.print();
    stk.push(2);
    stk.push(3);
    stk.push(4);
    stk.push(5);
    stk.push(6);
    stk.push(7);
    stk.push(8);
    stk.push(9);
    stk.push(10);
    stk.print();
    stk.pop();
    stk.print();
    if(stk.isFull())
        cout<<"ARE NHI JAGEH HAI!\n";
    else
        cout<<"ARE BOHUT JAGEH HAI!\n";
    stk.push(11);
    stk.push(12);
    stk.print();
    if(stk.isFull())
        cout<<"ARE NHI JAGEH HAI!\n";
    else
        cout<<"ARE BOHUT JAGEH HAI!\n";
    return 0;
}