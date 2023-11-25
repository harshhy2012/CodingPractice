#include<bits/stdc++.h>

using namespace std;

void midElement(stack<int> s, int origSize){
    if(s.size()==0){
        cout<<"No Element is stack\n";
        return;
    }
    if(s.size()==origSize/2){
        cout<<"middleElement: "<<s.top(); 
    }
    int temp = s.top();
    s.pop();
    midElement(s, origSize);
    s.push(temp);
}

int main(){
    stack<int> s;
    for(int i = 1;i<=6;i++){
        s.push(i*10);
    }

    midElement(s, s.size());

    return 0;
}