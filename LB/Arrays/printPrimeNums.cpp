#include<bits/stdc++.h>

using namespace std;

vector<bool> createSeive(){
    vector<bool> seive(1000001, true);
    seive[0]  = seive[1] = false;
    seive[2] = true;
    for(int i=4;i<1000001;i+=2){
        seive[i] = false;
    }
    for(int i=3;i<1000001; i++){
        if(seive[i]==true){
            for(int j=i+i;j<1000001;j+=i){
                seive[j] = false;
            }
        }
    }
    return seive;
}

int main(){
    int n;
    cin>>n;
    vector<bool> ans = createSeive();
    
    for(int i=0;i<n;i++){
        if(ans[i]){
            cout<<i<<" ";
        }
    }
    cout<<endl;

    return 0;
}