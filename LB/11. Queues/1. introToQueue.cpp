#include<bits/stdc++.h>

using namespace std;

int main(){
    queue<int> q;
    q.push(5);
    q.push(14);
    q.push(24);
    q.push(55);

    cout<<"SIZE OF QUEUE: " <<q.size();

    q.pop();

    cout<<"SIZE OF QUEUE: "<<q.size();

    if(q.empty()){
        cout<<"Q is empty!\n";
    } else {
        cout<<"Q is not empty!\n";
    }

    cout<<"FRONT ELEMENT: "<<q.front()<<endl;

    return 0;
}