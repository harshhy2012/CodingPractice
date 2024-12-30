#include<bits/stdc++.h>

using namespace std;

bool getAllVertices(vector<vector<int>>&grid, vector<pair<int,int>>&v, pair<int, int>c, int&delta){

}


void getAllSum(vector<vector<int>>&grid, vector<pair<int, int>>&v, pair<int,int>c, int&delta){

}

vector<int> getBiggestThree(vector<vector<int>>& grid) {
    // need to go through all the cells in the grid
    // make rhombus for every cell.
    // calc max area for rhombus and add to maxHeap
    // copy max heap and reverse array.
    int n = grid.size();
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            int delta = 0;
            int x = i, y = j;
            
            
        }
    }
}

int main(){
    int n;
    cin>>n;

    vector<vector<int>> rhombus(n, vector<int>(n));

    for(auto &rhomRow: rhombus){
        for(auto &rhomVal: rhomRow){
            cin>>rhomVal;
        }
    }

    vector<int> ans = getBiggestThree(rhombus);

    cout<<"ANS: ";
    for(auto i: ans){
        cout<<i<<" ";
    }
    cout<<endl;


    return 0;
}