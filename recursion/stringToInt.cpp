#include<bits/stdc++.h>

using namespace std;

int stringToInt(string s, int ptr){
    
    int num = 0;
    if(ptr==-1){
        return num;
    }
    int currentDig = 0;
    currentDig+=s[ptr]+48;
    currentDig*=10;
    num= currentDig+stringToInt(s,ptr++);
}

int main(){
    string s;
    cin>>s;
    cout<<stringToInt(s,s.size()-1)<<endl;
    return 0;
}