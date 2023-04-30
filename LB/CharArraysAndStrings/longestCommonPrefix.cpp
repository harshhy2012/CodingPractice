#include<bits/stdc++.h>

using namespace std;

string longCommPrefix(vector<string> strs){
    int minLen = INT_MAX;
    for(int i=0;i<strs.size();i++){
        if(strs[i].size()<minLen){
            minLen = strs[i].size();
        }
    }
    string res;
}

int main(){
    int n;
    cin>>n;
    vector<string> strs(n);
    for(auto &s: strs){
        cin>>s;
    }
    cout<<longCommPrefix(strs)<<endl;
    return 0;
}