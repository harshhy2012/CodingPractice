#include<bits/stdc++.h>

using namespace std;

void digits(int n){
    if(n==0){
        return;
    }
    n=n/10;
    digits(n);

    int dig = n%10;
    cout<<dig;

}


int main(){
    int n;
    cin>>n;
    vector<int> ans;
    digits(n);


    return 0;
}