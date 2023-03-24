#include<bits/stdc++.h>

using namespace std;

int main(){
    int k,n,w;
    cin>>k>>n>>w;
    int totalBananaCost =0;
    for(int i=1;i<=w;i++){
        totalBananaCost+=i*k;
    }
    int moneyRequired = totalBananaCost-n;
    if(moneyRequired>0){
        cout<<moneyRequired<<endl;
    }
    else{
        cout<<0<<endl;
    }
    return 0;
}