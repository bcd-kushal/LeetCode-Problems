#include <vector>
#include <algorithm>
using namespace std;

class Solution {
private:
    struct Compare {
        bool operator()(vector<int> &a, vector<int> &b) const {
            if (a[0] == b[0])
                return a[1] > b[1];
            return a[0] < b[0];
        }
    };

public : 
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        Compare compare;
        sort(envelopes.begin(), envelopes.end(), compare);
        vector<int> lis;

        for (int i = 0; i < envelopes.size(); i++) {
            if (lis.empty() || lis[lis.size() - 1] < envelopes[i][1])
                lis.push_back(envelopes[i][1]);
            else {
                auto it = lower_bound(lis.begin(), lis.end(), envelopes[i][1]);
                if (it != lis.end())
                    *it = envelopes[i][1];
            }
        }

        return lis.size();
    }
};