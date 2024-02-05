#include<bits/stdc++.h>

using namespace std;

class myQueue{
    int *arr;
    int size;
    int front;
    int rear;

    public:
        myQueue(int size){
            this->size = size;
            this->arr = new int[size];
            this->front = 0;
            this->rear = 0;
        }

        void push(int data){
            if(rear == size){
                cout<<"Q IS FULL\n";
                return;
            }
            else{
                arr[rear] = data;
                rear++;
            }
        }

        void pop(){
            if(front == rear){
                cout<<"Q IS EMPTY\n";
                return;
            } else{
                arr[front] = -1;
                front++;
                if(front == rear){
                    front = 0;
                    rear = 0;
                }
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
    
    myQueue q(10);

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