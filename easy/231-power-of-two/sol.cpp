using namespace std;

class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n<=0)            return false;

        bool foundOne = false;
        while(n>0) {
            if(foundOne)    return false;
            if(n%2==1)      foundOne = true;
            n >>= 1;
        }

        return true;
    }
};