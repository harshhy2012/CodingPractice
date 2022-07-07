#include<bits/stdc++.h>

using namespace std;

int main(){
    string s;
    getline(cin, s);
    vector<int> arr(27,0);
    for(int i=0;i<s.size();i++){
        
        if(s[i] != '}' && s[i] != '{' && s[i]!= ',' && s[i] != ' '){
            arr[s[i]-97]++;
        }
            
    }   
    int ans = 0; 
    for(int i=0;i<27;i++){
        if(arr[i]!=0)    
            ans++;
    }
    cout<<ans<<endl;
    return 0;
}