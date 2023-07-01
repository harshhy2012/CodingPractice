#include<bits/stdc++.h>

using namespace std;

bool isSafe(int i, int j, int row, int col, vector<vector<int>> maze, vector<vector<bool>>&visited){
    if(((i>=0 && i<row) && (j>=0 && j<col)) && (maze[i][j] == 1) && (!visited[i][j])){
        return true;
    }
    else
        return false;
}

void solveMaze(vector<vector<int>> &maze, int row, int col, int i, int j, vector<vector<bool>>&visited, vector<string>&path, string output){
    // base
    if(i == row-1 && j == col-1){
        path.push_back(output);
        return;
    }
    // Down
    if(isSafe(i+1, j, row, col, maze, visited)){
        visited[i+1][j] = true;
        solveMaze(maze, row, col, i+1,j,visited, path, output+'D');
        visited[i+1][j] = false; 
    }
    // left
    if(isSafe(i, j-1, row, col, maze, visited)){
        visited[i][j-1] = true;
        solveMaze(maze, row, col, i,j-1,visited, path, output+'L');
        visited[i][j-1] = false; 
    }
    // up
    if(isSafe(i-1, j, row, col, maze, visited)){
        visited[i-1][j] = true;
        solveMaze(maze, row, col, i-1,j,visited, path, output+'U');
        visited[i-1][j] = false; 
    }
    // right
    if(isSafe(i, j+1, row, col, maze, visited)){
        visited[i][j+1] = true;
        solveMaze(maze, row, col, i,j+1,visited, path, output+'R');
        visited[i][j+1] = false; 
    }
}

int main(){
    vector<vector<int>> maze = {
                                {1,0,0,0},
                                {1,1,0,0},
                                {1,1,1,0},
                                {1,1,1,1}
    };
    
    int row = maze.size();
    int col = maze[0].size();

    vector<vector<bool>> visited(row, vector<bool> (col, false));

    visited[0][0] = true;
    vector<string> path;
    string output = "";

    solveMaze(maze, row, col, 0, 0, visited, path, output);

    for(auto i: path){
        cout<<i<<endl;
    }
    cout<<endl;
    return 0;
} 