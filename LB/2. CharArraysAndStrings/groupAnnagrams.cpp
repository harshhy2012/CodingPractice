#include<bits/stdc++.h>

using namespace std;

vector<vector<string>> groupAnnagrams(vector<string> strs){
    int n = strs.size();
    map<string, vector<string>> hash;
    for(auto str: strs){
        string sorted = str;
        sort(sorted.begin(), sorted.end());
        hash[sorted].push_back(str);
    }
    vector<vector<string>> ans;
    for(auto i = hash.begin();i!=hash.end();i++){
        ans.push_back(i->second);
    }
    return ans;
}

int main(){
    int n;
    cin>>n;
    vector<string> strs(n);
    for(auto &str: strs){
        cin>>str;
    }   

    vector<vector<string>> ans = groupAnnagrams(strs);

    for(auto group: ans){
        cout<<"[ ";
        for(int i=0;i<group.size();i++){
            cout<<group[i];
            if(i!=group.size()-1)
                cout<<", ";
            else
                cout<<" "; 
        }
        cout<<"]\n";
    }

    return 0;
}