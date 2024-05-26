#include <bits/stdc++.h>
using namespace std;
 
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Tree {
    private:
        bool isNodeSymmetric(TreeNode *a, TreeNode *b) {
            if(a->val != b->val)        return false;
            if(!(a->left && b->right && a->left->val==b->right->val) && !(!a->left && !b->right))   return false;
            if(!(a->right && b->left && a->right->val==b->left->val) && !(!a->right && !b->left))   return false;
            return true;
        }

        TreeNode *symmetricCheck(TreeNode *a, TreeNode *b, bool &result) {
            if(!isNodeSymmetric(a,b)) {
                result &= false;
                return nullptr;
            }
            if(!result)                     return nullptr;
            if(a->left) 
                symmetricCheck(a->left,b->right, result);
            if(a->right) 
                symmetricCheck(a->right,b->left, result);

            return nullptr;
        }

    public:
        bool isSymmetric(TreeNode* root) {
            if(!root)                       return true;
            if(!root->left && !root->right) return true;
            if((!root->left && root->right) || (root->left && !root->right)) return false;

            bool ans = true;
            symmetricCheck(root->left,root->right,ans);

            return ans;
        }
};

int main() {
    TreeNode *head = new TreeNode();
    Tree tree;
    
    auto start = chrono::steady_clock::now();
    cout << tree.isSymmetric(head);
    auto end = chrono::steady_clock::now();

    cout << "\n... time taken: " << chrono::duration_cast<chrono::milliseconds>(end-start).count() << "ms";
    return 0;
}
