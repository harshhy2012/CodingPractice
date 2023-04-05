#include<bits/stdc++.h>

using namespace std;

int divideNums(int a, int b){
    if(b==-1){
        return -a;
    }
    if(b==1){
        return a;
    }
    int low = 0, high = a;
    int mid;
    int ans=0;
    while(low<=high){
        mid = low+(high-low)/2;
        if( abs(mid*low)> abs(high)){
            high = mid-1;
        }
        else{
            ans = mid;
            low = mid+1;
        }
    }
    if((a<0 && b<0) || (a>0 && b>0)){
        return ans;
    }
    else{
        return -ans; 
    }
    
}

int main(){
    int a,b;
    cin>>a>>b;
    cout<<divideNums(a,b)<<endl;
    return 0;
}