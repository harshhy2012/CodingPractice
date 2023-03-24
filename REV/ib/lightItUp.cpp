#include<bits/stdc++.h>

using namespace std;

void setter(vector<int> &A, int B, int i){
    for(int x=i,y=i;x>i-B,y<i+B;x--,y++){
        A[x] = 1;
        A[y] = 1;
        if(x<=0){
            x=1;
        }
        if(y>=A.size()-1){
            y = A.size()-1;
        }
    }
}

bool checkLeftZeros(vector<int> &A, int B, int i){
    for(int x=i;x>i-B;x--){
        if(A[x]==1){
            return false;
        }
    }
}

int solve(vector<int> &A, int B) {
    bool allOne = true;
    for(int i=0;i<A.size();i++){
        if(A[i]!=1)
            allOne = false; 
    }
    if(allOne)
        return 1;
    int ans=0;
    for(int i=0;i<A.size();i++){
        if(A[i]==1){
                setter(A,i,B);
                i+=B-1;
                ans++;
        }
    }
    for(int i=0;i<A.size();i++){
        if(A[i]!=1){
            return -1;
        }
    }
    return ans;
}


int main(){
    int n;
    cin>>n;
    vector<int> A(n);
    int B;
    for(auto &i: A){
        cin>>i;
    }

    cin>>B;

    cout<<solve(A,B)<<endl;

    return 0;
}