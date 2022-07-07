#include<bits/stdc++.h>

using namespace std;

int steps(int n){
    if(n<0){
        return 0;    
    }
    if(n==0){
        return 1;
    }
    int ans = steps(n-2) + steps(n-1);

    return ans;
}
int main(){
    int n;
    cin>>n;
    cout<<steps(n)<<endl;
    return 0;
}