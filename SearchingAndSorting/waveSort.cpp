#include<bits/stdc++.h>

using namespace std;

void waveSort(vector<int>&arr){
    int n = arr.size();
    int i = 0 ,j = 1,k = 2;
    while(j<n-1){
        if(arr[i]<arr[j] && arr[j]<arr[k]){
            swap(arr[i], arr[j]);
        }
        if(arr[j]<arr[k] && arr[i]<arr[j]){
            swap(arr[j], arr[k]);
        }
        i++;
        j++;
        k++;
    }
}

int main(){
    ifstream cin("waveSort.txt");
    if(cin.fail())
    cout<<"Input from file failed";
    int n;
    cin>>n;
    vector<int>arr(n);
    for(auto&i:arr){
        cin>>i;
    }

    waveSort(arr);
    for(auto i: arr){
        cout<<i<<" ";
    }
    cout<<endl;

    cin.close();
    return 0;
}