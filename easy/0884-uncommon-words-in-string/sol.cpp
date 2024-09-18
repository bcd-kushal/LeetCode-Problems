#include <string>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        vector<string> uncommons;
        unordered_map<string,bool> count;
        string temp = "";
        s1 += " " + s2 + " ";

        for(int i=0;i<s1.size();i++) {
            if(s1[i]==' ') {
                if(temp.size() > 0) {
                    if(count.find(temp)!=count.end())   count[temp] = false;
                    else                                count[temp] = true;
                }
                temp = "";
            }
            else
                temp += s1[i];
        }

        for(auto it=count.begin();it!=count.end();it++)
            if(it->second)
                uncommons.push_back(it->first);
        
        return uncommons;
    }
};