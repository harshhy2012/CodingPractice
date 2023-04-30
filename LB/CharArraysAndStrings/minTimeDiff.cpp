#include<bits/stdc++.h>

using namespace std;

int minTimeDiff(vector<string> times){
    vector<int> intTimes;
    for(auto time: times){
        int hours = stoi(time.substr(0,2));
        int mins = stoi(time.substr(3,2));
        int totalMins = (hours*60)+mins;
        intTimes.push_back(totalMins);
    }
    for(auto i: intTimes){
        cout<<i<<" ";
    }
    cout<<endl;

    sort(intTimes.begin(),intTimes.end());
    

    int diff = 0, minDiff = INT_MAX;
    for(int i=0;i<times.size()-1;i++){
        diff = intTimes[i+1] - intTimes[i];
        minDiff = min(diff,minDiff);
    }
    int lastDiff = (1440+intTimes[0])-intTimes[intTimes.size()-1];
    cout<<lastDiff<<endl;
    minDiff = min(minDiff, lastDiff);
    return minDiff;
}

int main(){
    int n;
    cin>>n;
    vector<string> times(n);
    for(auto &time: times){
        cin>>time;
    }

    cout<<minTimeDiff(times)<<endl;


    return 0;
}