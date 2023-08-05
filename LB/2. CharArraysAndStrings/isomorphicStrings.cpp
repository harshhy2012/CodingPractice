#include<bits/stdc++.h>

using namespace std;

bool isomorphic(string s, string t){
    if(s.size()!=t.size()){
        return false;
    }
    vector<char> hash(257, '\0');
    vector<bool> mapped(257, 0);
    int n = s.size();
    for(int i=0;i<n;i++){
        // new element in both strings
        if(hash[s[i]] == '\0' && !mapped[t[i]]){
            hash[s[i]] = t[i];
            mapped[t[i]] = true;
        }
    }

    for(int i=0;i<n;i++){
        if(hash[s[i]] != t[i]){
            return false;
        }
    }

    return true;
}

int main(){
    string s, t;
    cin>>s>>t;
    if(isomorphic(s,t)){
        cout<<"ISOMORPHIC\n";
    }
    else{
        cout<<"NOT\n";
    }    
    return 0;
}