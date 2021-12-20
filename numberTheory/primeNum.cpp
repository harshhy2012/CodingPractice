#include<bits/stdc++.h>

using namespace std;

bool isPrime(int n){
    if(n<2 && n>=0){
        return true;
    }
    for(int i=2;i*i<=n;i++){
        if(n%i==0)
            return false;
    }
    return true;
}

int main(){
    ifstream cin("primeNum.txt");
    if(cin.fail())
    cout<<"Input from file failed";
    int n;
    cin>>n;
    if(isPrime(n))
        cout<<"Prime\n";
    else
        cout<<"Non-Prime\n";
    cin.close();
    return 0;
}