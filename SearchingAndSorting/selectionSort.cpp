#include<bits/stdc++.h>

using namespace std;

void selectionSort(vector<int> &arr){
    int n = arr.size();

    for(int i=0;i<n;i++){
        int min_idx = i;
        for(int j = i;j<n;j++){
            if(arr[min_idx] > arr[j]){
                min_idx = j;
            }
        }
        swap(arr[i],arr[min_idx]);
    }
} 

int main(){
    ifstream cin("selectionSort.txt");
    if(cin.fail())
    cout<<"Input from file failed";
    int n;
    cin>>n;
    vector<int> arr(n);
    for(auto &i: arr){
        cin>>i;
    }
    selectionSort(arr);
    for(auto i: arr){
        cout<<i<<" ";
    }
    cout<<endl;
    cin.close();
    return 0;
}