#include<bits/stdc++.h>

using namespace std;

bool isHello(string s){
    if(s.size()<5)
        return false;
    
    string checkIt="hello";

    int i = 0, j = 0;

    while(i<s.size()){
        if(s[i]==checkIt[j]){
            i++;
            j++;
        }
        else
            i++;
        if(j==5)
            break;
    }
    if(j!=5)
        return false;
    else
        return true;

}

int main(){
    string s;
    cin>>s;
    
    if(isHello(s))
        cout<<"YES\n";
    else
        cout<<"NO\n";
   
    return 0;
}