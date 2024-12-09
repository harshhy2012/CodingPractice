#include<bits/stdc++.h>

using namespace std;

int numOfWays(int n){
    // base case
    if(n==1 || n==0){
        return 1;
    }
    return numOfWays(n-1)+numOfWays(n-2);
}

int main(){
    int n;
    cin>>n;
    cout<<"num of ways: ";
    cout<<numOfWays(n);
    cout<<endl;

    return 0;
}