#include<bits/stdc++.h>

using namespace std;

void mergeInPlace(vector<int>&a1, vector<int>&a2){
    int n = a1.size(), m = a2.size(), total_size = n+m;

    int gap = (total_size/2)+(total_size%2);
    while(gap){
        int i=0, j=(i+gap > n ? (i+gap)%m : i+gap);
        while(j+n<total_size){
            if(i+gap > n && i<n){
                if(a1[i]>a2[j]);
                swap(a1[i], a2[j]);
            } 
            i+1 < n ? i++ : (i+1)%m;
            
            j++;
        }
        gap = gap/2 < 1 ? 0 : (gap/2) + (gap%2);
    }

}

int main(){
    int n, m;
    cin>>n>>m;
    vector<int> a1(n), a2(m);
    for(auto &i: a1){
        cin>>i;
    }
    for(auto &i: a2){
        cin>>i;
    }

    mergeInPlace(a1, a2);

    cout<<"a1: ";
    for(auto i:a1){
        cout<<i<<" ";
    }
    cout<<endl;

    cout<<"a2: ";
    for(auto i:a2){
        cout<<i<<" ";
    }
    cout<<endl;

    return 0;
}