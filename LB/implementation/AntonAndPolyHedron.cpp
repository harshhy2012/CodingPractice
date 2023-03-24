#include<bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin>>n;
    map<string, int> shapeMap = {
        {"Tetrahedron", 4},
        {"Cube", 6},
        {"Octahedron", 8},
        {"Dodecahedron", 12},
        {"Icosahedron", 20}
    };
    vector<string> inp(n);
    for(auto &i: inp){
        cin>>i;
    }
    int ans;
    for(int i=0;i<n;i++){
        ans+=shapeMap[inp[i]];
    }
    cout<<ans<<endl;
    return 0;
}