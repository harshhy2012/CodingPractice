#include<bits/stdc++.h>

using namespace std;

vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
    vector<vector<int>> finAns;
    vector<int> step;

    int i = rStart, j = cStart;
    while(){
        // cannot think of any condition where we stop this loop
        //will get back to it
    }

}

int main(){
    int rows, cols;
    cin>>rows>>cols;
    int rStart, cStart;
    cin>>rStart>>cStart;
    vector<vector<int>> ans = spiralMatrixIII(row, cols, rStart, cStart);

    cout<<"[";
    for(auto i: ans){
        cout<<"[";
        for(auto j: i){
            cout<<j<<", ";
        }
        cout<<"], ";
    }    
    cout<<"]\n";

    return 0;
}