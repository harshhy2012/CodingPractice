#include<bits/stdc++.h>

using namespace std;

void insertionSort(vector<int> &arr){
    int n = arr.size();
    for(int i=1;i<n;i++){
        int key = arr[i];
        int j = i-1;
        while(arr[j]>key && j>=0){
            arr[j+1] = arr[j];
            j--; 
        }
        arr[j+1] = key;
    }
}

int main(){
    ifstream cin("insertionSort.txt");
    if(cin.fail())
    cout<<"Input from file failed";
    int n;
    cin>>n;
    vector<int> arr(n);
    for(auto &i: arr){
        cin>>i;
    }
    insertionSort(arr);
    for(auto i: arr){
        cout<<i<<" ";
    }
    cout<<endl;

    cin.close();
    return 0;
}