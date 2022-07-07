#include<bits/stdc++.h>

using namespace std;

vector<bool> seive(1001, false);

bool islucky(int n){
    while(n){
        int dig = n%10;
        if(dig!=4 && dig!=7)
            return false;
        n/=10;
    }
    return true;
}

bool almostLucky(int n){
    for(int i=4;i<seive.size();i++){
        if(seive[i])
            if(n%i==0)
                return true;
    }
    return false;
}

int main(){
    int n;
    cin>>n;
    for(int i=4;i<1001;i++){
        seive[i]=islucky(i);
    }

    if(seive[n] || almostLucky(n))
        cout<<"YES\n";
    else   
        cout<<"NO\n";

    return 0;
}