#include<bits/stdc++.h>

using namespace std;

void quickSort(vector<int> &arr, int s, int e){
    if(s>=e){
        return;
    }
    int piv = e;
    int i=s-1, j=s;
    while(j<piv){
        if(arr[j]<arr[piv]){
            i++;
            swap(arr[i], arr[j]);
        }
        j++;
    }
    ++i;
    swap(arr[i], arr[piv]);

    quickSort(arr, s, i-1);
    quickSort(arr, i+1, e);

}

int main(){

    int n;
    cin>>n;
    vector<int>arr(n);
    for(auto&i: arr){
        cin>>i;
    }    

    quickSort(arr, 0, n-1);

    for(auto &i: arr){
        cout<<i<<" ";
    }
    cout<<endl;

    return 0;
}