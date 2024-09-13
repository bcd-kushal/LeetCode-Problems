#include <vector>
#include <utility>
#include <limits.h>
using namespace std;

class Solution {
public:
    pair<int,vector<int>> checkIds(vector<int> a, vector<int> b) {
        if(a[0] == b[0]) {
            vector<int> vec = {a[0], a[1] + b[1]};
            return make_pair(0, vec);
        }
        if(a[0] < b[0])     return make_pair(-1, a);
        return make_pair(1, b);
    }
    
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        int ptr1 = 0, ptr2 = 0;
        int size1 = nums1.size(), size2 = nums2.size();

        vector<vector<int>> merged;
        vector<int> v1, v2;

        while(ptr1 < size1 || ptr2 < size2) {
            if(ptr1 >= size1)   v1 = { INT_MAX, 0 };
            else                v1 = nums1[ptr1];

            if(ptr2 >= size2)   v2 = { INT_MAX, 0 };
            else                v2 = nums2[ptr2];

            pair<int,vector<int>> result = checkIds(v1, v2);
            merged.push_back(result.second);

            if(result.first == 0) {
                ptr1++;
                ptr2++;
            }
            else if(result.first == -1) {
                ptr1++;
            }
            else {
                ptr2++;
            }
        }

        return merged;
    }
};