#include<bits/stdc++.h>

using namespace std;

class MinStack {
public:
        vector<pair<int,int>> st;
    MinStack() {

    }
    
    void push(int val) {
        if(st.empty()){
            st.push_back({val,val});
        } else{
            int mini = min(st.back().second, val);
            st.push_back({val, mini});
        }
    }
    
    void pop() {
        if(!st.empty()){
            st.pop_back();
        }
    }
    
    int top() {
        return st.back().first;
    }
    
    int getMin() {
        return st.back().second;
    }
};

int main(){
    
    return 0;
}