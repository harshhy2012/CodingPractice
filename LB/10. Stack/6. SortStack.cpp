#include<bits/stdc++.h>

using namespace std;

 void insertSorted(stack<int>& s, int temp){
    if(s.empty()){
        s.push(temp);
        return;
    } 
    if(s.top() >= temp){
        s.push(temp);
        return;
    }
    int topEle = s.top();
    s.pop();
    insertSorted(s, temp);
    s.push(topEle);
}

 void sortStack(stack<int> &s){
    if(s.empty()){
        return;
    }
    int temp = s.top();
    s.pop();
    sortStack(s);
    insertSorted(s, temp);
 }

void printStack(stack<int> s){
    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
    cout<<endl;
}

int main(){
    stack<int> s;

    s.push(7);
    s.push(11);
    s.push(3);
    s.push(5);
    s.push(9);

    cout<<"Before Sorting: ";
    printStack(s);

    sortStack(s);

    cout<<"After Sorting: ";
    printStack(s);

    return 0;
}