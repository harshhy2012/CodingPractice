#include<bits/stdc++.h>

using namespace std;

int main(){
    ifstream cin("helpRamu.txt");
    if(cin.fail())
        cout<<"Input from file failed";
    int t;
    cin>>t;
    while(t--){
        int c1,c2,c3,c4;
        cin>>c1>>c2>>c3>>c4;
        int n,m;
        cin>>n>>m;
        vector<int> rick(n), cab(m);
        for(auto &i: rick){
            cin>>i;
        }
        for(auto &i: cab){
            cin>>i;
        }
        
        int cabCost, rickCost, finalCost;
        for(auto i: rick){
            rickCost+=min(i*c1, c2);
        }
        rickCost = min(rickCost, c3);
        
        for(auto i: cab){
            cabCost+=min(i*c1, c2);
        }
        cabCost = min(cabCost, c3);
        
        finalCost = min(cabCost+rickCost, c4);
        cout<<finalCost<<endl;
    }
    cin.close();
    return 0;
}