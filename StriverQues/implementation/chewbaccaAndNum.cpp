#include<bits/stdc++.h>

using namespace std;

int main(){
    string s;
    cin>>s;

    if(s[0]>'4' && s[0] != '9'){
        int dig = s[0]-'0';
        int comp = 9-dig;
        s[0] = comp+'0';
    }

    for(int i=1;i<s.size();i++){
        if(s[i] > '4'){
            int dig = s[i]-'0';
            int comp = 9-dig;
            s[i] = comp+'0';
        }
    }

    cout<<s<<endl;

    return 0;
}