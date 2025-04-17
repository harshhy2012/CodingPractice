#include<bits/stdc++.h>

using namespace std;

void moveZeroes(vector<int>& nums) {
    int j = -1, n = nums.size();
    for(int i=0;i<n;i++){
        if(nums[i] == 0){
            j = i;
            break;
        }
    }
    if(j==-1)   return;
    for(int i = j+1;i<n;i++){
        if(nums[i]==0){
            continue;
        } else{
            swap(nums[i], nums[j]);
            j++;
        }
        cout<<"IterDone: ";
        for(auto i: nums){
            cout<<i<<" ";
        }
        cout<<endl;
    }
}


int main(){
    vector<int> nums = {0,1,0,3,12};
    moveZeroes(nums);

    return 0;
}