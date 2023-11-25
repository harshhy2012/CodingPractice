#include<bits/stdc++.h>

using namespace std;

void printStack(stack<char> s){
    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
    cout<<endl;
}

bool redundantBracket(string&s){

    stack<char>st;
    int n = s.size();
    bool isOperator = false;
    for(int i=0;i<n;i++){
            char currChar = s[i];
            if(currChar == '('){
                st.push(currChar);
            }
            if(currChar == '+' || currChar == '-' || currChar == '*' || currChar == '/'){
                st.push(currChar);
            }
            if(currChar == ')'){
            bool isOperator = false;
            while(st.top() != '('){
                char temp = st.top();
                if(temp == '+' || temp == '-' || temp == '*' || temp == '/'){
                    isOperator = true;
                }
                st.pop();
            }
            if(isOperator){
                st.pop();
            }
            else{
                return true;
            }
        }
        printStack(st);
    }
    //printStack(st);
    return !st.empty();
}

int main(){
    string s;
    cin>>s;
    if(redundantBracket(s)){
        cout<<"REDUNDANT BRACKETS PRESENT!\n";
    } else{
        cout<<"NO REDUNDANT BRACKETS\n";
    }
    cout<<s;
    return 0;
}