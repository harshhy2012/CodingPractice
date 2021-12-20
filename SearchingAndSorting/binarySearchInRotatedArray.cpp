#include<bits/stdc++.h>

using namespace std;

pair<bool, int> BSearchRotated(vector<int>&arr, int key){
    int beg = 0, end = arr.size()-1;
    while(beg<=end){
        cout<<beg<<" "<<end<<endl;
        int mid = (beg+end)/2;
        
        if(arr[mid] == key){
            return {true, mid};
        }

        // left part
        else if(arr[beg] <= arr[mid]){
            if(arr[beg] <= key && key <= arr[mid])
                end = mid-1;

            else
                beg = mid+1;           
             
        }
        //right part
        else{
            if(arr[mid] <= key && key<=arr[end])
                beg = mid+1; 

            else
                end = mid-1;    
        }
        
    }
    return {false,-1};
}

int bSearchRotatedRec(vector<int>&arr, int s, int e, int key){ 
    if(s>e){
        return -1;
    }

    int mid = (s+e)/2;

    if(arr[mid] == key)
        return mid;
 
    else if(arr[s] <= arr[mid]){
        if(arr[s] <= key && key <= arr[mid])
            return bSearchRotatedRec(arr, s, mid-1, key);
        else
            return bSearchRotatedRec(arr, mid+1, e, key);
    }
    if(arr[mid] <= key && key<=arr[e]){
        return bSearchRotatedRec(arr, s, mid-1, key);
    }
    return bSearchRotatedRec(arr, mid+1, e, key);
}

int main(){
    ifstream cin("binarySearchInRotatedArray.txt");
    if(cin.fail())
    cout<<"Input from file failed";
    int n,key;
    cin>>n;
    vector<int> arr(n);
    for(auto &i: arr){
        cin>>i;
    }
    cin>>key;
    pair <bool, int> ans = BSearchRotated(arr,key); 
    int ans2 = bSearchRotatedRec(arr, 0, 6, key);
    if(ans.first)
        cout<<"Found at "<<ans.second<<" index\n";
    else
        cout<<"NOT FOUND\n";
    cin.close();

    if(ans2)
        cout<<"Found at "<<ans.second<<" index\n";
    else
        cout<<"NOT FOUND\n";
    cin.close();
    return 0;
}