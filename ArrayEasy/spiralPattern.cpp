#include<bits/stdc++.h>

using namespace std;

void printPattern(int n, int m){
    int startRow = 0, endRow = n-1, startCol = 0, endCol = m-1;
    while(startCol<=endCol && startRow<=endRow){
        for(int i=0;i<endCol;i++){
            
        }
    }  
}

int main(){
    ifstream cin("spiralPattern.txt");
    if(cin.fail())
    cout<<"Input from file failed";
    int n,m;
    cin>>n>>m;
    printPattern(n,m);
    cin.close();
    return 0;
}