#include<bits/stdc++.h>

using namespace std;

class Stack{
    public:
    int top; // index of top element
    int *arr;
    int size;

    Stack(int size){
        arr = new int[size];
        this->size = size;
        top = -1;
    }

    void push(int data){
        if(size - top > 1){
            top++;
            arr[top] = data;
        } else {
            cout<<"Stack Overflow\n";
        }
    }
    void pop(){
        if(top==-1){
            cout<<"Stack Underflow\n";
        } else {
            top--;
        }
    }

    int getTop(){
        if(top==-1){
            cout<<"Stack is Empty Nothing at top!\n";        
        } else {
            return arr[top];
        }
    }

    int getSize(){
        // number of elements inserted in stack;S        return top+1;
    }

    bool isEmpty(){
        return top==-1;
    }
};

void print(Stack s){
    while(!s.isEmpty()){
        cout<<s.getTop()<<" ";
        s.pop();
    }
}

int main(){
    Stack s(10);
    s.push(10);
        s.push(20);
            s.push(30);
                s.push(40);
    
    print(s);
    
    
    return 0;
}