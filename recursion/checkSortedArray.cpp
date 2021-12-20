#include<bits/stdc++.h>

using namespace std;

bool isSortedRec(vector<int> arr, int n){
    if(n==0)
        return true;

    if(arr[n]>=arr[n-1])
        return isSortedRec(arr,n-1);
    else  
        return false;
    
    
}

int main(){
    ifstream cin("checkSortedArray.txt");
    if(cin.fail())
    cout<<"Input from file failed";
    int n;
    cin>>n;
    vector<int> arr(n);
    for(auto &i: arr){
        cin>>i;
    }
    if(isSortedRec(arr, arr.size()-1))
        cout<<"Sorted\n";
    else
        cout<<"Not Sorted\n";
    cin.close();
    return 0;
}