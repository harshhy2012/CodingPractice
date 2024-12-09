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
    int lowerBound(vector<int> arr){
    if(arr[0] == 1){
      return 0;
    }
    int low = 0, high = arr.size();
    while(low<=high){
      int mid = high - (high-low)/2;
      if(arr[mid] >= 1){
        high = mid-1;
      } else{
        low = mid+1;
      }
    }
    return high;
  }


    int rowWithMax1s(vector < vector < int >> & mat) {
    int n = mat.size();
    int m = mat[0].size();

    int maxCount = 0, maxRow = -1;

    for(int i=0;i<n;i++){
      int numOnes = m-lowerBound(mat[i]);
      cout<<"Num of 1s in row "<<i+1<<" is: "<<numOnes<<endl;
      if(numOnes > maxCount){
        maxCount = numOnes;
        maxRow = i;
      }

    }
    return maxRow;
  }


int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> mat(n, vector<int> (m));
    for (auto &i : mat){
        for(auto &j: i){
            cin>>j;
        }
    }
    int ans = rowWithMax1s(mat);
    cout<<" row with max 1s: "<< ans <<endl;
    return 0;
}
