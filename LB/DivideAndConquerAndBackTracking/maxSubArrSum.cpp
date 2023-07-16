#include<bits/stdc++.h>

using namespace std;

int maxSubArrayHelper(vector<int> nums, int s, int e){
    if(s==e){
        return nums[s];
    }
    int maxLeftBorderSum = INT_MIN, maxRightBorderSum = INT_MIN;
    int mid = s+(e-s)/2;

    int maxLeftSum = maxSubArrayHelper(nums, s, mid);
    int maxRightSum = maxSubArrayHelper(nums, mid+1, e);

    // find max cross border Sum
    int leftBorderSum = 0, rightBorderSum = 0;
    for(int i = mid;i >= s;i--){
        leftBorderSum+=nums[i];
        if(leftBorderSum>maxLeftBorderSum){
            maxLeftBorderSum = leftBorderSum;
        }
    }  
    for(int i = mid;i <= e;i++){
        rightBorderSum+=nums[i];
        if(rightBorderSum>maxRightBorderSum){
            maxRightBorderSum = rightBorderSum;
        }
    }  
    int cbs = maxLeftBorderSum+maxRightBorderSum;
    return max(max(maxLeftBorderSum, maxRightBorderSum), cbs);
 
}

int maxSubArray(vector<int> nums){
    return maxSubArrayHelper(nums, 0, nums.size()-1);    
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(auto &i: arr){
        cin>>i;
    }


    return 0;
}