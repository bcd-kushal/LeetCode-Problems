using namespace std;

class Solution {
public:
    int minBitFlips(int start, int goal) {
        int xor_value = start^goal;
        int minFlips = 0;
        
        while(xor_value > 0) {
            if(xor_value%2==1)
                minFlips += 1;
            xor_value >>= 1;
        }

        return minFlips;
    }
};