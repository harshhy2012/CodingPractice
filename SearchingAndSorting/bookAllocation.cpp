#include<bits/stdc++.h>
#define ll long long int

using namespace std;

bool validComb(ll students, vector<ll>books, ll ans){
    ll pageSum = 0;
    for(int i=0;i<books.size();i++){
        if(pageSum+books[i]>ans){
            pageSum = books[i];
            students--;
            if(students<=0){
                return false;
            }
        }
        else{
            pageSum += books[i];
        }
    }
    return true;
}

ll maxPages(vector<ll> &books, ll students){
    ll minn = books[0], maxx = accumulate(books.begin(), books.end(), 0);
    ll finAns=0;
    while(minn<=maxx){
        int mid = (minn+maxx)/2; 
        int sum = 0;
        if(validComb(students, books, mid)){
            finAns = mid;
            maxx = mid-1;
        }
        else{
            minn = mid+1;
        }
    }
    return finAns;
}

int main(){
    ifstream cin("bookAllocation.txt");
    if(cin.fail())
    cout<<"Input from file failed";
    ll n, students;
    cin>>n>>students;
    vector<ll> books(n);
    for(auto &i: books){
        cin>>i;
    }
    cout<<maxPages(books, students)<<endl;
    cin.close();
    return 0;
}