using namespace std;

class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int total = numBottles;
        while(numBottles >= numExchange) {
            total += floor(numBottles/numExchange);
            numBottles = (numBottles % numExchange) + floor(numBottles/numExchange);
        }

        return total;
    }
};