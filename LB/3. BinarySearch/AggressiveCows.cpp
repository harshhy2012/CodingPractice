#include<bits/stdc++.h>

using namespace std;

bool isPossible(vector<int> arr, int k, int dist){
    int n = arr.size();
    int c = 1;
    int prevPlace = 0;
    for(int i=1;i<n;i++){
        if(abs(arr[i]-arr[prevPlace])>=dist){
            c++;
            prevPlace = i;
        }
        if(c>=k){
            return true;
        }
    }
    return false;
}

int aggressiveCows(vector<int> arr, int k){
    sort(arr.begin(), arr.end());
    int n = arr.size();
    int s =0, e = *max_element(arr.begin(), arr.end()) - *min_element(arr.begin(), arr.end());
    int mid;
    int ans = 0;
    while(s<=e){
        mid = (s+e)/2;
        if(isPossible(arr,k,mid)){
            ans = mid;
            s = mid+1;
        }
        else{
            e = mid-1;
        }
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
    cout<<aggressiveCows(arr, k);
    return 0;
}