#include<bits/stdc++.h>

using namespace std;

bool isDigit(char s){
    return ( s=='0' || s=='1' || s=='2' || s=='2' || s=='3' || s=='4' || s=='5' || s=='6' || s=='7' || s=='8' || s=='9' );
}

int myatoi(string s){
    long long int ans=0;
    vector<int> ansVec;

    if(s.empty())
        return 0;
    
    reverse(s.begin(),s.end());
    
    while(s.size() && s[s.size()-1] == ' ' ){
        s.pop_back();

    }

    bool neg = false;
    if(s.size() && s[s.size()-1]=='-'){
        cout<<"This RAN\n";
        neg = true;
    }   

    if( s.size() && (s[s.size()-1]=='-' || s[s.size()-1] == '+') ){
        s.pop_back();
    }

    reverse(s.begin(),s.end());
   
    for(int i=0;i<s.size();i++){
        if(!isDigit(s[i])){
            break;
        }
        if(isDigit(s[i])){
            long long int dig = s[i] - '0';
            ansVec.push_back(dig);
        }
    }

    reverse(ansVec.begin(), ansVec.end());
    while(ansVec.size() && ansVec[ansVec.size()-1] == 0){
        ansVec.pop_back();
    }
    reverse(ansVec.begin(), ansVec.end());

    cout<<"ANSVEC Size: "<<ansVec.size()<<endl;
    for(auto &i: ansVec){
        cout<<i;
    }
    cout<<endl;

    if(ansVec.size()>10){
        if(neg){
            return INT_MIN;
        }
        else{
            return INT_MAX;
        }
    }
    else{
        for(int i=0;i<ansVec.size();i++){
            long long int dig = ansVec[i];
            ans+=dig;
            ans*=10;
        }
    }
    ans/=10;
    if(neg)
        ans*=-1;    
    if(ans>=INT_MAX)
        return INT_MAX;
    else if(ans<=INT_MIN)
        return INT_MIN;
    // cout<<"  ---------------------------------------------------------\n";
    return int(ans); 
}

int main(){
    string s;
    cin>>s;
    cout<<myatoi(s)<<endl;
    return 0;
}