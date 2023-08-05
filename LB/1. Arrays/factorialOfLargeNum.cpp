#include<bits/stdc++.h>

using namespace std;

vector<unsigned long long> largeFactorial(int n){
    vector<unsigned long long> ans;
    ans.push_back(1);
    unsigned long long carry = 0;
    for(long long i=2;i<=n;i++){
        for(unsigned long long j=0;j<ans.size();j++){
            unsigned long long x = ans[j]*i+carry;
            ans[j] =  x%10;
            carry = x/10;
        }
        while(carry){
            ans.push_back(carry%10);
            carry/=10;
        }
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

int main(){
    int n;
    cin>>n;
 
    for(auto i: largeFactorial(n)){
        cout<<i;
    }
    cout<<endl;
    return 0;
}