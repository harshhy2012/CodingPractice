#include<bits/stdc++.h>

using namespace std;

int bs(vector<int> arr, int s, int e, int x){
    int mid = s+(e-s)/2;
    while(s<=e){
        if(arr[mid]==x){
            return mid;
        }
        else if(x<arr[mid]){
            e=mid-1;
        }
        else{
            s = mid+1;
        }
        mid = s+(e-s)/2;
    }
    return -1;
}

int kDiffPairsBrute(vector<int> arr, int k){
    set<pair<int,int>> ans;
    int n = arr.size();
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(abs(arr[j]-arr[i])==k){
                ans.insert({arr[i],arr[j]});
            }
        }
    }
    return ans.size();
}

int kDiffPairs2P(vector<int> arr, int k){
    set<pair<int,int>> ans;
    int n = arr.size();
    sort(arr.begin(), arr.end());
    int i=0,j=1;
    while(j<n){
        if(arr[j]-arr[i]==k){
            ans.insert({arr[i],arr[j]});
            i++;
            j++;
        }
        if(arr[j]-arr[i] > k){
            if(i+1<j){
                i++;
            }
            else{
                i++;
                j++;
            }
        }
        else{
            j++;
        }
    }

    return ans.size();
}

int kDiffPairsBS(vector<int> arr, int k){
    set<pair<int,int>> ans;
    int n = arr.size();
    sort(arr.begin(), arr.end());
    for(int i=0;i<n-1;i++){
        int idx = bs(arr, i, n-1, k+arr[i]);
        if(idx!=-1){
            ans.insert({arr[i],arr[idx]});
        }
    }
    return ans.size();
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
    
        cout<<kDiffPairsBrute(arr, k)<<endl;
        cout<<kDiffPairs2P(arr, k)<<endl;
    cout<<kDiffPairsBS(arr, k)<<endl;
    return 0;
}