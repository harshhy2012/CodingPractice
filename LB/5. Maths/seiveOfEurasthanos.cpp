#include<bits/stdc++.h>

using namespace std;

vector<bool> seiveOfEur(int n){
    vector<bool> seive(n+1, true);
    seive[0] = seive[1] = false;
    for(int i=2;i*i<=n;i++)
        if(seive[i])
            for(int j=i*i;j<=n;j+=(2*i))
                seive[j] = false;
                
    for(int i=4;i<=n;i+=2)
        seive[i] = false;
    
    return seive;
}

int main(){
    int n;
    cin>>n;
    vector<bool> seive = seiveOfEur(n);

    for(int i=0;i<=n;i++){
        if(seive[i])
            cout<<i<<" ";
    }
    cout<<endl;

    return 0;
}