#include<bits/stdc++.h>

using namespace std;

int  fibo(int n){
    // base
    if(n==1||n==0){
        return n;
    }
    return fibo(n-2) + fibo(n-1);
}

int main(){
    int n;
    cin>>n; 
    for(int i=0;i<=n;i++)
        cout<<fibo(i)<<" ";
    return 0;
}