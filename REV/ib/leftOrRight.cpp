#include<bits/stdc++.h>

using namespace std;

int solve(vector<int> &A, int B){
    int sum = 0;
    for(int i=0;i<B;i++){
        sum+=A[i];
    }
    int i = B-1;
    int j = A.size()-B-1;
    while(B>0){
        if(sum-A[i]+A[j]>sum){
            sum = sum-A[i]+A[j];
        }    
            i--;
            j++;
            B--;
    }
    return sum;
}

int main(){
    int n;
    cin>>n;
    vector<int> A(n);
    for(auto &i: A){
        cin>>i;
    }
    int B;
    cin>>B;
    int ans = solve(A, B);
    cout<<ans<<endl;
    return 0;
}

