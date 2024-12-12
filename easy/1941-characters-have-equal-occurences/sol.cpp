#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    bool areOccurrencesEqual(string s) {
        vector<int> freqs(26,0);
        int latch;

        for(int i=0;i<s.size();i+=1) {
            int index = static_cast<int>(s[i]) - 97;
            freqs[index] += 1;
            latch = freqs[index];
        }
        
        for(int i=0;i<26;i+=1)
          if(freqs[i] && freqs[i]!=latch)
            return false;
        
        return true;
    }
};