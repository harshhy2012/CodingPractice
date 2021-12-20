#include<bits/stdc++.h>

using namespace std;

int water(vector<int>arr){
    int n = arr.size();
    vector<int> leftMax(n), rightMax(n);
    leftMax[0] = arr[0];
    rightMax[n-1] = arr[n-1];
    int i=1,j=n-2;
    while(i<n && j>=0){
        leftMax[i] = max(arr[i], leftMax[i-1]);
        rightMax[j] = max(arr[j],rightMax[j+1]);
        i++;
        j--; 
    }
    int area = 0;
    for(int i=0;i<n;i++){
        area += min(rightMax[i],leftMax[i])-arr[i];
    }
    return area;
}

int main(){
    ifstream cin("waterHarvesting.txt");
    if(cin.fail())
    cout<<"Input from file failed";
    int n;
    cin>>n;
    vector<int> arr(n);
    for(auto &i: arr){
        cin>>i;        
    }
    cout<<water(arr);
    cin.close();
    return 0;
}