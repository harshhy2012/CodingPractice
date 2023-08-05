#include<bits/stdc++.h>

using namespace std;

int main(){

    int n, k;
    cin>>n>>k;
    int mask=1;
    mask = mask<<k;
    cout<<(mask|n)<<endl;
    return 0;
}