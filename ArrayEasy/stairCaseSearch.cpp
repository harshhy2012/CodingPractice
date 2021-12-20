#include<bits/stdc++.h>

using namespace std;

pair<bool, pair<int,int>> stairCaseSearch(vector<vector<int>>&arr, int R, int C, int key){
    int i=0;
    int j=C-1;
    while(i<R && j>=0){
        if(key>arr[i][j])
            i++;
        else if(key<arr[i][j]){
            j--;
        }
        else{
            return {true, {i,j}};
        }
    }
}

void spiralPrint(vector<vector<int>> arr, int R, int C){  
    int i=0;
    int j=0;
    int startCol = 0, endCol = C-1, startRow = 0, endRow = R-1;
    while(startRow<=endRow&& startCol<=endRow){
        // 1st row from top
        startRow++;
        while(j<=endCol){
            cout<<arr[i][j]<<" ";
            j++;
        }
        endCol--;
        j--;
        i++;
        //last col from right
        while(i<=endRow){
            cout<<arr[i][j]<<" ";
            i++;
        }
        i--;
        endRow--;
        j--;
        //first row from bottom
        while(j>=startCol){
            cout<<arr[i][j]<<" ";
            j--;
        }
        j++;
        startCol++;
        i--;
        //first col from left 
        while(i>=startRow){
            cout<<arr[i][j]<<" ";
            i--;
        }
        i++;
        startRow++;
        j++;
        
    }
}

void spiralPrintBetter(vector<vector<int>> arr, int R, int C){  
    int startCol = 0, endCol = C-1, startRow = 0, endRow = R-1;
    while(startRow<=endRow&& startCol<=endRow){

        for(int j = startCol;j<=endCol;j++){
            cout<<arr[startRow][j]<<" ";
        }
        startRow++;

        for(int i=startRow;i<=endRow;i++){
            cout<<arr[i][startRow]<<" ";
        }
        endCol--;
        if(endRow>startRow)
        for(int j=endCol;j>=startCol;j--){
            cout<<arr[endRow][j]<<" ";
        }
        endRow--;
        if(startCol<endCol)
        for(int i=endRow;i>=startRow;i--){
            cout<<arr[i][startCol]<<" ";
        }
        startCol++;
    }
}

int main(){
    ifstream cin("stairCaseSearch.txt");
    if(cin.fail())
    cout<<"Input from file failed";
    int R,C,key;
    cin>>R>>C;

    vector< vector<int> > arr(R, vector<int> (C));
    for(int i=0;i<R;i++){
        for(int j=0;j<C;j++){
            cin>>arr[i][j];
        }
    }
    //cin>>key;
    pair<bool, pair<int,int>> ans = stairCaseSearch(arr,R,C,key);
    spiralPrint(arr,R,C);
    cout<<endl;
    spiralPrintBetter(arr,R,C);
    cout<<endl;
    cin.close();
    return 0;
}