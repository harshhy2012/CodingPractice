#include<bits/stdc++.h>

using namespace std;

bool validAnagram(string s1, string s2){
    if(s1.size()!=s2.size()){
        return false;
    }
    vector<int> arr(257,0);
    for(int i=0;i<s1.size();i++){
        arr[s1[i]]++;
    }
    for(int i=0;i<s2.size();i++){
        arr[s2[i]]--;
    }
    for(int i=1;i<257;i++){
        if(arr[i]!=0){
            return false;
        }
    }
    return true;
}

int main(){
    string s1,s2;
    cin>>s1>>s2;
    if(validAnagram(s1,s2)){
        cout<<"VALID!\n";
    }
    else{
        cout<<"NOT VALID!\n";
    }
    return 0;
}