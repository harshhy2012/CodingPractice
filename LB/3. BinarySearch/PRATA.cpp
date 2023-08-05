 #include<bits/stdc++.h>
 
 using namespace std;
 
int eCal(vector<int> cookRank, int p){
    int maxTime=0, worstCook = cookRank[cookRank.size()-1];
    for(int i=1;i<=p;i++){
        maxTime+=(i*worstCook);
    }
    return maxTime;
}

bool isPossible(vector<int> cookRank, int p, int timeTaken){
    int time=0, finalTime = 0;

    int n = cookRank.size();
    int c=1;
    for(int i=0;i<n-1;i++){
        int prataNo=1;
        int factor = 1;
        while(factor<cookRank[i+1]){
            time+=(cookRank[i]*factor);
            factor++;
            c++;
        }
    }
}

int orderReadyIn(vector<int> cookRank, int p){
    sort(cookRank.begin(), cookRank.end());
    int s = 0, e = eCal(cookRank, p);

    int mid;
    int ans = 0;
    while(s<=e){
        mid = s+(e-s)/2;
        if(isPossible(cookRank, p, mid)){
            ans = mid;
            e = mid-1;
        }
        else{
            s = mid+1;
        }
    }
    return ans;
}

 int main(){
    int t;
    cin>>t;
    while(t--){
        int p;
        cin>>p;
        int l;
        cin>>l;
        vector<int> cookRank(l);
        for(auto &rank: cookRank){
            cin>>rank;
        }

    }
    return 0;
 }