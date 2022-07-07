#include<bits/stdc++.h>

using namespace std;

bool bSearch(vector<int> arr, int beg, int end, int key){
    if(beg>end)
        return false;
    
    int mid = (beg+end)/2;

    if(arr[mid] == key)
        return true;
    else if(arr[mid]>key)
        return bSearch(arr, beg, mid-1, key);
    else
        return bSearch(arr, mid+1, end, key);

}

int main(){
    int n, key;
    cin>>n;
    vector<int> arr(n);
    for(auto &i:arr){
        cin>>i;
    }

    cin>>key;

    bool ans = bSearch(arr, 0, n, key);

    if(ans)
        cout<<"FOUND\n";
    else
        cout<<"NOT FOUND\n";

    return 0;
}