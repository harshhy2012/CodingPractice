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
    if(l == 0){
        segSeive[l] = segSeive[l+1] = false;
    }
    if(l == 1){
        segSeive[l] = false;
    }
        
    vector<bool> seive = seiveofEur(sqrt(r));
    vector<int> basePrimes;
    for(int i=2;i<seive.size();i++){
        if(seive[i])
            basePrimes.push_back(i);
    }

    cout<<"BASE PRIMES: ";
    for(auto prime: basePrimes){
        cout<<prime<<" ";
    }
    cout<<endl;

    for(auto primeNum: basePrimes){
        int start;
        if(l<=1){
            start=2;
        }
        else{
            start = (l/primeNum)*primeNum;
        }
        if(start<l)
            start+=primeNum;
        int j = max(start, primeNum*primeNum);
        while(j<=r){
            segSeive[j-l] = false;
            j+=primeNum;
        }
    }
    return segSeive;
}

vector<int> closestPrimes(int left, int right) {
    vector<bool> segSeive = segmentedSeive(left, right);
    int count = 0;
    for(int i=0;i<segSeive.size();i++){
        if(segSeive[i]){
            cout<<i+left<<" ";
        }
        else{
            cout<<"x ";
        }
    }
    cout<<endl;
    // if(count<=1){
    //     return {-1,-1};
    // }
    int l=-1, r=-1, prev=-1;
    for(int i=0; i<segSeive.size(); i++){
        if(!segSeive[i])
            continue;
        if(l==-1)
            l = i;
        else if(r==-1){
            r = i;
        }
        else if(i-prev < r-l){
            l=prev;
            r=i;
        }
        prev = i;
    }

    if(r==-1) 
        return {-1, -1};
    else
        return {l+left, r+left};
}

int main(){
    int left,right;
    cin>>left>>right;
    vector<int> ans = closestPrimes(left,right);
    for(auto i: ans){
        cout<<i<<" ";
    }
    cout<<endl;
    return 0;
}