#include<bits/stdc++.h>

using namespace std;

void merge1(vector<int>&arr, int s, int mid, int e){
    // for inplace merge we can use 2 ways
    // 1. QuickSort Partition logic we can use to sort 2 arrays
    //      Start 2 pointers i and j from s ans mid+1 respectively
    //      Keep moving i until we get an element such that arr[i]>arr[j]
    //      when arr[i]>arr[j] swap(arr[i],arr[j])
    //      after swapping put the swapped j element to its correct position. and set j as mid+1 again
    int i = s, j = mid+1;
    while(i<=mid && j<=e){
        if(arr[i]>arr[j]){
            swap(arr[i],arr[j]);
            int k = j;
            while(arr[k]>arr[k+1] && k<e){
                swap(arr[k],arr[k+1]);
                k++;
            }
            j=mid+1;                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                             
        }
        i++;
    }
}

void merge2(vector<int>&arr, int s, int mid, int e){
    // for inplace merge we can use 2 ways
    // 2. Gap Method
    //      take a gap variable and set it as ceil((n+m)/2) or we can use gap = (total_size/2)+( total_size%2)
    //      initialize i = s and j = i+gap and swap if arr[i]>arr[j]
    //      in 1 iteration we will increment i and j until j>e
    //      after that update gap = ceil(gap/2)
    //      when gap/2<1 break;
    int total_size = e-s+1;
    int gap = ((total_size)/2)+((total_size)%2);

    while(gap){
        int i = s, j = i+gap;
        while(j<=e){
            if(arr[i]>arr[j])
                swap(arr[i], arr[j]);
            i++;
            j++;
        }
        gap = (gap/2) < 1 ? 0 : (gap/2)+(gap%2);   
    }
}

void mergeSortInPlace(vector<int>&arr, int s, int e){
    if(s>=e){
        return;
    }
    int mid = s+(e-s)/2;

    mergeSortInPlace(arr, s, mid);
    mergeSortInPlace(arr, mid+1, e);
    merge2(arr, s, mid, e);
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(auto &i: arr){
        cin>>i;
    }

    mergeSortInPlace(arr, 0, n-1);

    for(auto i: arr){
        cout<<i<<" ";
    }
    cout<<endl;

    return 0;
}