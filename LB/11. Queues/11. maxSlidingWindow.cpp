#include<bits/stdc++.h>

using namespace std;


void printQueue(deque<int> q){
    while(!q.empty()){
        cout<<q.front()<<" ";
        q.pop_front();
    }
    cout<<endl;
}

vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    deque<int> dq;
    vector<int> ans;
    int i=0;
    for(i=0;i<k;i++){
        while(!dq.empty() && nums[i] >= nums[dq.back()]){
            dq.pop_back();
        }
        dq.push_back(i);
    }

    ans.push_back(nums[dq.front()]);

    for(int i=k;i<nums.size();i++){
        if(!dq.empty() && i-k >= dq.front()){
            dq.pop_front();
        }
        while(!dq.empty() && nums[i] >= nums[dq.back()]){
            dq.pop_back();
        }
        dq.push_back(i);
        ans.push_back(nums[dq.front()]);
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
    int k;
    cin>>k;
    vector<int> maxSlidWin = maxSlidingWindow(arr, k);
    for(auto i: maxSlidWin){
         cout<<i<<" ";
    }
    return 0;
}