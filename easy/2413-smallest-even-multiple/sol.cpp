using namespace std;

class Solution {
public:
    int smallestEvenMultiple(int n) {
        if(n==1)    return 2;
        if(n%2==0)  return n;
        return n*2;
    }
};