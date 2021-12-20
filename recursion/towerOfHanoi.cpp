#include<bits/stdc++.h>

using namespace std;

/*
   
    A           B           C
    |           |           |
    |           |           |
    |           |           |
    |           |           |
    _      X    |           |
   ___     Y    |           |
  _____    Z    |           |

move all disks from A to C with help of B

1. bigger tile cannot be placed on smaller tile
2. pick one disk at a time

x to C
y to B
x to B
z to C
x to A
y to C
x to C

*/

/*

dryrun for n = 2;

toh(A,B,C, 2);
    toh(A,C,B,1);
        return;
    move disk 1 from A to B;
    toh(B,C,A,0)
        return;
    
    toh(B,C,A,2);
        toh(B,A,C,1);
            return;
        move disk  


*/

void towerOfHanoi(char src, char hlp, char dst, int n){
    //Base Case
    if(n==0)
        return;
    //Rec case
    towerOfHanoi(src, dst, hlp, n-1);  
    cout<<"Move disk "<<n<<" from "<<src<<" to "<<dst<<endl;
    towerOfHanoi(hlp, dst, src, n-1);
}

int main(){
    ifstream cin("towerOfHanoi.txt");
    if(cin.fail())
        cout<<"Input from file failed";
    
    int n;
    cin>>n;
    towerOfHanoi('A', 'B', 'C', n);
    cin.close();
    return 0;
}