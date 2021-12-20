#include<bits/stdc++.h>

using namespace std;

vector<int> seiveArr(1001);

bool isLucky(int n){
    if(n<4)
        return false;
    while(n){
        int dig = n%10;
        if(dig != 4 && dig != 7)
            return false;
        n=n/10;
    }
    return true;
}

void almostLuckySeive(){
    for(int i=0;i<500;i++){
        int mul = 2;
        if(seiveArr[i]==1)
            while(mul*i<1001){
                seiveArr[mul*i] = 2;
                mul++;
            }
    }
}

void seive(){
    for(int i=0;i<1001;i++){
        if(isLucky(i))
            seiveArr[i] = 1;
    }
}

int main(){
    // ifstream cin("luckyDivision.txt");
    // if(cin.fail())
    // cout<<"Input from file failed";
    seiveArr.clear();
    seive();
    almostLuckySeive();
    int n;
    cin>>n;
    if(seiveArr[n]==1 || seiveArr[n]==2)
        cout<<"YES"<<endl;
    else
        cout<<"NO"<<endl;
    // cin.close();
    return 0;
}