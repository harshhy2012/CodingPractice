#include<bits/stdc++.h>

using namespace std;

int numSetBit(int n){
    int ans = 0;
    while(n>0){
        if(n&1)
            ans++;
        (n>>=1);
    }
    return ans;
}

int numSetBitFast(int n){
    int count=0;
    while(n){
        count++;
        n = n&(n-1);
    }
    return count;
}

int noFlips(int x, int y){
    return (numSetBit(x^y)); 
}

int main(){
    ifstream cin("noOfFlips.txt");
    if(cin.fail())
    cout<<"Input from file failed";
    int x, y;
    cin>>x>>y;
    cout<<noFlips(x,y)<<endl;
    cin.close();
    return 0;
}