#include<bits/stdc++.h>

using namespace std;

int fastMultiply(int a, int b){
    if(b==0||a==0)
        return 0;
    if(b==1)
        return a;
    int smallAns = 0;
    //if one num is -ve
    if(a<0&&b>=0 || a>=0 && b<0){
        a = abs(a);
        b = abs(b);
        smallAns = fastMultiply(a,b/2);
        smallAns += smallAns;
        smallAns = -smallAns;
        if(b&1)
            return smallAns-a;
        else
            return smallAns;
    }
    //if both numbers are positive or negetive
    else{
        a = abs(a);
        b = abs(b);
        smallAns = fastMultiply(a,b/2);
        smallAns += smallAns;
        if(b&1)
            return a+smallAns;
        else
            return smallAns;
    }
    
}

int main(){
    int a,b;
    cin>>a>>b;
    cout<<fastMultiply(a,b)<<endl;
    return 0;
}