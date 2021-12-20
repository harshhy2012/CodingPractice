#include<bits/stdc++.h>

using namespace std;

int getIthBit(int n, int i){
    if(n&(1<<i))
        return 1;
    else 
        return 0; 
}

void setIthBit(int &n, int i){
    n = n|(1<<i);
}
void eraseIthBit(int &n, int i){
    int mask = ~(1<<i);
    n = n&mask;
}

int main(){
    ifstream cin("ithBit.txt");
    if(cin.fail())
    cout<<"Input from file failed";
    int n,i;
    cin>>n>>i;
    int j=0;
    cout<<getIthBit(n,i)<<endl;
    setIthBit(n,i);
    cout<<n<<endl;
    eraseIthBit(n,i);
    cout<<n<<endl;
    cin.close();
    return 0;
}