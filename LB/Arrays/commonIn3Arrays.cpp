#include<bits/stdc++.h>

using namespace std;

vector<int> commonEle(vector<int> arr, vector<int> brr, vector<int> crr){
     int a = arr.size(), b = brr.size(), c = crr.size();
     int i=0,j=0,k=0;
     vector<int> ans;
    while(i<a && j<b && k<c){
        if(arr[i]==brr[j] && brr[j] == crr[k]){
            ans.push_back(arr[i]);
            i++;j++;k++;
        }
        int lowest = min(arr[i], min(brr[j],crr[k]));
        if(lowest==arr[i]){
            i++;
        }
        else if(lowest==brr[j]){
            j++;
        }
        else{
            k++;
        }
    }   
    return ans;
}

int main(){
    int a,b,c;
    cin>>a>>b>>c;
    //
    vector<int> arr(a), brr(b), crr(c);
    for(auto &i: arr){
        cin>>i;
    }
    for(auto &i: brr){
        cin>>i;
    }
    for(auto &i: crr){
        cin>>i;
    }
   
    for(auto i: commonEle(arr,brr,crr)){
        cout<<i<<" ";
    }
    cout<<endl;

    return 0;
}