#include<bits/stdc++.h>

using namespace std;

int missingNumber(vector<int> arr){

    int beg = 0, end = arr.size()-1;
    int mid = 0;
    int ans = -1;
    while(beg<=end){
        mid = beg+(end-beg)/2;
        if( (arr[mid]-1 != arr[mid-1])){
            ans = arr[mid]-1;
            return ans;
        }
        else if(arr[mid]+1 != arr[mid+1]){
            ans = arr[mid]+1;
            return ans;
        } 
        else if(arr[mid]>mid+1){
            end = mid-1;
        }
        else{
            beg = mid+1;
        }
    }   
    return ans;
}

int main(){
    vector<int> arr= {1,2,3,4,5,6,8,9};
    cout<<missingNumber(arr)<<endl;
    return 0;
}