#include<bits/stdc++.h>

using namespace std;

int main(){
    int a = 5;
    int b = 2;
    cout<<"A: "<<a<<", B: "<<b<<endl;
    a = a^b;
    b = a^b;
    a = b^a;
    cout<<"A: "<<a<<", B: "<<b<<endl;
    return 0;
}