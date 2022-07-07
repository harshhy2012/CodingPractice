#include<bits/stdc++.h>

using namespace std;

int solve(vector<int> &A, int B) {
    int sum=0;
    int maxSum=0;
    for(int i=0;i<B;i++){
        sum+=A[i];
        int f=B-1, r=A.size()-1;
        maxSum=sum;
        while(f>=0&&r>=0){
            sum+=A[r--];
            sum-=A[f--];
            maxSum=max(sum,maxSum);
        }
    }
    return maxSum;
}

int main(){
    vector<int> x = { -533, -666, -500, 169, 724, 478, 358, -38, -536, 705, -855, 281, -173, 961, -509, -5, 942, -173, 436, -609, -396, 902, -847, -708, -618, 421, -284, 718, 895, 447, 726, -229, 538, 869, 912, 667, -701, 35, 894, -297, 811, 322, -667, 673, -336, 141, 711, -747, -132, 547, 644, -338, -243, -963, -141, -277, 741, 529, -222, -684, 35};
    int B=48;
    cout<<solve(x, B)<<endl;
    return 0;
}