#include<bits/stdc++.h>

using namespace std;

void mergeSort(vector<int> &arr, int beg, int end){

    



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

    mergeSort(arr, 0, arr.size());

    cin.close();
    return 0;
}