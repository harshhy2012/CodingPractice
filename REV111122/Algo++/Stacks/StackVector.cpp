#include<bits/stdc++.h>

using namespace std;

template <typename T>

class myStack{

    private: 
        vector<T> arr;

    public:

        void push(T d){
            if(top == size-1){
                cout<<"OVERFLOW!\n";
                return;
            }
            top++;
            arr.push_back(d);
        }
        void pop(){
            if(top==-1){
                cout<<"ALREADY EMPTY!\n";
                return;
            }
            arr.pop_back();
            top--;
        }

        bool isEmpty(){
            return arr.empty();
        }

        bool isFull(){
            return top==arr.size()-1;
        }

        int top(){
            return arr[arr.size()-1];
        }

        void print(){
            for(int i=0;i<top;i++)
                cout<<arr[i]<<" ";
            cout<<endl;
        }
    
};

int main(){
    myStack stk;
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