#include<bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    int ans = 0;
    for(auto &i: arr){
        cin>>i;
        if(i==1){
            ans = 1;
        }
    }
    if(ans==1){
        cout<<"HARD\n";
    }
    else{
        cout<<"EASY\n";
    }
    
    return 0;
}