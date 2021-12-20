#include<bits/stdc++.h>

using namespace std;

vector<bool> seiveGen(){
    vector<bool> seive(1000000,true);
    seive[0] = seive[1] = false;
    for(int i=3;i<seive.size();i+=2){
        if(seive[i]){
            for(int j=i*i;j<seive.size();j+=(2*i)){
                seive[j] = false;
            }
        }
    }
    for(int i=4;i<seive.size();i+=2){
        seive[i] = false;
    }
     return seive;
}

int main(){
    ifstream cin("seiveOfEurasthanos.txt");
    if(cin.fail())
    cout<<"Input from file failed";
    vector<bool> seive = seiveGen();
    for(int i=0;i<100;i++){
        if(seive[i])
            cout<<i<<" ";
    }
    cin.close();
    return 0;
}