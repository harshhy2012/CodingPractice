#include<bits/stdc++.h>

using namespace std;

int compareStrings(string s1, string s2){
    int ans = 0;
    for(int i=0;i<s1.size();i++){
        if(tolower(s1[i])<tolower(s2[i])){
            return -1;
        }
        else if(tolower(s1[i])>tolower(s2[i])){
            return 1;
        }
    }
    return ans;
}

int main(){
    // ifstream cin("petyaAndStrings.txt");
    // if(cin.fail())
    // cout<<"Input from file failed";
    string s1,s2;
    cin>>s1>>s2;
    cout<<compareStrings(s1,s2);
    // cin.close();
    return 0;
}