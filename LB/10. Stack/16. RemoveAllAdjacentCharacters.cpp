#include<bits/stdc++.h>

using namespace std;

void printStack(stack<char> s){
    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
    cout<<endl;
}


string removeAdjDup(string s){
    stack<char> st;
    int n = s.size();
    for(int i=0;i<n;i++){
        if(st.empty()){
            st.push(s[i]);
        } else {
            char curr = st.top();
            if(curr==s[i])
                while(curr==s[i]){
                    st.pop();
                    if(!st.empty())
                        curr = st.top();
                    else{
                        break;
                    }
                }
            else
                st.push(s[i]);
        }
        
    }
    
    s.clear();
    while(!st.empty()){
        s.push_back(st.top());
        st.pop();
    }

    reverse(s.begin(), s.end());

    return s;
}

int main(){
    string s;
    cin>>s;
    cout<<removeAdjDup(s)<<endl;
    return 0;
}