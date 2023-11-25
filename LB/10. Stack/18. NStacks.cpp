#include<bits/stdc++.h>

using namespace std;

class nStack{
    int size;
    int*top; // stores index of top element of ith stack
    int*next; // two things: a) can point to next element after top b) can point to next free space.
    int*arr; 
    int n;
    int freespot;

    public:
     nStack(int size, int n){
        top = new int[n];
        next = new int[size];
        arr = new int[size];
        this->size = size;
        this->n = n;
        for(int i=0;i<n;i++){
            top[i] = -1;
        }
        for(int i=0;i<size-1;i++){
             next[i] = i+1;
        }
        next[size-1] = -1;
        freespot = 0;
    }

    void push(int data, int k){
        //find index
        int idx = freespot;
        //update freespot
        freespot = next[idx];
        // insert in array;
        arr[idx] = data;
        // update next
        next[idx] = top[k-1];
        // update top
        top[k-1] = idx;
    }

    int pop(int k){
        //do opposite of push in opposite orcer
        // update index with top
        int idx = top[k-1];
        // update top with next
        top[k-1] = next[idx];
        //
        next[idx] = freespot;
        freespot = idx;
        return arr[idx];
    }



};

int main(){
     
    return 0;
}