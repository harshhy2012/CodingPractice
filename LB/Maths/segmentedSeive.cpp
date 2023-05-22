#include<bits/stdc++.h>

using namespace std;

vector<bool> seiveofEur(int n){
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

vector<bool> segmentedSeive(int l, int r){
    vector<bool> segSeive(r-l+1, true);
    vector<bool> seive = seiveofEur(sqrt(r));
    vector<int> basePrimes;
    if(l==0){
        return seiveofEur(r);
    }
    if(l == 1){
        segSeive[0] = false;
    }
    for(int i=2;i<seive.size();i++){
        if(seive[i])
            basePrimes.push_back(i);
    }
    cout<<"BASE PRIMES: ";
    for(auto i: basePrimes){
        cout<<i<<" ";
    }
    cout<<endl;
    for(auto primeNum: basePrimes){
        int start = (l/primeNum)*primeNum;
        if(start<l)
            start+=primeNum;
        int j = max(start, primeNum*primeNum);

        cout<<"START: "<<start<<" || PrimeNum: "<<primeNum<<" || J: "<<j<<endl;
        while(j<=r){
            segSeive[j-l] = false;
            cout<<"J-L : "<<j-l<<endl;
            j+=primeNum;
        }
    }
    return segSeive;
}

int main(){
    int l, r;
    cin>>l>>r;
    vector<bool> ans = segmentedSeive(l,r);
    for(int i=0;i<ans.size();i++){
        if(ans[i])
            cout<<i+l<<" ";
    }
    return 0;
}