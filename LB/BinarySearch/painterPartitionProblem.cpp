#include<bits/stdc++.h>

using namespace std;

bool isValidPartition(vector<int> arr, int n, int k, int max){
    long long int sum = 0;
    int c = 1;
    for(int i=0;i<n;i++){
        if(arr[i]>max){
            // cout<<"arr[i]>max\nreturned False\n";
                return false;
        }
        if(sum+arr[i]>max){
            c++;
            sum = arr[i];
            // cout<<"C: "<<c<<" || SUM: "<<sum<<endl;
            if(c>k){
                // cout<<"c>n\nreturned False\n";
                return false;
            }
        }
        else{
            // cout<<"sum+=arr[i]\n";
            sum+=arr[i];
        }
        // cout<<"SUM: "<<sum<<" || MID: "<<max<<endl;
    }
    // cout<<"Returned true\n";
    return true;
}

int painterPartition(vector<int> arr, int n, int k){
    if(k>=n){
        return *max_element(arr.begin(), arr.end());
    }
    int s = *min_element(arr.begin(), arr.end()), e = accumulate(arr.begin(), arr.end(), 0);
    int ans = -1;
    int mid;
    while(s<=e){
        // cout<<"S: "<<s<<" || E: "<<e<<endl;
        mid = (s+e)/2;
        if(isValidPartition(arr, n, k, mid)){
            ans = mid;
            e = mid-1;
        }
        else{
            s = mid+1;
        }
        // cout<<"S: "<<s<<" || E: "<<e<<endl;
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
    cout<<painterPartition(arr,n,k);
    return 0;
}