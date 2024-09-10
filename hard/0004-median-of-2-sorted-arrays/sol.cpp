#include <vector>
#include <queue>
using namespace std;

class Solution {
private:
    struct MinHeapSortLogic {
        bool operator()(const vector<int> &a, const vector<int> &b) {
            return a[0] > b[0];
        }
    };
    struct MaxHeapSortLogic {
        bool operator()(const vector<int> &a, const vector<int> &b) {
            return a[0] < b[0];
        }
    };

public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // initializations
        priority_queue<vector<int>, vector<vector<int>>, MinHeapSortLogic> lowest;
        priority_queue<vector<int>, vector<vector<int>>, MaxHeapSortLogic> highest;

        int len1 = nums1.size(), len2 = nums2.size();
        int max_execs = (len1+len2)%2 == 0 ? len1+len2-2 : len1+len2-1;
        int curr_execs = 0;
        pair<int,int> left, right;

        // feed first 2 and last 2:: { value, index, array_number }
        if(len1 > 0) {
            lowest.push({nums1[0],0,1});
            highest.push({nums1[len1-1],len1-1,1});
        }
        if(len2 > 0) {
            lowest.push({nums2[0],0,2});
            highest.push({nums2[len2-1],len2-1,2});
        }

        // run loop
        while(curr_execs < max_execs) {
            vector<int> low = lowest.top();
            vector<int> high = highest.top();
            lowest.pop();
            highest.pop();

            if(low[2]==1 && low[1]+1 < len1)   
                lowest.push({ nums1[low[1]+1], low[1]+1, 1 });
            else if(low[2]==2 && low[1]+1 < len2)            
                lowest.push({ nums2[low[1]+1], low[1]+1, 2 });

            if(high[2]==1 && high[1]-1 >= 0)   
                highest.push({ nums1[high[1]-1], high[1]-1, 1 });
            else if(high[2]==2 && high[1]-1 >= 0)            
                highest.push({ nums2[high[1]-1], high[1]-1, 2 });

            curr_execs += 2;
        }

        vector<int> low = lowest.top();
        vector<int> high = highest.top();

        return (double(high[0])+double(low[0]))/2.0;
    }
};