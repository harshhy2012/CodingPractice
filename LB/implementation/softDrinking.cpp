#include<bits/stdc++.h>

using namespace std;

int main(){
    int n, k, l, c, d, p, nl, pl;
    cin>>n>>k>>l>>c>>d>>p>>nl>>pl;
    int totalLimeSlices = c*d, totalSoftDrink=k*l;
    int ans = 0;
    ans = min(totalLimeSlices, min(totalSoftDrink/nl, p/pl))/n;
    cout<<ans<<endl;
    return 0;
}