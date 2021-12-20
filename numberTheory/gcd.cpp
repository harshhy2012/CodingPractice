#include<bits/stdc++.h>

using namespace std;

int gcdFast(int a, int b){
    if(a==0)
        return b;
    if(b==0)
        return a;
    else
        return gcdFast(b,a%b);
}

int main(){
    int a, b;
    cin>>a>>b;
    cout<<gcdFast(a,b)<<endl;
    return 0;
}