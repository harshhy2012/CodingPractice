#include<bits/stdc++.h>

using namespace std;

class cQueue{
    int *arr;
    int n;
    int front;
    int rear;

    public:
        cQueue(int size){
            this->n = size;
            this->arr = new int[size];
            this->front = -1;
            this->rear = -1;
        }

        void push(int data){
            if(rear == (front-1)%(n-1)){
                cout<<"Q IS FULL\n";
                return;
            }
            
            if(front == -1){
                front = rear = 0;
            }
            
            else if(rear == n-1 && front !=0){
                rear = 0;
            }
            else{
                rear++; 
            }
            arr[rear] = data;
        }

        void pop(){
            if(front == -1){
                cout<<"Q IS EMPTY\n";
                return;
            }
            
            if(front == rear){
                arr[front] = -1;
                front = -1;
                rear = -1;
            }
            else if(front == n-1){
                arr[front] = -1;
                front = 0;
            } else{
                arr[front] = -1;
                front++;

            }
        }

        int getFront(){
            if(front == rear){
                cout<<"Q IS EMPTY\n";
                return -1;
            } else{
                return arr[front];
            }
        }

        bool isEmpty(){
            return front == rear;
        }
        int qSize(){
            return abs(rear-front);
        }

};

int main(){
    
    cQueue q(10);

    q.push(5);
    q.push(15);
    q.push(25);
    q.push(55);

    cout<<"SIZE OF Q IS: "<<q.qSize()<<endl;

    q.pop();

    cout<<"SIZE OF Q IS: "<<q.qSize()<<endl;
    cout<<"ELEMENT AT FRONT: "<<q.getFront()<<endl;
    
    if(q.isEmpty()){
        cout<<"Q IS EMPTY\n";
    } else{
        cout<<"Q IS NOT EMPTY\n";
    }

    return 0;
}