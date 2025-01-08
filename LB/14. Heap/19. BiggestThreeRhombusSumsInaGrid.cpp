#include<bits/stdc++.h>

using namespace std;

bool checkBounds(vector<vector<int>>&grid, vector<pair<int,int>>&v){
    int n = grid.size();
    int m = grid[0].size();

    for(auto pt: v){
        if(pt.first < 0 || pt.first >= n || pt.second <0 || pt.second >= m){
            return false;
        }
    }
    return true;
}

bool getAllVertices(vector<vector<int>>&grid, vector<pair<int,int>>&v, pair<int, int>c, int&delta){
    pair<int, int> A(c.first-delta, c.second);
    pair<int, int> B(c.first, c.second+delta);
    pair<int, int> C(c.first-delta+delta, c.second);
    pair<int, int> D(c.first-delta, c.second-delta);
    v[0] = A;
    v[1] = B;
    v[2] = C;
    v[3] = D;

    if(checkBounds(grid, v)){
        return true;
    }
    return false;
}


void getAllSum(vector<vector<int>>&grid, int&x, int&y, priority_queue<int>&maxHeap){
    maxHeap.push(grid[x][y]);
    int delta = 1;
    vector<pair<int, int>> v(4);
    int area = 0, maxArea = 0;
    vector<int> ans;
    while(getAllVertices(grid,v ,{x, y}, delta)){
        pair<int, int>&A = v[0];
        pair<int, int>&B = v[1];
        pair<int, int>&C = v[2];
        pair<int, int>&D = v[3];

        area = grid[A.first][A.second] + grid[B.first][B.second] + grid[C.first][C.second] + grid[D.first][D.second];

        for(int i=1;i<(B.first-A.first);i++){
            area += grid[A.first+i][A.second-i];
        }
        for(int i=1;i<(C.first-B.first);i++){
            area += grid[B.first+i][B.first+i];
        }
        for(int i=1;i<(D.second-C.second);i++){
            area += grid[C.first-i][C.second+i];
        }
        for(int i=1;i<(D.second-A.second);i++){
            area += grid[D.first-i][D.second-i];
        }
        maxHeap.push(area);
    }
}

vector<int> getBiggestThree(vector<vector<int>>& grid) {
    // need to go through all the cells in the grid
    // make rhombus for every cell.
    // calc max area for rhombus and add to maxHeap
    // copy max heap and reverse array.
    priority_queue<int> maxHeap;
    int n = grid.size();
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            getAllSum(grid, i,j, maxHeap);    
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