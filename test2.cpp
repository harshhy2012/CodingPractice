#include<bits/stdc++.h>

using namespace std;

int findPeakElement(vector<int> &nums) {
    int n = nums.size();
    int maxEl = *max_element(nums.begin(), nums.end());
    if(nums[n-1] == maxEl) return n-1;
    if(nums[0] == maxEl) return 0;

    int beg = 1, end = n-2;

    while(beg<=end){
        int mid = beg + (end-beg)/2;
        if(nums[mid-1]<=nums[mid] && nums[mid]>=nums[mid+1]){
            return mid;
        } else if(nums[mid]>nums[mid-1]){
            beg = mid+1;
        } else{
            end = mid-1;
        }   
    }
    return -1;
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(auto &i: arr){
        cin>>i;
    }
    int ans = findPeakElement(arr);
    cout<<"peak element: "<<arr[ans]<<" || idx: "<<ans<<endl;

    return 0;
}