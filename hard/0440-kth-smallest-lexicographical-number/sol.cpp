using namespace std;

class Solution {
public:
    int findKthNumber(int n, int k) {
        long curr = 1;

        for(int i=1; i<k; i+=1) {
            if(curr*10 <= n)
                curr *= 10;
            else {
                while(curr%10==9 || curr>=n)
                    curr = curr/10;
                curr += 1;
            }
        }

        return (int)curr;
    }
};