#include<bits/stdc++.h>

using namespace std;

vector<int> maxInKElements(vector<int> arr, int k){
    int n = arr.size();
    deque<int> deq(k);
    vector<int> ans;

    int i = 0;
    for(;i<k;i++){
        while(!deq.empty() && arr[deq.back()] <= arr[i]){
            deq.pop_back();
        }
        deq.push_back(i);
    }

    for(;i<n;i++){
        ans.push_back(arr[deq.front()]);
        // contraction
        while(!deq.empty() && deq.front() <= i-k){
            deq.pop_front();
        }

        while(!deq.empty() && arr[deq.back()] <= arr[i]){
            deq.pop_back();
        }
        // expansion
        deq.push_back(i);
    }
    ans.push_back(arr[deq.front()]);
    return ans;
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(auto &i: arr){
        cin>>i;
    }

    int k;
    cin>>k;

    vector<int> ans = maxInKElements(arr, k);
    for(auto i: ans){
        cout<<i<<" ";
    }
    cout<<endl;

    return 0;
}