#include<bits/stdc++.h>

using namespace std;

void sortColors(vector<int> &colors){
    int low, mid, high = colors.size()-1;
    low = mid = 0;
    while(mid<=high){
        if(colors[mid]==0){
            swap(colors[mid], colors[low]);
                low++;
                mid++;
            }
            
        else if(colors[mid] == 1){
            mid++;
        }
        else{
            swap(colors[high], colors[mid]);
            high--;
        }
    }
}

int main(){
            int n;
        cin>>n;
        vector<int> colors(n);
        for(auto &i: colors){
            cin>>i;
        }
    sortColors(colors);

    for(auto i: colors){
        cout<<i<<" ";
    }

       
    return 0;
}