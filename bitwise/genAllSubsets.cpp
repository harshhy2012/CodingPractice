#include<bits/stdc++.h>

using namespace std;

int main(){
    ifstream cin("genAllSubsets.txt");

    if(cin.fail())
        cout<<"Input from file failed";
    
    string s;
    cin>>s;
    int range = (1<<s.size())-1;
    for(int i=0;i<=range;i++){
        int x = i;
         int j = 0;
        while(x){
            (x&1)?cout<<s[j]:cout<<"";
            j++;
            x=x>>1;
        }
        cout<<endl;
    }
    cin.close();
    return 0;
}