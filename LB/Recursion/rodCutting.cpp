#include<bits/stdc++.h>

using namespace std;

int rodCutting(int rod, int& x, int& y, int& z){
    if(rod==0){
        return 0;
    }
    if(rod<0){
        return INT_MIN;
    }
    int maxi = INT_MIN;
    int ans1 = rodCutting(rod-x, x,y,z)+1;
    int ans2 = rodCutting(rod-y, x,y,z)+1;    
    int ans3 = rodCutting(rod-z, x,y,z)+1;

    maxi = max(ans1, max(ans2, ans3));
    return maxi;

}

int main(){
    int rod;
    cin>>rod;
    int x,y,z;
    cin>>x>>y>>z;
    int ans = rodCutting(rod,x,y,z);
    if(ans<0)
        cout<<-1;
    else
        cout<<rodCutting(rod, x, y, z);
    return 0;
}