#include<bits/stdc++.h>

using namespace std;

float squareRoot(int n, int p){
    if(n==1||n==0)
        return 0;
    
    int beg=  0, end = n;
    float ans = 0;
    while(!(beg>end)){
        int mid = (beg+end)/2; 
        if(mid*mid == n){
            ans = mid;
            break;
        }
        else if(mid*mid<n){
            ans = mid;
            beg = mid+1;
        }
        else{
            end = mid-1;
        }
    }
    float dig = 0.1;
    for(int i=0;i<p;i++){
        while(ans*ans<=n){
            ans+=dig;
        }
        ans-=dig;
        dig/=10;
    }

    return ans;
}       


int main(){
    ifstream cin("squareRoot.txt");
    if(cin.fail())
    cout<<"Input from file failed";
    int num, p;
    cin>>num>>p;
    cout<<"SQUARE ROOT INT: "<<squareRoot(num,p);
    cin.close();
    return 0;
}