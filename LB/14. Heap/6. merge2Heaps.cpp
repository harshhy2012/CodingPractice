#include<bits/stdc++.h>

using namespace std;

priority_queue<int> merge2Heaps(priority_queue<int>heap1, priority_queue<int>heap2){
    if(heap1.size() > heap2.size()){
        return merge2Heaps(heap2, heap1);
    }
    while(!heap2.empty()){
        int x = heap2.top();
        heap1.push(x);
        heap2.pop();
    }
    return heap1;
}

int main(){
    priority_queue<int> q1;
    priority_queue<int> q2;


    q1.push(12);
    q1.push(2);
    q1.push(3);
    q1.push(8);
    q1.push(9);
    
    q2.push(7);
    q2.push(11);
    q2.push(10);
    q2.push(14);
    q2.push(6);
    q2.push(5);
    q2.push(4);

    priority_queue<int> printq;
    printq = q1;
    cout<<"q1: ";
    while(!printq.empty()){
        cout<<printq.top()<<" ";
        printq.pop();
    }
    cout<<endl;
    printq = q2;
    cout<<"q2: ";
    while(!printq.empty()){
        cout<<printq.top()<<" ";
        printq.pop();
    }
    cout<<endl;
    
    priority_queue<int> merged = merge2Heaps(q1, q2);

    printq = merged;
    cout<<"merged: ";
    while(!printq.empty()){
        cout<<printq.top()<<" ";
        printq.pop();
    }
    cout<<endl;

    

    return 0;
}