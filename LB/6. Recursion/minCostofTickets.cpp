#include<bits/stdc++.h>

using namespace std;

    /*
        1 2 3 4 5 6 7 8 9 10 30 31
    */ 
    int mincostTicketsHelper(vector<int>&days, vector<int>& costs, int i){
        if(i>=days.size()){
            return 0;
        }
        int cost1 = costs[0]+mincostTicketsHelper(days, costs, i+1);
        int x = i;
        int passEndDay =days[i]+7-1;
        while(x<days.size() && days[x]<=passEndDay){
            x++;
        }
        int cost2 = costs[1]+mincostTicketsHelper(days, costs, x);
        x = i;
        passEndDay = days[i]+30-1;
        while(x<days.size() && days[x] <= passEndDay){
            x++;
        }
        int cost3 = costs[2]+mincostTicketsHelper(days, costs, x);

        return min(cost1, min(cost2, cost3));
    }   

    int mincostTickets(vector<int>& days, vector<int>& costs) {
        return mincostTicketsHelper(days, costs, 0);
    }

int main(){
    int d;
    cin>>d;
    vector<int> days(d);
    for(auto &day: days){
        cin>>day;
    }
    vector<int> costs(3);
    for(auto &cost: costs){
        cin>>cost;
    }

    cout<<mincostTickets(days, costs);

    return 0;
}