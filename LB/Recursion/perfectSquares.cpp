#include<bits/stdc++.h>

using namespace std;

int numSquaresHelper(int n){
    if(n==0){
        return 1;
    }
    if(n<0){
        return 0;
    }

    int i = 1;
    
    int ans = INT_MAX;
    int end = sqrt(n);
    int minPerfectSquares=0;
    while(i<=end){
        int perfectSquare = i*i;
        minPerfectSquares = 1+numSquaresHelper(n-perfectSquare);
        ans = min(ans, minPerfectSquares);
        i++;
    }
    return ans;
}

int numSquares(int n){
    return numSquaresHelper(n)-1;
}

int main(){
    int n;
    cin>>n;
    cout<<numSquares(n)<<endl;
    return 0;
}