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

int main(){
    ifstream cin("numberOfSetBits.txt");
    if(cin.fail())
    cout<<"Input from file failed";
    int n;
    cin>>n;
    cout<<numSetBit(n)<<endl;
    cin.close();
    return 0;
}