#include<bits/stdc++.h>

using namespace std;

pair<string, string> rotateString(string &s, int k){
    string temp1,temp2;
    int n = s.size();
    /*

    geeksforGeeks
    
    sforGeeksgeek

    geeksforGeekss

    eeksgeeksforG

    */
   temp1 = s.substr(0,k);
   temp2 = s.substr(n-k,n-1);
   string s1=s, s2 = s;

    for(int i=0;i<n;i++){
        s1[i] = s1[(i+k)%n];
    }
    for(int i=0;i<k;i++){
        s1[n-k+i] = temp1[i];
    }
    while(s1.size()>n)
        s1.pop_back();

    for(int i=0;i<n;i++){
        s2[(i+k)%n] = s2[i];
    }
    for(int i=0;i<k;i++){
        s2[i] = temp2[i];
    }

    while(s2.size()>n)
        s2.pop_back();

    return {s1,s2};
}

int main(){
    ifstream cin("rotateString.txt");
    if(cin.fail())
    cout<<"Input from file failed";
    string s;
    cin>>s;
    int k;
    cin>>k;
    pair <string, string> ans = rotateString(s,k);
    cout<<ans.first<<"\n"<<ans.second<<endl;
    cin.close();
    return 0;
}