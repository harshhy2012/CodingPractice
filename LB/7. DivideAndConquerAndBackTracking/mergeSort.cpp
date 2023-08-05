#include<bits/stdc++.h>

using namespace std;

void merge(vector<int> &arr, int s, int e){
    int mid = s+(e-s)/2;
    int len1, len2;
    len1 = mid-s+1; len2 = e-mid;
    vector<int> left(len1), right(len2);
    int x = s;
    for(int i=0;i<len1;i++){
        left[i] = arr[x];
        x++;
    }
    for(int i=0;i<len2;i++){
        right[i] = arr[x];
        x++;
    }

    int i=0,j=0,k=s;
    while(i<len1 && j<len2){
        if(left[i]<=right[j]){
            arr[k++] = left[i++];
        }
        else{
            arr[k++] = right[j++];
        }
    }

    while(i<len1){
        arr[k++] = left[i++];
    }

    while(j<len2){
        arr[k++] = right[j++];
    }
    for(auto i: arr){
        cout<<i<<" ";
    }
    cout<<endl;
}

void mergeSort(vector<int> &arr, int s, int e){
    if(s>=e){
        return;
    }
    int mid = s+(e-s)/2;

    mergeSort(arr, s, mid);
    cout<<"RETURNED From s->mid\n";
    mergeSort(arr, mid+1, e);
        cout<<"RETURNED From mid+1->e\n";
    merge(arr, s, e);
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(auto &i: arr){
        cin>>i;
    }
    mergeSort(arr, 0, n-1);
    for(auto i: arr){
        cout<<i<<" ";
    }
    cout<<endl;
    return 0;
}