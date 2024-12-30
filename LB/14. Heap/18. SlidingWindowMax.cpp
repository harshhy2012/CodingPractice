#include<bits/stdc++.h>

using namespace std;

class Compare{
    public:
        bool operator()(pair<int, int> a, pair<int,int> b){
            return a.first < b.first;
        }  
};

vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    priority_queue<pair<int, int>, vector<pair<int,int>>, Compare> maxHeap;
    int i=0;
    for(;i<k;i++){
        maxHeap.push({nums[i], i});
    }
    vector<int> ans;
    ans.push_back(maxHeap.top().first);
    for(;i<nums.size();i++){
        maxHeap.push({nums[i], i});
        while(maxHeap.top().second <= i-k){
            maxHeap.pop();
        }
        pair<int,int> currTop = maxHeap.top();
        ans.push_back(currTop.first);
    }
    return ans;
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(auto&i: arr){
        cin>>i;
    }
    int k; cin>>k;

    vector<int> ans =  maxSlidingWindow(arr, k);

    cout<<"ANs: ";
    for(auto i: ans){
        cout<<i<<" ";
    }
    cout<<endl;
    return 0;
}