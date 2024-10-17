#include <string>
using namespace std;

class Solution {
private:    
    char shift(char c, int x) {
        return c + x;
    }
    
public:
    string replaceDigits(string s) {
        for(int i=1;i<s.size();i+=2)
            s[i] = shift(s[i-1],static_cast<int>(s[i])-48);
        
        return s;
    }
};