#include<bits/stdc++.h>

using namespace std;

class Deque{
    int *arr;
    int n;
    int front;
    int rear;
    public: 

        Deque(int size){
            this->n = size;
            this->arr = new int[n];
            rear = -1;
            front = -1;
        }

        void push_back(int data){
            if(front == 0 && rear == n-1){
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

        void push_front(int data){
            if(front == 0 && rear == n-1){
                cout<<"Q IS FULL\n";
                return;
            }
            if(front == -1){
                front = rear = 0;
            }
             else if(front == 0 && rear != n-1){
                front = n-1;
            }
            else{
                front--;
            } 
            arr[front] = data;
        }

        void pop_front(){
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

        void pop_rear(){
            if(rear == -1){
                cout<<"Q IS EMPTY\n";
                return;
            }
            
            if(front == rear){
                arr[rear] = -1;
                front = -1;
                rear = -1;
            }
            else if(rear == 0){
                arr[rear] = -1;
                rear = n-1;
            } else{
                arr[rear] = -1;
                rear--;

            }
        }
};

int main(){
    
    return 0;
}