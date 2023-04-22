#include<bits/stdc++.h>

using namespace std;

vector<int> kClosestOptimal(vector<int> arr, int k, int x){
     int left = 0,right = arr.size()-k-1,mid;
        vector<int> result;
        while(left <= right){
            mid = left + (right - left) / 2;
            if(x - arr[mid] > arr[mid+k] - x){
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        cout<<"LEFT: "<<left<<" || RIGHT: "<<right<<endl;
        for(int i = 0; i<k;i++){
             result.push_back(
                 arr[left+i]);
        }
        return result;
}

int lowerBound(vector<int> arr, int x){
    int s = 0, e = arr.size()-1;
    int ans = e;
    while(s<=e){
        int mid = s+(e-s)/2; 
        if(arr[mid] >= x){
            ans = mid;
            e = mid-1;
        }
        else if(x > arr[mid])
            s = mid+1;
        else
            e = mid-1;
    }
    return ans;
}

vector<int> kClosest(vector<int> arr, int k, int x){
    int i=0,j=0, n = arr.size();
    j = lowerBound(arr, x);
    i=j-1;
    //cout<<"I: "<<i<<" || J: "<<j<<endl; 
    while(k--){
        if(i<0){
            j++;
        }
        else if(j >= n){
            i--;
        }
        else if(x-arr[i] > arr[j]-x){
            j++;
        }
        else{
            i--;
        }
        //cout<<"I: "<<i<<" || J: "<<j<<" || K: "<<k<<endl; 
    }
    return vector<int>(arr.begin()+i+1,arr.begin()+j);
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(auto &i: arr){
        cin>>i;
    }
    int k,x;
    cin>>k>>x;

    vector<int> ans = kClosestOptimal(arr, k, x);

    for(auto i: ans){
        cout<<i<<" ";
    }
    cout<<endl;

    return 0;
}