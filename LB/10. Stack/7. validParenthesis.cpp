#include<bits/stdc++.h>

using namespace std;

bool validParenthesis(string s){
    
    stack<char> st;
    int n = s.size();
    for(int i=0;i<n;i++){
        if(s[i]=='(' || s[i] == '[' || s[i] == '{'){

            st.push(s[i]);

        } else{
            if(!st.empty()){
                if(st.top() == '(' && s[i] == ')')
                    st.pop();
                else if(st.top() == '[' && s[i] == ']')
                    st.pop();
                else if(st.top() == '{' && s[i] == '}')
                    st.pop();
                else{
                    return false;
                }
            } else{
                return false;
            }
        }
    }

    return st.empty();

}

int main(){
    string s;
    cin>>s;

    if(validParenthesis(s)){
        cout<<"VALID!\n";
    } else{
        cout<<"NOT VALID!\n";
    }

    return 0;
}