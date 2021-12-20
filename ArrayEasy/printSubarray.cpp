#include<bits/stdc++.h>

using namespace std;
//brute force
void printSubArr(vector<int> arr){
    for(int i=0;i<arr.size();i++){
        for(int j=i;j<arr.size();j++){
            for(int k=i;k<=j;k++){
                cout<<arr[k]<<" ";
            }
            cout<<endl;
        }
    }
}

//using precomputation
void printSubArr2(vector<int> arr){
    vector<int> cum(arr.size()+1);
    cum[0] = 0;
    for(int i=1;i<cum.size();i++){
        cum[i] = arr[i-1]+cum[i-1];
    }
    for(auto i: cum){
        cout<<i<<" ";
    }
    cout<<endl;
    int left = -1;
    int right = -1;
    int subArrSum = 0;
    int maxSum = INT_MIN;
    for(int i=1;i<cum.size();i++){
        for(int j=i;j<cum.size();j++){
            subArrSum = cum[j]-cum[i-1];
            if(maxSum<subArrSum){
                left =i-1;
                right = j;
                maxSum = subArrSum;
            }
                
            cout<<"arrSum from "<<i<<"th index to "<<j<<"th index: "<<subArrSum<<endl;
        }
    }
    cout<<"MAX_SUM: "<<maxSum<<endl;
    for(int i=left;i<right;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

//kadane's algo
void printSubArr3(vector<int>&arr){
    int maxSum = INT_MIN, curSum = 0;
    for(int i=0;i<arr.size();i++){
        if(curSum+arr[i]>=0)
            curSum+=arr[i];
        else   
            curSum=0;
        if(curSum>maxSum){
            maxSum=curSum;
        }
    }
    cout<<"MAX_SUM: "<<maxSum<<endl;
}


int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(auto&i: arr){
        cin>>i;
    }   
    printSubArr3(arr);
    return 0;
}