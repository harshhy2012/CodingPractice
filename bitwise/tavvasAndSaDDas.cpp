#include<bits/stdc++.h>

using namespace std;

int numDig(int n){
    int ans = 0;
    while(n){
        ans++;
        n/=10;
    }
    return ans;
}

int luckyRank(int n){
//1. find lesser numbers with n-1 digits by GP formula
//   {2(2^(n-1)-1)/(2-1)} = 2^n-2
    int numDigs = numDig(n);
    int ans = (1<<numDigs)-2;
//2. calulate lesser number with n number of digits.
    int x = 0;
    while(n){
        int dig = n%10;
        if(dig==7)
            ans+=1<<x;
        x++;
        n/=10;
    }  

    return ans+1;
}

int main(){
    ifstream cin("tavvasAndSaDDas.txt");
    if(cin.fail())
    cout<<"Input from file failed";
    int n;
    cin>>n;
    cout<<luckyRank(n);
    cin.close();
    return 0;
}