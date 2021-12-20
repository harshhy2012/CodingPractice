#include<bits/stdc++.h>

using namespace std;

string numMap[10] = {"zero", "one", "two", "three","four", "five", "six", "seven", "eight", "nine"};

void numToStr(int n){
    if(n==0)  
        return;
    int dig = n%10; 
    numToStr(n/10); 
    cout<<numMap[dig]<<" ";
} 

int main(){
    ifstream cin("2048.txt");
    if(cin.fail())
        cout<<"Input from file failed";
    int n;
    cin>>n;
    numToStr(n);
    cin.close();
    return 0;
}