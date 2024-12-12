#include <vector>
using namespace std;

class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        vector<int> ans(code.size(),0);

        if(k==0)
            return ans;
        
        int curr = 0, n = code.size();
        int left = k > 0 ? 1%n : (n+k)%n;
        int right = k < 0 ? (n-1)%n : k%n;

        for(int i=left;i<=right;i+=1)
            curr += code[i%n];
        
        for(int i=0;i<code.size();i+=1) {
            ans[i] = curr;

            curr -= code[left];
            left = (left+1) % code.size();
            
            right = (right+1) % code.size();
            curr += code[right];
        }

        return ans;
    }
};