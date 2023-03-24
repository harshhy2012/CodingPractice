#include<bits/stdc++.h>

using namespace std;

struct vec{
    int i;
    int j;
    int k;
};

bool inEquilibrium(vector<vec> arr){
    int i,j,k;
    i = j = k = 0;
    for(auto x: arr){
        i+=x.i;
        j+=x.j;
        k+=x.k;
    }
    return (i==0&&j==0&&k==0);
}

int main(){
    int n;
    cin>>n;
    vector<vec> arr(n);
    for(auto &x: arr){
        cin>>x.i>>x.j>>x.k;
    }
    if(inEquilibrium(arr))
        cout<<"YES\n";

    else
        cout<<"NO\n";
    return 0;
}x