#include<bits/stdc++.h>

using namespace std;

int main(){
    // ifstream cin("beautifulMatrix.txt");
    // if(cin.fail())
    
    // cout<<"Input from file failed";
    int n,x,y;
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            cin>>n;
            if(n==1){
                x = i;
                y = j;
            }
        }
    }
    // cout<<x<<" "<<y<<endl;
    int ans = abs(x-2)+abs(y-2);
    cout<<ans<<endl;
    // cin.close();
    return 0;
}