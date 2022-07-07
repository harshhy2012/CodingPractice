#include<bits/stdc++.h>

using namespace std;

string reverseIt(string &s, int i, int j){
    if(i>=j){
        return s;
    }
    swap(s[i],s[j]);
    return reverseIt(s, i+1, j-1);
}

int main(){
    string s;
    cin>>s;

    cout<<reverseIt(s, 0, s.size()-1);

    return 0;
}