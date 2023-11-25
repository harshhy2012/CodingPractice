#include<bits/stdc++.h>

using namespace std;

void insertAtBottom(stack<string>&st, string target){
    if(st.empty()){
        st.push(target);
        return;
    }

    string temp = st.top();
    st.pop();
    insertAtBottom(st, target);
    st.push(temp);
}

void reverseStack(stack<string> &st){

    if(st.empty()){
        return;
    }

    string target = st.top();
    st.pop();

    reverseStack(st);

    insertAtBottom(st, target);

}

void printStack(stack<string> s){
    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
    cout<<endl;
}

string simplifyPath(string s){
    stack<string> st;
    int i=0;
    while(i<s.size()){
        if(s.substr(i,2) == "./"){
            i+=2;
            continue;
        }

        if(s.substr(i,2) == ".."){
            if(!st.empty())
                st.pop();
            i+=2;
            continue;
        }


        string pushit = "";
        while(s[i]!='/'){
            pushit.push_back(s[i]);
            i++;
        }cout<<"PUSHIT: "<<pushit<<endl;
        
        
        
        if(!pushit.empty())
            st.push(pushit);
        i++;
        cout<<"STACK: ";
        printStack(st);
    }
    reverseStack(st);
    string ans = "/";
    while(!st.empty()){
        ans += st.top();
        ans += "/";
        st.pop();
    }
    if(ans.size()>1)
        ans.pop_back();
    return ans;
}




int main(){
    string path;
    cin>>path;

    cout<<simplifyPath(path)<<endl;

    return 0;
}