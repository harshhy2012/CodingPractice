#include<bits/stdc++.h>

using namespace std;

int main(){
    int n,m;
    cin>>n>>m;
    bool firstOdd = true;
    for(int i=0;i<n;i++){
        if(i%2==0){
            for(int j=0;j<m;j++){
                cout<<"#";
            }
            cout<<endl;
        }
        else{
            if(firstOdd){
                for(int j=0;j<m-1;j++){
                    cout<<".";
                }
                cout<<"#";
                firstOdd = false;
            }
            
            else{
                cout<<"#";
                for(int j=0;j<m-1;j++){
                    cout<<".";
                }
                firstOdd = true;
            }
            cout<<endl;
        }
    }    
    return 0;
}