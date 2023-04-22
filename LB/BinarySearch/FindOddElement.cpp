#include<bits/stdc++.h>

using namespace std;

int findOddElement(vector<int> arr){
    int s = 0, e = arr.size()-1;
    int mid;
    while(s<=e){
        mid = s+(e-s)/2;
        if(s==e){
                return s;
            }
        if(mid%2!=0){
            if(mid-1>=0 && arr[mid-1]==arr[mid])
                s = mid+1;
            else if(mid-1>0 && arr[mid-1]!=arr[mid])
                e = mid-1;
        }
        else{
            if(mid+1<arr.size() && arr[mid]==arr[mid+1])
                s = mid+2;
            else if(mid+1<arr.size() && arr[mid]!=arr[mid+1])
                e = mid;
        }
    }
    return -1;
}

int main(){
    vector<int> arr = {2,2,3,3,2,2,4,4,1,1,3,2,2,3,3};

    cout<<"INDEX: "<<findOddElement(arr)<<" || ELEMENT: "<<arr[findOddElement(arr)]<<endl;

    return 0;
}