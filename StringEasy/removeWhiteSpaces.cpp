#include<bits/stdc++.h>
 
using namespace std;
 
string removeWhiteSpaces(string &s){
    int count=0;
    for(int i=0;i<s.size();i++){
        if(s[i]!=' ')
            s[count++] = s[i];
    }
    s.erase(count,s.size());
    return s;
}
 
int main(){
    string s;
    getline(cin,s);
    cout<<s<<endl;
    cout<<removeWhiteSpaces(s)<<endl;
    return 0;
}