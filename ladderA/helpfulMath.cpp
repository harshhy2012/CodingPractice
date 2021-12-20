#include<bits/stdc++.h>

using namespace std;

int main(){
    // ifstream cin("helpfulMath.txt");
    // if(cin.fail())
    // cout<<"Input from file failed";
    string s;
    cin>>s;
    sort(s.begin(),s.end());
    for(int i=0;i<s.size();i++){
        if(s[i]!='+' && i<s.size()-1)
            cout<<s[i]<<"+";
        else if(s[i]!='+')
            cout<<s[i];
    }
    cout<<endl;
    // cin.close();
    return 0;
}