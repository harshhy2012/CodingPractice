#include<bits/stdc++.h>

using namespace std;

class myStack{

    int * stk = NULL;
    int top;
    int size;

    public:

        myStack(int x){
            int *arr = new int [x];
            stk = arr;
            top = -1;
            size = x;
        }

        void push(int d){
            if(top==size-1){
                cout<<"OVERFLOW!\n";
                return;
            }
            top++;
            stk[top] = d;
        }

        void pop(){
            if(top==-1){
                cout<<"EMPTY!\n";
                return;
            }
            int *arr = new int[size-1];
            copy(stk, stk+size-1, arr);
            swap(stk, arr);
            delete [] arr;
            top--;
        }

        bool isEmpty(){
            return top==-1;
        }
        bool isFull(){
            return top==size-1;
        }

        void print(){
            for(int i=0;i<=top;i++){
                cout<<stk[i]<<" ";
            }
            cout<<endl;
        }
        int topEle(){
            if(top==-1)
                return -1;
            return stk[top];
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