#include<bits/stdc++.h>

using namespace std;

string removeAllSubstrings(string s, string part){
    
    int pos = s.find(part);
    while(pos != string::npos){
        s.erase(pos, part.size());
        pos = s.find(part);
    }
    return s;
}

int main(){
    string s,sub;
    cin>>s>>sub;
    cout<<removeAllSubstrings(s, sub)<<endl;
    return 0;
}