#include <unordered_set>
using namespace std;

class Solution {
private:
    int sum_of_squares(int n) {
        int sum = 0;
        while(n > 0) {
            int digit = n % 10;
            sum += digit * digit;
            n /= 10; 
        }

        return sum;
    }

public:
    bool isHappy(int n) {
        unordered_set<int> visited_nums;
        int sq = sum_of_squares(n);

        while(sq!=1 && visited_nums.find(sq)==visited_nums.end()) {
            visited_nums.insert(sq);
            sq = sum_of_squares(sq);
        }

        return sq == 1;
    }
};