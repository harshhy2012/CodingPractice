#include<bits/stdc++.h>

using namespace std;

bool isSafe(vector<vector<int>>&maze, int i, int j, int&row, int&col, vector<vector<bool>> visited){
    if(i>=0 && i<row && j>=0 && j<col && (maze[i][j]==1) && !visited[i][j]){
        return true;
    }
    return false;
}

void solveMaze(vector<vector<int>> &maze, int i, int j, int&row, int&col, vector<vector<bool>> visited, vector<string>&ans, string output){
    if(i==row-1 && j==col-1){
        ans.push_back(output);
        return;
    }
    if(isSafe(maze, i+1, j, row, col, visited)){
        visited[i+1][j] = true;
        solveMaze(maze, i+1,j, row, col, visited, ans, output+'U');
        visited[i+1][j] = false;
    }
    if(isSafe(maze, i, j+1, row, col, visited)){
        visited[i][j+1] = true;
        solveMaze(maze, i,j+1, row, col, visited, ans, output+'R');
        visited[i][j+1] = false;
    }
    if(isSafe(maze, i-1, j, row, col, visited)){
        visited[i-1][j] = true;
        solveMaze(maze, i-1,j, row, col, visited, ans, output+'D');
        visited[i-1][j] = false;
    }
    if(isSafe(maze, i, j-1, row, col, visited)){
        visited[i][j-1] = true;
        solveMaze(maze, i,j-1, row, col, visited, ans, output+'L');
        visited[i][j-1] = false;
    }
}

int main(){
    vector<vector<int>> maze = {
                                {1,0,0,1,1,0},
                                {1,1,1,1,1,0},
                                {0,0,1,1,0,0},
                                {0,1,1,1,0,0},
                                {0,1,1,1,1,1}
    };
    vector<vector<bool>> visited = {
                                {true, false, false, false, false, false},
                                {false, false, false, false, false, false},
                                {false, false, false, false, false, false},
                                {false, false, false, false, false, false},
                                {false, false, false, false, false, false}   
    };

    int row = maze.size(), col = maze[0].size();

    string output = "";
    vector<string> allAns;

    solveMaze(maze,0,0, row, col, visited, allAns, output);

    for(auto i: allAns){
        cout<<i<<endl;
    }

    return 0;
}