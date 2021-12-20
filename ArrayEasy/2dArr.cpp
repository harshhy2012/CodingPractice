#include<bits/stdc++.h>

using namespace std;

void readMatrix(vector<vector<int>> &arr, int R, int C){
    for(int i=0;i<R;i++){
        for(int j=0;j<C;j++){
            cin>>arr[i][j];
        }
    }
}

void printMatrix(vector<vector<int>> &arr, int R, int C){
    for(int i=0;i<R;i++){
        for(int j=0;j<C;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
}

void wavePrint(vector<vector<int>> &arr, int R, int C){
    for(int i=0;i<C;i++){
        if(i%2==0){
            for(int j=0;j<R ;j++){
                cout<<arr[j][i]<<" ";
            }
        }
        else{
            for(int j=C-1;j>=0;j--){
                cout<<arr[j][i]<<" ";
            }
        }
    }
}

void spiralPrint(vector<vector<int>> &arr, int R, int C){
    
}

int main(){

    vector< vector<int> > arr(10, vector<int> (10));
    int R,C;
    cin>>R>>C;
    readMatrix(arr, R, C);
    printMatrix(arr, R, C);
    wavePrint(arr, R, C);
    return 0;
}