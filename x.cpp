#include <bits/stdc++.h>

using namespace std;

// long double minimiseMaxDistance(vector<int> &arr, int k) {
//     int n = arr.size();
//     cout<<"CHALA\n";
//     vector<int> placed(n-1);
//     for(int i=1;i<=k;i++){
//         long double maxi = -1;
//         int maxIdx = -1;
//         for(int j=0;j<n-1;j++){
//             double diff = arr[j+1] - arr[j];
//             double sectionLen = diff/(placed[j]+1);
//             if(sectionLen > maxi){
//                 maxi = sectionLen;
//                 maxIdx = j;
//             }
//         }
//         placed[maxIdx]++;
//         cout<<"PLACED: ";
//         for(auto k: placed){
//             cout<<k<<" ";
//         }
//         cout<<endl;
//     }
//     long double ans = DBL_MIN;

//     for(int i=0;i<n-1;i++){
//         long double dist = (arr[i+1] - arr[i]);
//         long double sectionLen = dist / (placed[i]+1);
//         ans = max(sectionLen, ans);
//     }
//     // long double roundedAns = round(ans * 1000000) / 1000000;
//     // return roundedAns;
//     return ans;

// }

int numOfGasStation(vector<int>&arr, int mid){
    int n = arr.size();
    int cnt = 0;
    for(int i=1;i<n;i++){
        int numInBetween = ( arr[i] - arr[i-1] ) / mid;
        if(arr[i] - arr[i-1] == numInBetween * mid)
            numInBetween--;

        cnt+=numInBetween;
    }
    return cnt;
}

long double minimiseMaxDistance(vector<int> &arr, int k) {
    int n = arr.size(); 
    long double low = 0;
    long double high = 0;

    for(int i=0;i<n-1;i++){
        high = max(high, (long double)(arr[i+1]-arr[i]));
    }

    long double diff = 1e-6;
    while(high - low > diff){
        long double mid = (low + high) / 2.0;
        int cnt = numOfGasStation(arr, mid);
        if(cnt > k){
            low = mid;
        } else{
            high = mid;
        }
    }
    
    return high;
}


int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (auto &i : arr)
    {
        cin >> i;
    }
    int k;
    cin>>k;
    long double ans = minimiseMaxDistance(arr, k);
    cout << std::fixed << std::setprecision(6);
    std::cout << "Rounded value: " << ans << std::endl;
    return 0;
}
