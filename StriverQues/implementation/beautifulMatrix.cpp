#include<bits/stdc++.h>

using namespace std;

int main(){
    vector<vector<int>> matrix(5, vector<int> (5));
    int x,y;
    for(int i=0;i<5;i++){
        for(int j = 0;j<5;j++){
            cin>>matrix[i][j];
            if(matrix[i][j] == 1){
                x = i; y = j;
            }
        }
    }

    cout<<abs(2-x)+abs(2-y)<<endl;
    return 0;
}