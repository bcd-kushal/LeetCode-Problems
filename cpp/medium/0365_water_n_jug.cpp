#include <bits/stdc++.h>
using namespace std;

int gcd(int &a, int &b) {
    while(b!=0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    
    return a;
}

bool canMeasureWater(int x, int y, int target) {
    if(x==target || y==target || x+y==target)   return true;
    if(x+y < target)                            return false;
    return target % gcd(x,y) == 0;
}

int main() {
    auto start = chrono::steady_clock::now();
    cout << canMeasureWater(3,5,4);
    auto end = chrono::steady_clock::now();
    cout << "\n\n... time taken: " << chrono::duration_cast<chrono::milliseconds>(end-start).count() << "ms";
    
    return 0;
}
