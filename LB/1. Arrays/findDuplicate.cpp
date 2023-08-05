#include<bits/stdc++.h>

using namespace std;

int findDuplicateSwapPlaces(vector<int> arr){
    while(arr[0]!=arr[arr[0]]){
        swap(arr[0],arr[arr[0]]);
    }
    return arr[0];
}

int findDuplicateBinarySearch(vector<int> arr){
    int n = arr.size();
    int low = 0, high = n-1;
    int count;
    int ans=-1;
    while(low<=high){
        int curr = (low+high)/2;
        for(int i=0;i<n;i++){
            if(arr[i]<=curr){
                count++;
            }
        }
        if(count>curr){
            ans = curr;
            high = curr-1;
        }
        else{
            low = curr+1;
        }
    }
    return ans;
}

int findDuplicateNegetive(vector<int> arr){
    int n = arr.size();
    int ans = -1;
    for(int i=0;i<n;i++){
        int index = abs(arr[i]);
        if(arr[index]<0){
            ans = index;
            break;
        }
        arr[index] = -arr[index];
    }
    return ans;
}

// int findDuplicateBitManipulation(vector<int> arr){
//     int n = arr.size()-1;
//     int mask=0;
    
    
//     for(int i=1;i<=n;i++){
//         x|=i;
//     }

//     cout<<x;
//     cout<<endl;
//     for(int i=0;i<arr.size();i++){
//         y|=arr[i];
//     }
//     cout<<y;
//     return abs(x-y);
// }

int main(){
    int n;
    cin>>n;
    vector<int> arr(n+1);
    for(auto &i: arr){
        cin>>i;
    }

    cout<<findDuplicateBinarySearch(arr)<<endl;
    cout<<findDuplicateNegetive(arr)<<endl;

    return 0;
}