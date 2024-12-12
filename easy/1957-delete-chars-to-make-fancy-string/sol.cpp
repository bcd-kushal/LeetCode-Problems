#include <string>
using namespace std;

class Solution {
public:
    string makeFancyString(string s) {
      string fancy = "";
      char curr = s[0];
      bool allowMore = true;
      
      fancy += s[0];
      for(int i=1;i<s.size();i+=1) {
        if(s[i]==curr && allowMore) {
          fancy += s[i];
          allowMore = false;
        }
        else if(s[i]!=curr) {
          fancy += s[i];
          allowMore = true;
          curr = s[i];
        }
      }
      
      return fancy;
    }
};
