#include<bits/stdc++.h>

using namespace std;

string longCommPrefix(vector<string> strs){
        int minLen = INT_MAX;
        for(int i=0;i<strs.size();i++){
            if(strs[i].size()<minLen){
                minLen = strs[i].size();
            }
        }
        string res = "";
        char pre = strs[0][0];
        int x = 0;
        for(int i=0;i<minLen;i++){
            for(auto str: strs){
                if(str[x]!=pre){
                    return res;
                }
            }
            x++;
            res.push_back(pre);
            pre = strs[0][x];
        }
        return res;
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