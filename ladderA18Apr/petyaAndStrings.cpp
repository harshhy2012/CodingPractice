#include<bits/stdc++.h>

using namespace std;

int main(){
    string a, b;
    cin>>a>>b;
    int n = b.size();
    int ans;
    for(int i=0;i<n;i++){
        if(tolower(a[i]) > tolower(b[i])){
            ans=1;
            break;
        }
        else if(tolower(a[i])<tolower(b[i])){
            ans=-1;
            break;
        }
        ans=0;
    }
    cout<<ans<<endl;
    return 0;
}