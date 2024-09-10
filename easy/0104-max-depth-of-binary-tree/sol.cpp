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
    int nodeDepth(TreeNode *ptr) {
        if(!ptr) return 0;
        if(!ptr->left && !ptr->right) return 1;
        if(!ptr->left) return 1 + nodeDepth(ptr->right);
        if(!ptr->right) return 1 + nodeDepth(ptr->left);
        return 1 + max(nodeDepth(ptr->left), nodeDepth(ptr->right));
    }

public:
    int maxDepth(TreeNode* root) {
        return nodeDepth(root);
    }
};