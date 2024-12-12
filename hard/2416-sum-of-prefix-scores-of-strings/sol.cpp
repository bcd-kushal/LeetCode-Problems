#include <vector>
#include <unordered_map>
#include <string>
using namespace std;

class Solution {
public:
    vector<int> sumPrefixScores(vector<string>& words) {
        unordered_map<string,vector<int>> finds;
        vector<int> scores(words.size(), 0);

        string temp;
        int len;

        for(int i=0;i<words.size();i+=1) {
            temp = "";
            for(int j=0;j<words[i].size();j+=1) {
                temp += words[i][j];
                if(finds.find(temp)!=finds.end())   finds[temp].push_back(i);
                else                                finds[temp] = { i };
            }
        }
        
        for(auto it=finds.begin();it!=finds.end();it++) {
            len = it->second.size();
            for(int i=0;i<len;i+=1)
                scores[(it->second)[i]] += len;
        }

        return scores;
    }
};