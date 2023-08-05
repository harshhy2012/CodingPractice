#include<bits/stdc++.h>

using namespace std;

int minNum(vector<int>& arr, int tar){
    if(tar==0){
        return 0;
    }
    if(tar<0){
        return INT_MAX;
    }
    int mini = INT_MAX;
    for(auto coin: arr){
        int ans = minNum(arr, tar-coin);
        if(ans!=INT_MAX)
            ans+=1;
        mini = min(ans, mini);
    }
    return mini;

}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(auto &i: arr){
        cin>>i;
    }
    int tar;
    cin>>tar;
    cout<<minNum(arr, tar)<<endl;
    return 0;
}