#include <bits/stdc++.h>

using namespace std;


void printSt(stack<float> st){
    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }
    cout<<endl;
}
class Car
{
public:
    int pos;  int spd;
    Car(int p, int s): pos(p), spd(s) {};
};


bool comp(Car&a, Car&b){
    return a.pos<b.pos;
}
// postition: 10 8 0 5 3
// speed: 2 4 1 1 3
// target: 12
int numOfFleets(int target, vector<int> &position, vector<int> &speed)
{
    vector<Car> cars;
    for (int i = 0; i < position.size(); i++)
    {
        Car car(position[i], speed[i]);
        cars.push_back(car);
    }
    sort(cars.begin(), cars.end(), comp);

    stack<float> st;
    for(auto car: cars){
        float time = (target-car.pos)/ ((float)car.sp);
        while(!st.empty() && time >= st.top()){
            st.pop();
        }
        st.push(time);
    }
    // printSt(st);
    return st.size();
}

int main()
{
    int n;
    cin >> n;
    vector<int> posi(n), speed(n);
    for (auto &i : posi)
    {
        cin >> i;
    }
    for (auto &j : speed)
    {
        cin >> j;
    }
    int totLen;
    cin >> totLen;
    cout << numOfFleets(totLen, posi, speed) << endl;
    return 0;
}