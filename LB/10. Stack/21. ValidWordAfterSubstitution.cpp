#include<bits/stdc++.h>

using namespace std;

bool isValid(string s){
    stack<char> st;
    for(int i=0;i<s.size();i++){
        if(s[i]=='a')
            st.push(s[i]);
        else if(s[i] == 'b'){
            if(!st.empty() && st.top() == 'a'){
                st.push(s[i]);
            } else{
                return false;
            }
        }
        else{
            if(!st.empty() && st.top()=='b'){
                st.pop();
                if(!st.empty() && st.top()=='a'){
                    st.pop();
                } else{
                    return false;
                }
            } else{
                return false;
            }
        }
    }
}      

int main(){
    string s;
    cin>>s;
    if(isValid(s)){
        cout<<"true\n";
    } else{
        cout<<"false\n";
    }
    return 0;
}