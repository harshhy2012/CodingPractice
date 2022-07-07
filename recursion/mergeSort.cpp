#include<bits/stdc++.h>

using namespace std;

vector<int> merge(vector<int> &arr, int s, int e){
    int n = arr.size();
    int mid = (s+e)/2;
    vector<int> ans;
    int i=0;
    int j = mid+1;

    while(i<=mid && j<n){
        if(arr[i]>=arr[j]){
            ans.push_back(arr[j]);
            j++;
        }
        else{
            ans.push_back(arr[i]);
            i++;
        }

        while(i<=mid){
            ans.push_back(arr[i]);
            i++;
        }
        while(j<n){
            ans.push_back(arr[j]);
            j++;
        }
    } 

    cout<<"MERGED ARR: ";

    for(auto i: ans){
        cout<<i<<" ";
    }
    cout<<endl;
    return ans;

}

void mergeSort(vector<int> &arr, int s, int e){
    // Base Case
    if(s+1>=e)
        return;
    //rec case
    int mid = (s+e)/2;

    mergeSort(arr, s, mid);
    mergeSort(arr, mid+1,e);
    arr = merge(arr, s, e);
}

int main(){
    ifstream cin("mergeSort.txt");
    if(cin.fail())
        cout<<"Input from file failed";
    
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
    cin.close();
    return 0;
}