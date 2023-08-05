#include<bits/stdc++.h>

using namespace std;

int reverse(int n){
    int rev = 0;
    while(n){
        int dig = n%10;
        rev+=dig;
        rev*=10;
        n/=10;
    }
    return rev/10;
}

const bool cmp(string t1, string t2){
    return ( t1+t2 ) > ( t2+t1 );
}


string largestNumber(vector<int>&nums){
    vector<string> snums;
    for(auto i: nums){
        snums.push_back(to_string(i));
    }
    sort(snums.begin(), snums.end(), cmp);
    string ans="";
    for(auto i: snums){
        ans+=i;
    }
    return ans;
}

int main(){
    int n;
    cin>>n;
    vector<int> nums(n);
    for(auto &i: nums){
        cin>>i;
    }

    cout<<largestNumber(nums)<<endl;

    return 0;
}