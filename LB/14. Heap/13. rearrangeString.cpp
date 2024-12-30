#include<bits/stdc++.h>

using namespace std;

// same pattern as min cost to cut rope

class node{
    public: 
        char data;
        int count;

        node(int d, int c){
            this->data = d;
            this->count = c;
        }
};

class compare{
    public: 
        bool operator()(node*a, node*b){
            return a->count < b->count; 
        }
};

string reorganizeString(string s) {
    unordered_map<char, int> charMap;
    for(auto i: s){
        if( charMap.find(i) == charMap.end())
            charMap[i] = 1; 
        else
            ++charMap[i];
    }

    priority_queue<node, vector<node>, compare> maxHeap;

    for(auto i: charMap){
        if(i.second!=0){
            node temp(i.first, i.second);
            maxHeap.push(temp);
        }
    }
    string ans;

    while(maxHeap.size() > 1){
        node first = maxHeap.top();
        maxHeap.pop();
        node second = maxHeap.top();
        maxHeap.pop();
        ans+=first.data+second.data;
        first.count--;second.count--;

        if(first.count!=0){
            maxHeap.push(first);
        }
        if(second.count!=0){
            maxHeap.push(second);
        }
    }

    if(maxHeap.size()==1){
        node temp = maxHeap.top();
        if(temp.count>1){
            return "";
        } else{
            ans+=temp.data;
        }
    }

    return ans;
}

int main(){
    string s;
    cin>>s;
    cout<<"ans: "<<reorganizeString(s)<<endl;
    return 0;
}