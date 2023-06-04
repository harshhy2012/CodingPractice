#include<bits/stdc++.h>

using namespace std;

void buyAndSell(vector<int>&stocks, int i, int&maxProfit, int&minPrice){
    if(i==stocks.size())
        return;
    if(stocks[i]<minPrice){
        minPrice = stocks[i];
    }
    maxProfit = max(stocks[i]-minPrice, maxProfit);
    buyAndSell(stocks,i+1, maxProfit, minPrice);
}

int main(){
    int n;
    cin>>n;
    vector<int> stocks(n);
    for(auto &stock: stocks){
        cin>>stock;
    }
    int maxProfit = INT_MIN, minPrice = INT_MAX;
    buyAndSell(stocks,0,maxProfit,minPrice);
    cout<<"MAX PROFIT: "<<maxProfit<<endl; 
    return 0;
}