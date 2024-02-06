#include<bits/stdc++.h>

using namespace std;

vector<int> firstNegNumInK(vector<int>&arr, int k){
    deque<int> q;
    int i = 0;
    int n = arr.size();
    vector<int> ans;
    for(i=0;i<k;i++){
        if(arr[i]<0){
            q.push_back(i);
        }
    }
    if(!q.empty() && arr[q.front()]<0 ){
        ans.push_back(arr[q.front()]);
    } else{
        ans.push_back(0);
    }
    for(;i<n;i++){
        if(!q.empty() && i-k>=q.front()){
            q.pop_front();
        }
        if(arr[i]<0){
            q.push_back(i);
        }
        if(!q.empty() && arr[q.front()]<0){
            ans.push_back(arr[q.front()]);
        } else{
            ans.push_back(0);
        }
        cout<<"ANS: ";
        for(auto i: ans){
            cout<<i<<" ";
        }
        cout<<endl;
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

    vector<int> ans = firstNegNumInK(arr, k);

    cout<<"finAns: ";
    for(auto i: ans){
        cout<<i<<" ";
    }
    cout<<endl;

    return 0;
}