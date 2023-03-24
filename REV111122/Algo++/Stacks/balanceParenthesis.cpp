#include<bits/stdc++.h>

using namespace std;

int main(){
    string s;
    stack<char> stk;

    getline(cin, s);

    for(int i=0;i<s.size();i++){
        if(s[i] == '('){
            stk.push('(');
        }
        else if(s[i] == ')'){
            stk.pop();
        }
    }

    if(!s.empty())
        cout<<"BRACKETS NOT BALANCED!\n";
    else
        cout<<"BRAKCERS ARE BALANCED!\n";



    return 0;
}