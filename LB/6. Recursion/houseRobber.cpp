#include<bits/stdc++.h>

using namespace std;

int robbery(vector<int> arr, int i, int ans1, int ans2){
    if(i>=arr.size()){
        return 0;
    }
    ans1 = robbery(arr, i+1, ans1, ans2);
    cout<<"ANS1: "<<ans1<<" || ANS2: "<<ans2<<endl;
    ans2 = arr[i]+robbery(arr, i+2, ans1, ans2);
    cout<<"ANS1: "<<ans1<<" || ANS2: "<<ans2<<endl;
    return max(ans1, ans2);
}

int main(){
    int n;
    cin>>n;
    vector<int> houses(n);
    for(auto &i: houses){
        cin>>i;
    }
    int ans1 = 0, ans2 = 0;
    cout<<robbery(houses, 0, ans1, ans2);
    return 0;
}