#include<bits/stdc++.h>

using namespace std;

int maxIdx(vector<int> arr){
    int max = INT_MIN;
    int maxI =0;
    for(int i=0;i<arr.size();i++){
        if(max<arr[i] && max!=arr[i]){
            max = arr[i];
            maxI = i;
        }
    }
    return maxI;
}

int minIdx(vector<int> arr){
    int min = INT_MAX;
    int minI = 0;
    for(int i=0;i<arr.size();i++){
        if(min>=arr[i]){
            min = arr[i];
            minI = i;
        }
    }
    return minI;
}

int timeReq(vector<int> arr){
    cout<<minIdx(arr)<<endl<<maxIdx(arr)<<endl;
    return 0;
}

int main(){
    ifstream cin("arrivalOfGeneral.txt");
    if(cin.fail())
    cout<<"Input from file failed";
    int n;
    cin>>n;
    vector<int> arr(n);
    for(auto &i: arr){
        cin>>i;
    }
    cout<<timeReq(arr)<<endl;
    cin.close();
    return 0;
}