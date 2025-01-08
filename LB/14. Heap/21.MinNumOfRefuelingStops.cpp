#include<bits/stdc++.h>

using namespace std;


int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
    int stops = 0;
    int dist = 0;
    int i=0;
    int currFuel = startFuel;
    priority_queue<pair<int,int>> maxHeap;
    
    while(true){
        while(i < stations.size()){
            if(stations[i][0] <= dist+currFuel)
                maxHeap.push({stations[i][1], stations[i][0]});
            else
                break;
            i++;
        } 

        dist+=currFuel;
        currFuel = 0;
        
        if(dist >= target) break;

        if(maxHeap.empty()){
            stops = -1;
            break;
        }

        //refuel and readjust distance 
        auto&top = maxHeap.top();

        currFuel = (dist - top.second) + top.first;
        dist = top.second;
        maxHeap.pop();
        stops++;
    }
    return stops;    
}

int main(){
    int n;
    cin>>n;
    vector<vector<int>> stations(n, vector<int>(2));
    for(auto &station: stations){
        cin>>station[0]>>station[1];
    }
    int startFuel, target;
    cin>>startFuel>>target; 

    cout<<"stops: "<<minRefuelStops(target, startFuel, stations);
    return 0;
}