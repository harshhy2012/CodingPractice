#include<bits/stdc++.h>

using namespace std;

vector<int> numToArr(long long int n){
    vector<int> ans;
    while(n){
        int dig=n%10;
        ans.push_back(dig);
        n/=10;
    }
    return ans;
}

bool luckyNum(int n){
    return (n==4 || n==7);
}
bool isLucky(int n){
    if(n==0){
        return false;
    }
    bool res = true;
    while(n){
        int dig = n%10;
        if(n!=4 && n!=7){
            res = false;
        }
        n/=10;
    }
    return res;
}

int main(){
    long long int n;
    cin>>n;
    vector<int>digs = numToArr(n);
    int luckyDigs = 0;
    for(int i=0;i<digs.size();i++){
        if(luckyNum(digs[i]))
            luckyDigs++;
    }
    // cout<<"LUCKY DIGITS: "<<luckyDigs<<endl;
    if(isLucky(luckyDigs))
        cout<<"YES\n";
    else
        cout<<"NO\n";
    return 0;
}