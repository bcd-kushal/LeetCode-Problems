#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        if(arr.size()==0)   return {};

        unordered_map<int,int> scores;
        vector<int> ranks = arr;

        sort(arr.begin(),arr.end());
        int rank = 2;

        scores[arr[0]] = 1;

        for(int i=1;i<arr.size();i+=1)
            if(arr[i]!=arr[i-1]) {
                scores[arr[i]] = rank;
                rank += 1;
            }
        
        for(int i=0;i<ranks.size();i+=1) 
            ranks[i] = scores[ranks[i]];
        
        return ranks;
    }
};