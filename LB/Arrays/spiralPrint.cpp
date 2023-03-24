#include<bits/stdc++.h>

using namespace std;

void spiralPrint(vector<vector<int>> arr){

    int n = arr.size();
    int m = arr[0].size();
    int rowStart = 0, colStart = 0, rowEnd = n-1, colEnd = m-1;

    while(rowStart<=rowEnd && colStart<=colEnd){
        if(rowStart<=rowEnd && colStart<=colEnd){
            for(int i=colStart;i<=colEnd;i++){
                cout<<arr[rowStart][i]<<" ";
            }
            rowStart++;
        }
        if(rowStart<=rowEnd && colStart<=colEnd){
            for(int i=rowStart;i<=rowEnd;i++){
                cout<<arr[i][colEnd]<<" ";
            }
            colEnd--;
        }
        if(rowStart<=rowEnd && colStart<=colEnd){
            for(int i=colEnd;i>=colStart;i--){
                cout<<arr[rowEnd][i]<<" ";
            }
            rowEnd--;            
        }

        if(rowStart<=rowEnd && colStart<=colEnd){
            for(int i=rowEnd;i>=rowStart;i--){
                cout<<arr[i][colStart]<<" ";
            }
            colStart++;
        }
    }
}

int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> arr(n, vector<int> (m));
    for(auto &i: arr){
        for(auto &j: i){
            cin>>j;
        }
    }

    spiralPrint(arr);

    return 0;
}