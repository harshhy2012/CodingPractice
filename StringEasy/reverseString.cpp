#include<bits/stdc++.h>

using namespace std;

string reverseIt(string &s){
    int n = s.size();
    for(int i=0;i<n/2;i++){
        char ch;
        ch = s[i];
        s[i] = s[n-1-i];
        s[n-1-i] = ch;
    }
    return s;
}

int main(){
    ifstream cin("reverseString.txt");
    if(cin.fail())
    cout<<"Input from file failed";
    string s;
    cin>>s;
    cout<<reverseIt(s)<<endl;
    cin.close();
    return 0;
}