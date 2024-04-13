#include<bits/stdc++.h>

using namespace std;

int minCost(int&c1, int&c2, int&c3, int&c4, vector<int>&rick, vector<int>&cab){
    int op1 = 0, op2 = 0, op3 = 0; 
    int rickC = 0, cabC = 0;
    for(auto i: rick)
        rickC += min(i*c1, c2);
    
    for(auto i: cab)
        cabC += min(i*c1, c2);
    
    op1 = rickC+cabC;
    
    op2 += min(rickC, c3);
    op2 += min(cabC, c3);
    
    op3 = c4;

    return min(op1, min(op2, op3));
}

int main(){
    int n, m;
    cin>>n>>m;

    int c1, c2, c3, c4;
    vector<int> rick(n), cab(m);
    
    cin>>c1>>c2>>c3>>c4;
    for(auto &i: rick){
        cin>>i;
    }
    for(auto &i: cab){
        cin>>i;
    }

    cout<<minCost(c1, c2, c3, c4, rick, cab);

    return 0;
}