#include<bits/stdc++.h>

using namespace std;

string longlongToString(long long int ans){
    string x;
    while(ans){
        int dig = ans%10;
        x.push_back('0'+dig);
        ans/=10;
    }
    reverse(x.begin(), x.end());
    return x;
}

string solve(int A) {
    string ret;
    if(A==0 || A==1){
        ret.push_back('0'+A);
        return ret;
    }
    long long int ans = 1;
    for(int i=2;i<=A;i++){
        ans*=i;
    }
    ret = longlongToString(ans);
    return ret;
}

int main(){
    int A;
    cin>>A;
    cout<<solve(A)<<endl;
    return 0;
}