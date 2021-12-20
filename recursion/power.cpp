#include<bits/stdc++.h>

using namespace std;

int power(int n, int m){
    if(m==0)
        return 1;
    return n*power(n,m-1);
}

int fastPow(int n, int m){
    if(m==0)
        return 1;
    
    int smallAns = fastPow(n,m/2);
    smallAns*=smallAns;
    if(m&1)
        return n*smallAns;
    else
        return smallAns;
}

int main(){
    int n,m;
    cin>>n>>m;
    cout<<pow(n,m)<<endl;
    cout<<fastPow(n,m)<<endl;
    return 0;
}