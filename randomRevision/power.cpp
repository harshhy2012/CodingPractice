#include<bits/stdc++.h>

using namespace std;

int fastPow(int a, int b){
    if(b==0)
        return 1;
    int ans = pow(a,b/2);
    if(b%2==0)
        ans *= ans;
    else
        ans *= a*ans;

    
    return ans;
}

int pow(int a, int b){
    if(b==0)
        return 1;
    
    int ans = a*pow(a,b-1);
    cout<<"(slow)"<<ans<<endl;
    return ans;
}

int main(){
    int a,b;
    cin>>a>>b;
    cout<<pow(a,b)<<endl;
    cout<<fastPow(a,b)<<endl;
    return 0;
}