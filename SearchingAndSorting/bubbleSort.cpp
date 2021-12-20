#include<bits/stdc++.h>

using namespace std;

void bubbleSort(vector<int> &arr){
    int n = arr.size();
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(arr[i]>arr[j])
                swap(arr[i], arr[j]);
        }
        for(auto i: arr){
            cout<<i<<" ";
        }
        cout<<endl;
    }
}

int main(){
    ifstream cin("bubbleSort.txt");
    if(cin.fail())
    cout<<"Input from file failed";
    int n;
    cin>>n;
    vector<int> arr(n);
    for(auto &i: arr){
        cin>>i;
    }
    bubbleSort(arr);
    for(auto i: arr){
        cout<<i<<" ";
    }
    cout<<endl;
    cin.close();
    return 0;
}