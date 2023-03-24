#include<bits/stdc++.h>

using namespace std;

vector<int> maxset(vector<int> &A) {
    long long subSum = 0, maxSubSum = LLONG_MIN;
    vector<int> ans;
    int x=0, y=-1;
    for(int i=0;i<A.size();i++){
        if(A[i]>=0){
            subSum+=(long long)A[i];
            y++;
        }
        else{
            if(maxSubSum<subSum){
                ans.clear();
                y = i;
                maxSubSum = subSum;
                subSum=0;
                for(int i=x;i<y;i++){
                    ans.push_back(A[i]);
                }
                x = i+1;
                y = i;
            }
            else{
                subSum=0;
                x = i+1;
                y = i; 
            }
        }
         cout<<"MAX SUM: "<<maxSubSum<<" | SUM: "<<subSum<<endl;
         cout<<"ANS: ";
         for(auto i: ans){
            cout<<i<<" ";
         }
         cout<<endl;
    }
    if(maxSubSum<subSum){
                ans.clear();
                y = A.size();
                maxSubSum = subSum;
                subSum=0;
                for(int i=x;i<y;i++){
                    ans.push_back(A[i]);
                }
    }
    return ans;
}

int main(){
    int n;
    cin>>n;
    vector<int> A(n);
    for(auto &i: A){
        cin>>i;
    }
    vector<int> ans = maxset(A);

    for(auto i: ans){
        cout<<i<<" ";
    }
    cout<<endl;

    return 0;
}