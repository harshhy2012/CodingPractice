#include<bits/stdc++.h>

using namespace std;

int ans(int a, int b){
    if(a==b){
        return 1;
    }
    int ans = 0;
    while(a<=b){
        a*=3;
        b*=2;
        ans++;
    }
    return ans;
}

int main(){
    int a,b;
    cin>>a>>b;
    
    cout<<ans(a,b)<<endl;

    return 0;
}
