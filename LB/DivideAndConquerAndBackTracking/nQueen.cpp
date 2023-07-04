#include<bits/stdc++.h>

using namespace std;

unordered_map<int, bool> rowCheck;
unordered_map<int, bool> leftUpperDiagCheck;
unordered_map<int, bool> leftBottomDiagCheck;


void printSolution(vector<vector<char>> board, int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<board[i][j]<<" ";
        }
        cout<<endl; 
    }
    cout<<endl;
}

bool isSafe(int row, int col, vector<vector<char>> board, int n){   
    if(rowCheck[row])
        return false;
    if(leftUpperDiagCheck[abs(col-row)])
        return false;
    if(leftBottomDiagCheck[row+col])
        return false;

    return true;
    // check if we can keep queen at [row,col]
    // int i=row, j = col;

    // // check in same row
    // while(j>=0){
    //     if(board[i][j]=='Q'){
    //         return false;
    //     }
    //     j--;
    // }   
    // // check left up diagonal
    // i=row, j=col;
    // while(i>=0 && j>=0){
    //     if(board[i][j]=='Q'){
    //         return false;
    //     }
    //     i--;
    //     j--;
    // }
    // // check left down diagonal
    // i=row, j=col;
    // while(i<n&& j>=0){
    //     if(board[i][j]=='Q'){
    //         return false;
    //     }
    //     i++;
    //     j--;
    // }

    // // no Queen found so queen can be placed
    // return true;
}

void nQueen(vector<vector<char>> board, int col, int n){
    if(col>=n){
        printSolution(board, n);
        return;
    }    
    for(int row =0;row<n;row++){
        if(isSafe(row, col, board, n)){
            board[row][col] = 'Q';
            rowCheck[row] = true;
            rowCheck[abs(col-row)] = true;
            rowCheck[row+col] = true;
            nQueen(board, col+1, n);
            board[row][col] = '-';
            rowCheck[row] = false;
            rowCheck[abs(col-row)] = false;
            rowCheck[row+col] = false;
        }
    } 
}

int main(){
    int n;
    cin>>n;
    vector<vector<char>> board(n, vector<char>(n,'-'));
    int col = 0;
    nQueen(board, col, n);
    return 0;
}