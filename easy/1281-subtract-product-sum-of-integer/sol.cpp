using namespace std;

class Solution {
public:
    int subtractProductAndSum(int n) {
        int prod = 1, sum = 0;
        for(;n>0;n/=10) {
            prod *= n%10;
            sum += n%10;
        }

        return prod - sum;
    }
};