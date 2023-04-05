#include<bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int a, b, n;
        cin>>a>>b>>n;
        int sum = max(a,b);
        int x=0;
        while(sum<=n){
            if(x%2==0){
                a+=b;
            }   
            else{
                b+=a;
            }
            sum = max(a,b);
            x++;
        }
        if(a)
        cout<<x<<endl;
    }
    return 0;
}