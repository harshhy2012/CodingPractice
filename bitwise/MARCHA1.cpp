#include<bits/stdc++.h>

using namespace std;

bool robAmount(int m, vector<int>&notes){
    int range = (1<<notes.size())-1;

    for(int i=0;i<=range;i++){
        int num = i;
        int j = 0;
        int sum=0;
        while(num){
            (num&1)?sum+=notes[j]:sum+=0;
            j++;
            num>>=1;
        }
        if(sum==m)
                return true;
    }
    return false;
}

int main(){
    ifstream cin("MARCHA1.txt");
    if(cin.fail())
    cout<<"Input from file failed";
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<int> notes(n);
        for(auto &i: notes){
            cin>>i;
        }
        if(robAmount(m, notes))
            cout<<"Yes\n";
        else
            cout<<"No\n";
    }
    cin.close();
    return 0;
}