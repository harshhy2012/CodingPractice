#include<bits/stdc++.h>

using namespace std;

int fact(int n){
    int ans = 1;
    for(int i=2;i<=n;i++){
        ans*=i;
    }
    return ans;
}

int NCR(int n, int r){
    int ans = fact(n)/(fact(n-r)*fact(r));
    return ans;
}

int main(){
    int n;
    cin>>n;

    return 0;
}