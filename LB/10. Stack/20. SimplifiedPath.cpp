#include<bits/stdc++.h>

using namespace std;

void printStack(stack<string> s){
    while(!s.empty()){
       // cout<<s.top()<<" ";
        s.pop();
    }
    cout<<endl;
}

string simplifyPath(string s){
    stack<string> st;
    int i=0;
    int pop = 0;
    while(i<s.size()){
        // cout<<"i value: "<<i<<endl;
        if(s.substr(i,2) == "./"){
            i+=2;
            continue; 
        }
        
        if(s.substr(i,2) == ".."){
            pop++;
            // if(!st.empty())
            //     st.pop();
            i+=2;
            // cout<<"substr: "<<s.substr(i,2)<<" i value: "<<i<<endl;
            continue;
        }

        string pushit = "";
        while(s[i]!='/' && i<s.size()){
            pushit.push_back(s[i]);
            i++;
        }
        cout<<"before: "<<pushit<<" || ";
        reverse(pushit.begin(), pushit.end());
        cout<<"after: "<<pushit<<endl;

        while(pop){
            if(!pushit.empty()){
                pushit.pop_back();
            }
            pop--;
        }
        if(!pushit.empty())
            st.push(pushit);
        i++;
    }
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