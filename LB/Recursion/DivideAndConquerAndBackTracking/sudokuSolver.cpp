#include<bits/stdc++.h>

using namespace std;

bool isSafe(vector<vector<char>>&sudoku, int x, int y, int n, char num){
    // row check
    for(int i=0; i<n; i++) {
            //row check
            if(sudoku[x][i] == num)
                return false;
            
            //col check
            if(sudoku[i][y] == num) 
                return false;

            //3*3 box check
            if(sudoku[3*(x/3)+(i/3)][3*(y/3)+(i%3)] == num) 
                return false;
        }
    // inner box check
     //3*3 box check
    // int divX = x/3;
    // int divY = y/3;
    // int boxXstart ,boxXend, boxYstart, boxYend;
    
    // if(divX == 0){
    //     boxXstart = 0, boxXend = 2;
    // } else if(divX == 1){
    //     boxXstart = 3, boxXend = 5;
    // } else{
    //     boxXstart = 6, boxXend = 8;
    // }

    // if(divY == 0){
    //     boxYstart = 0, boxYend = 2;
    // } else if(divX == 1){
    //     boxYstart = 3, boxYend = 5;
    // } else{
    //     boxYstart = 6, boxYend = 8;
    // }
    // for(int i=boxXstart;i<=boxXend;i++){
    //     for(int j=boxYstart;j<=boxYend;j++){
    //         if(i==x && j==y) continue;
    //         if(sudoku[i][j] == num)
    //             return false;
    //     }
    // }

    return true;
}   

bool sudokuSolver(vector<vector<char>>&sudoku, int n){

    for(int x = 0;x<n;x++){
        for(int y = 0;y<n;y++){
            if(sudoku[x][y] == '.'){
                for(char num = '1';num<='9';num++){
                    if(isSafe(sudoku, x, y, n, num)){
                        sudoku[x][y] = num;
                        bool upcomingSol = sudokuSolver (sudoku, n);
                        if(upcomingSol){
                            return true;
                        }
                        else{
                            sudoku[x][y] = '.';   
                            
                        }
                    }             
                }
                return false;
            }    
        }
    }
    return true;
}

void printSudoku(vector<vector<char>>&sudoku){
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            cout<<sudoku[i][j]<<" ";
        }
        cout<<endl;
    }
}

int main(){
    vector<vector<char>> sudoku{
                                {'4','5','.','.','.','.','.','.','.'},
                                {'.','.','2','.','7','.','6','3','.'},
                                {'.','.','.','.','.','.','.','2','8'},
                                {'.','.','.','9','5','.','.','.','.'},
                                {'.','8','6','.','.','.','2','.','.'},
                                {'.','2','.','6','.','.','7','5','.'},
                                {'.','.','.','.','.','.','4','7','6'},
                                {'.','7','.','.','4','5','.','.','.'},
                                {'.','.','8','.','.','9','.','.','.'},
                              };
    sudokuSolver(sudoku, 9);
    printSudoku(sudoku);

    return 0;
}