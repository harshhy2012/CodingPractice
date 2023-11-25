#include<bits/stdc++.h>

using namespace std;

void printStack(stack<char> s){
    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
    cout<<endl;
}

int longestValidParentheses(string s) {
    int n = s.size();
    stack<int> st;
    st.push(-1);
    int maxAns = 0, ans = 0;
    for(int i=0;i<n;i++){
        if(s[i]=='('){
            st.push(i);
        } else if(s[i] == ')'){
            st.pop();
            if(!st.empty()){
                ans = i-st.top();
                maxAns = max(maxAns, ans);
            } else{
                st.push(i);
            }
        }
    }
    return maxAns;
}

int main(){
    string s;
    cin>>s;
    // know when to pop & count number of pops
    // return 2*num of pops;
    cout<<longestValidParentheses(s)<<endl;
    return 0;
}