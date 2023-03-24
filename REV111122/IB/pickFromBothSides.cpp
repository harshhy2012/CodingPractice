#include<bits/stdc++.h>

using namespace std;


int solve(vector<int> &A, int B) {
    int n = A.size();
    int ans=0, maxAns=INT_MIN;
    for(int i=0;i<B;i++){
        ans+=A[i];
    }
    maxAns = max(ans, maxAns);
    int i= B-1, j = n-1;
    while(i>=0 && j>=n-B){
        ans-=A[i];
        ans+=A[j];
        i--;j--;
        maxAns = max(ans, maxAns);
    }
    return maxAns;
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
    cout<<solve(A, B)<<endl;

    return 0;
}