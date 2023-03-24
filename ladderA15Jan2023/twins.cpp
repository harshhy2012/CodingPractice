#include<bits/stdc++.h>

using namespace std;

const bool compare(int a, int b){
    return a>b;
}

int ans(vector<int> arr){
    int n = arr.size();
    sort(arr.begin(), arr.end(), compare);
    int ans = 0;
    int tSum = accumulate(arr.begin(), arr.end(), 0);
    int curSum = 0;
    for(int i=0;i<n;i++){
        curSum+=arr[i];
        ans++;
        if(tSum/2<curSum){
            break;
        }
    }
    return ans;
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(auto &i: arr){
        cin>>i;
    }
    cout<<ans(arr)<<endl;
    return 0;
}