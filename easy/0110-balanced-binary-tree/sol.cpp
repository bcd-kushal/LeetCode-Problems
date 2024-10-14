#include <limits.h>
#include <algorithm>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
private:
    bool isHeightBalanced = true;
    
    int checkHeights(TreeNode* ptr) {
        if(!ptr || !isHeightBalanced)
            return 0;
        
        int ld = checkHeights(ptr->left);
        int rd = checkHeights(ptr->right);

        if(abs(ld-rd) > 1)
            isHeightBalanced = false;
        
        return max(ld,rd) + 1;
    }

public:
    bool isBalanced(TreeNode* root) {
        checkHeights(root);
        return isHeightBalanced;
    }
};