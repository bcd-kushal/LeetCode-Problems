#include <string>
#include <cmath>
using namespace std;

class Solution {
private:
    string generate(string s) {
        for(int i=0;i<s.size();i+=1)
            s[i] = (char)((static_cast<int>(s[i]) - 97 + 1) % 26 + 97);
        return s;
    }

public:
    char kthCharacter(int k) {
        string s = "a";
        for(int i=0;i<ceil((float)log2(k))+1;i+=1)
            s += generate(s);
        
        return s[k-1];
    }
};