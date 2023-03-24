#include<bits/stdc++.h>

using namespace std;

vector<int> missingNumNegetiveMarking(vector<int> arr){
    int n = arr.size();
    vector<int> ans;
    for(int i=0;i<n;i++){
        int index = abs(arr[i]);
        if(arr[index-1]>0){
            arr[index-1]*=-1;
        }
    }
    for(int i=0;i<n;i++){
        if(arr[i]>0)
            ans.push_back(i+1);
    }
    cout<<"ANS ARRAY: ";
    for(auto i: arr)
    {
        cout<<i<<" ";
    }
    cout<<endl;
    return ans;
}

vector<int> missingNumSwappingSorting(vector<int> arr){
    int n = arr.size();
    vector<int> ans;
    for(int i=0;i<n;){
        if(arr[arr[i]-1]!=arr[i]){
            swap(arr[arr[i]-1], arr[i]);
        }
        else{
            i++;
        }
    }
    for(auto i: arr){
        cout<<i<<" ";
    }
    cout<<endl;
    for(int i=0;i<n;i++){
        if(i+1!=arr[i]){
            ans.push_back(i+1);
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

    for(auto i: missingNumNegetiveMarking(arr)){
        cout<<i<<" ";
    }
    cout<<endl;
    for(auto i: missingNumSwappingSorting(arr)){
        cout<<i<<" ";
    }
    cout<<endl;

    return 0;
}