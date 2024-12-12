#include <string>
using namespace std;

class Solution {
public:
    int countSegments(string s) {
        s += ' ';
        int segments = 0;
        bool found = false;

        for(int i=0;i<s.size();i+=1) {
            if(s[i]==' ') {
                if(found)
                    segments += 1;
                found = false;
            }
            else found = true;
        }

        return segments;
    }
};