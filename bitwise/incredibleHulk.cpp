#include<bits/stdc++.h>

using namespace std;

int minJumps(int n){
    int jumps = 0;
    while(n){
        jumps++;
        n = n&(n-1);
    }
    return jumps;
}

int main(){
    ifstream cin("incredibleHulk.txt");
    if(cin.fail())
    cout<<"Input from file failed";
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        cout<<minJumps(n)<<endl;
    }
    cin.close();
    return 0;
}