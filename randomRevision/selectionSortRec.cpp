#include<bits/stdc++.h>

using namespace std;

void selectionSort(vector<int> &arr, int i){
    
    if(i>=arr.size()-2)
        return;
    
    int min = i;
    for(int j=i;j<arr.size();j++){
        if(arr[j]<=arr[min])
            min = j;
    }
    swap(arr[i], arr[min]);
    return selectionSort(arr, i+1);

}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(auto &i: arr){
        cin>>i;
    }

    selectionSort(arr, 0);

    for(auto i: arr){
        cout<<i<<" ";
    }
    cout<<endl;
    
    return 0;
}