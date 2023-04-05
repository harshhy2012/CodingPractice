#include<bits/stdc++.h>

using namespace std;

long double sqrt(int n, int pre){
    int s = 0, e = n/2;
    long double ans = 0, finalAns = 0;
    int mid;
    while(s<=e){
        mid = s+(e-s)/2;
        if(mid*mid <= n){
            ans = mid;
            s = mid+1;
        }
        else if(mid*mid>n){
            e = mid-1;
        }
        else{
            s = mid+1;
        }
    }
    long double dec = 0.1;
    for(int i=0;i<pre;i++){
        while(finalAns*finalAns<=n){
            finalAns+=dec;
        }
        finalAns-=dec;
        dec/=10;
    }
    return finalAns;
}

int main(){
    int n,p;
    cin>>n>>p;
    cout<<sqrt(n,p)<<endl;
    return 0;
}