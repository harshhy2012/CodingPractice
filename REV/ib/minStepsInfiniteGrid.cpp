#include<bits/stdc++.h>

using namespace std;

int coverPoints(vector<int> &A, vector<int> &B) {

        int n = A.size();
    
    int ans = 0;
    
    for(int i=0;i<n-1;i++){
        ans+=min( abs(A[i+1]-A[i]), abs(B[i+1]-B[i]) );
    }

    return ans;

}


int main(){
    int n;
    cin>>n;
    vector<int> A(n), B(n);

    for(auto&i: A){
        cin>>i;
    }
    for(auto&i: B){
        cin>>i;
    }
    cout<<coverPoints(A, B);

    return 0;
}