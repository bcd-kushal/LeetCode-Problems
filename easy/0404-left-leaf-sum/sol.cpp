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
    int leftLeafSum(TreeNode* ptr) {
        if(!ptr)    return 0;
        int rightSum = leftLeafSum(ptr->right);
        if(ptr->left && !ptr->left->left && !ptr->left->right)
            return ptr->left->val + rightSum;
        int leftSum = leftLeafSum(ptr->left);
        return leftSum + rightSum;
    }

public:
    int sumOfLeftLeaves(TreeNode* root) {
        return leftLeafSum(root);    
    }
};