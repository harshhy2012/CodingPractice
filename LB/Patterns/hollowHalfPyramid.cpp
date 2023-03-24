#include<bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        if(i<2 || i==n-1){
            for(int j=1;j<i+2;j++){
                cout<<j<<" ";
            }
        }
        else{
            for(int j=1;j<i+2;j++){
                if(j==1||j==i+1)
                   cout<<j<<" ";
                else
                    cout<<"  ";
            }
        }
        cout<<endl;
    }
    return 0;
}