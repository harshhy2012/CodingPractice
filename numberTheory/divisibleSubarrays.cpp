#include<bits/stdc++.h>

using namespace std;

int fact(int n){
    if(n==0)
        return 1; 
    int ans = 1;
    for(int i=2;i<=n;i++){
        ans*=i;
    }
    return ans;
}
int comb(int n, int r){
    return fact(n)/(fact(abs(n-r))*fact(r));
}

// o(n^3) method
// calculate sum of every subarray and see
int solveNCube(vector<int> arr){
    cout<<"\n*************************************************\n";
    cout<<"O(N^3)";
    cout<<"\n*************************************************\n";
    int ans = 0;
    for(int i=1;i<arr.size();i++){
        for(int j=i;j<arr.size();j++){
            int sum = 0;
            for(int k=i;k<=j;k++){
                sum+=arr[k];
            }
            if(sum%(arr.size()-1)==0){
                ans++;
            }
                
        }
    }
    return ans;
}
// o(n^2) method
// calculate cumulative sum anf find sum of each subarray
int solveNSquare(vector<int> arr){
    cout<<"\n*************************************************\n";
    cout<<"O(N^2)";
    cout<<"\n*************************************************\n";
    int ans = 0;
    vector<int> cumSum(arr.size(),0);
    for(int i=1;i<cumSum.size();i++){
        cumSum[i] = arr[i]+cumSum[i-1];
    }
    for(int i=1;i<arr.size();i++){
        int sum = 0;
        for(int j=i;j<arr.size();j++){
            sum = cumSum[j] - cumSum[i-1];
            if(sum%(arr.size()-1)==0){
                ans++;
            }
        }
            
    }
    return ans;
}
//o(n) method
//pegion hole principle
int solveNPegion(vector<int> arr){
    cout<<"\n*************************************************\n";
    cout<<"O(N)";
    cout<<"\n*************************************************\n";
    int ans = 0;
    vector<int> cumSum(arr.size(),0);
    for(int i=1;i<cumSum.size();i++){
        cumSum[i] = ((arr[i]+cumSum[i-1])%(arr.size()-1));
    }

    vector<int> ansArr(arr.size()-1);
    for(int i=0;i<cumSum.size();i++){
        ansArr[cumSum[i]]++;
    }
    for(int i=0;i<ansArr.size();i++){
        ans+=comb(ansArr[i],2);
    }

    return ans;
}


int main(){
    ifstream cin("divisibleSubarrays.txt");
    if(cin.fail())
    cout<<"Input from file failed";
    int n;
    cin>>n;
    vector<int> arr(n+1);
    for(int i=1;i<=n;i++){
        cin>>arr[i];
    }
    cout<<solveNCube(arr)<<endl;
    cout<<solveNSquare(arr)<<endl;
    cout<<solveNPegion(arr)<<endl;
    cin.close();
    return 0;
}