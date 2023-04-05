#include<bits/stdc++.h>

using namespace std;

int main(){
    string s;
    cin>>s;
    int one=0, two=0, three=0;
    for(int i=0;i<s.size();i++){
        if(s[i]=='1'){
            one++;
        }
        else if(s[i]=='2'){
            two++;
        }
        else if(s[i]=='3'){
            three++;
        }
    }
    string ans;
    for(int i=0;i<one;i++){
        ans.push_back('1');
        ans.push_back('+');
    }
    for(int i=0;i<two;i++){
         ans.push_back('2');
        ans.push_back('+');
    }
    for(int i=0;i<three;i++){
         ans.push_back('3');
        ans.push_back('+');
    }
    ans.pop_back();
    cout<<ans<<endl;

    return 0;
}