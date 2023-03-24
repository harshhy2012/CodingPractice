#include<bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n-i-1;j++){
            cout<<" ";
        }
        if(i==0||i==1||i==n-1){
            for(int j=0;j<i+1;j++){
            cout<<"* ";
            }
        }
        else{
            for(int j=0;j<i+1;j++){
                if(j==0||j==i){
                    cout<<"* ";
                }
                else{
                    cout<<"  ";
                }
            }
        }
        
        cout<<endl;
    }
    return 0;
}