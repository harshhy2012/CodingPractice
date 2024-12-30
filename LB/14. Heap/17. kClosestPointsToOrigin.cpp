#include<bits/stdc++.h>

using namespace std;



class coordinate{
    public: 
    int x, y;
    coordinate(int x, int y){
        this->x = x;
        this->y = y;
    }
};

class compare{
    public:
        bool operator()(coordinate a, coordinate b){
            int distA = (a.x*a.x) + (a.y*a.y);
            int distB = (b.x*b.x) + (b.y*b.y);
            return distA < distB;
        }
};

int calcDist(coordinate&c){
    return (c.x*c.x) + (c.y*c.y);
}

vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
    vector<vector<int>> ans;
    priority_queue<coordinate, vector<coordinate>, compare> maxHeap;
    int i = 0;
    for(;i<k;i++){
        coordinate newC = coordinate(points[i][0], points[i][1]);
        maxHeap.push(newC);
    }
    for(;i<points.size();i++){
        coordinate top = maxHeap.top();
         maxHeap.pop();
        int topDist = calcDist(top);
        coordinate currPoint(points[i][0], points[i][1]);
        int currDist = calcDist(currPoint);
        if(currDist < topDist){
            maxHeap.push(currPoint);
        }
    }

    while(!maxHeap.empty()){
        coordinate top = maxHeap.top();
        ans.push_back({top.x, top.y});
        maxHeap.pop();
    }

   // reverse(ans.begin(), ans.end());

    return ans;
}

int main(){
    int n;
    cin>>n;
    int k;
    cin>>k;
    vector<vector<int>> points(n, vector<int>(2));
    for(auto &i: points){
        for(auto &j: i){
            cin>>j;
        }
    }

    vector<vector<int>> ans = kClosest(points, k);
    cout<<"FINANS: \n";
    for(auto pt: ans){
        cout<<"("<<pt[0]<<", "<<pt[1]<<")\n";
    }

    return 0;
}