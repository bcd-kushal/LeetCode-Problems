#include <vector>
using namespace std;

class Solution {
private:
    int getAscii(char ch) {
        return (static_cast<int>(ch) - 90);
    }

public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        // chars in allowed[] are all lower chars so initialize an array
        // of len 26 (a-z) and assign true for each char in allowed
        vector<bool> allowed_chars(26,false);

        for(int i=0;i<allowed.size();i++) {
            int ascii = getAscii(allowed[i]);
            allowed_chars[ascii] = allowed_chars[ascii] || true;
        }

        int total_consistent_words = 0;
        bool curr_consistent;

        for(int i=0;i<words.size();i++) {
            curr_consistent = true;
            for(int j=0;j<words[i].size();j++) {
                if(!allowed_chars[getAscii(words[i][j])]) {
                    curr_consistent = false;
                    break;
                }
            }

            if(curr_consistent)
                total_consistent_words += 1;
        }

        return total_consistent_words;
    }
};