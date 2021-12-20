#include<bits/stdc++.h>

using namespace std;

int findPivot(vector<int> &arr){
    int s = 0, e = arr.size()-1;

    while(s<=e){
        int mid = (s+e)/2;

        if(arr[mid] >= arr[mid-1] && arr[mid] >= arr[mid+1]){
            return mid;
        }
        else if(arr[s] <= arr[mid]){
            s = mid + 1; 
        }
        else if(arr[mid] <= arr[e]){
            e = mid-1;
        }
    } 
    return arr.size()-1;
}

int main(){
    ifstream cin("findPivot.txt");
    if(cin.fail())
    cout<<"Input from file failed";
    int n;
    cin>>n;
    vector<int> arr(n);
    for(auto &i:arr){
        cin>>i;
    }
    int ans = findPivot(arr);
    cout<<"Pivot found at: "<<ans<<endl;

    cin.close();
    return 0;
}