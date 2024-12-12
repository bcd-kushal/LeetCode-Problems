using namespace std;

class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n==1) return true;
        if(n<2 || n%3!=0) return false;

        while(n%3==0 && n>3)
            n /= 3;
        
        return n==3;
    }
};