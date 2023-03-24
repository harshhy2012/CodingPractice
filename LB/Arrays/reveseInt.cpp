#include<bits/stdc++.h>

using namespace std;

int reverseIt(int n){
    int ans=0;
    while(n){
        ans*=10;
        int dig = n%10;
        ans+=dig;
        n=n/10;
    }
    return ans;
}

int main(){
    int n;
    cin>>n;
    cout<<reverseIt(n)<<endl;
    return 0;
}