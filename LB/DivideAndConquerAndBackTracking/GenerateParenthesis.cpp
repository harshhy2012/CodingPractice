#include<bits/stdc++.h>

using namespace std;

void parenthesis(int open, int close, string &output, vector<string> &ans){
    if(open == 0 && close == 0){
        ans.push_back(output);
        return;
    }
    if(open>0){
        output.push_back('(');
        parenthesis(open-1, close, output, ans);
        output.pop_back();
    }
    if(close>open){
        output.push_back(')');
        parenthesis(open, close-1, output, ans);
        output.pop_back();
    }
}

int main(){
    int n;
    cin>>n; 
    string ans="";
    vector<string> allAns;
    parenthesis(n, n, ans, allAns);
    for(auto i: allAns){
        cout<<i<<endl;
    }
    return 0;
}