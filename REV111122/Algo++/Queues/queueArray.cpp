#include<bits/stdc++.h>

using namespace std;

template<typename T>

class Queue{
    vector<T> arr;
    int f;
    int r;
    int ms;
    int cs;

  public:
    bool isFull(){
        return cs==ms;
    }

    bool isEmpty(){
        return cs==0;
    }
    Queue(int ds = 4){
        f = r = 0;
        ms = ds;
        r = ms-1;
        cs=0;
        arr.resize(ds);
    }

    void push(T data){
        if(!isFull()){
            r = (r+1)%ms;
            arr[r] = data;
            cs++;
        }
    }

    void pop(){
        if(!isEmpty()){
            f = (f+1)%ms;
            cs--;
        }
    }

    T getFront(){
        return arr[f];
    }
};

int main(){
    Queue<int> q;
    for(int i=1;i<=6;i++){
        q.push(i);
    }

    q.pop();
    q.push(8);

    while(!q.isEmpty()){
        cout<<q.getFront()<<" ";
        q.pop();
    }

    return 0;
}