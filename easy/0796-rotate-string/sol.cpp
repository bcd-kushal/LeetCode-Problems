#include <string>
using namespace std;

class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.size()!=goal.size())
            return false;
        
        int count = 1, n = s.size();

        while(count <= n) {
            if(s.substr(count-1,n) == goal)
                return true;

            s += s[count-1];
            count += 1;
        }

        return false;
    }
};