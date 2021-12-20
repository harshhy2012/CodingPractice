#include<bits/stdc++.h>

using namespace std;

bool isPermutation(string &s1, string &s2){
    if(s1.size()!=s2.size())
        return false;

    vector<int> str1(256,0),str2(256,0);
    for(int i=0;i<s1.size();i++){
        str1[s1[i]]++;
        str2[s2[i]]++;
    }

    for(int i=0;i<256;i++){
        if(str1[i]!=str2[i])
            return false;
    }
    return true;
}

int main(){
    ifstream cin("isPermutation.txt");
    if(cin.fail())
    cout<<"Input from file failed";
    string s1,s2;
    cin>>s1>>s2;
    
    if(isPermutation(s1,s2))
        cout<<"YES\n";
    else
        cout<<"NO\n";
    
    cin.close();
    return 0;
}