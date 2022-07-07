#include<bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(auto &i: arr){
        cin>>i;
    }
    sort(arr.begin(), arr.end());
    reverse(arr.begin(), arr.end());
    int totSum = accumulate(arr.begin(), arr.end(), 0);
    int cursum = 0;
    int ans = 0;
    for(int i=0;i<arr.size();i++){
        cursum+=arr[i];
        ans++;
        if(totSum/2<cursum){
            break;
        }
    }
    cout<<ans<<endl;

    return 0;
}