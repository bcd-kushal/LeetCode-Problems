#include <bits/stdc++.h>
using namespace std;

class Solution {
    private:

    public:
        int addDigits(int num) {
            if(num==0)          return 0;
            else if(num%9==0)   return 9;
            return num%9;
        }
};

int main() {
    Solution ob;

    auto start = chrono::steady_clock::now();
    cout << ob.addDigits(21849);
    auto end = chrono::steady_clock::now();

    cout << "\n... time taken: " << chrono::duration_cast<chrono::milliseconds>(end-start).count() << "ms"; 
    return 0;
}