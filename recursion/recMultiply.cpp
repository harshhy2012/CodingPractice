#include<bits/stdc++.h>

using namespace std;

int recMul(int n, int m){
    if(m==0||n==0)
        return 0;
    if(m==1)
        return n;
    int smallAns = 0;
    //if one num is -ve
    if(n<0&&m>=0 || n>=0 && m<0){
        n = abs(n);
        m = abs(m);
        smallAns = recMul(n,m/2);
        smallAns*= (-2);
        if(m&1)
            return smallAns-n;
        else
            return smallAns;
    }
    //if both numbers are positive or negetive
    else{
        n = abs(n);
        m = abs(m);
        smallAns = recMul(n,m/2);
        smallAns*= 2;
        if(m&1)
            return n+smallAns;
        else
            return smallAns;
    }
    
}

int main(){
    int n,m;
    cin>>n>>m;
    cout<<recMul(n,m)<<endl;
    return 0;
}