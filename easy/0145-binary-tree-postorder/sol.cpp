#include <vector>
#include <utility>
#include <stack>
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
public:
    vector<int> postorderTraversal(TreeNode* root) {
        if(!root)   
            return {};

        vector<int> vals;    
        stack<pair<TreeNode*,int>> st;
        st.push({ root, -1 });

        TreeNode *ptr;

        while(!st.empty()) {
            // if -1, traverse left
            if(st.top().second == -1) {
                ptr = st.top().first;
                st.pop();
                st.push({ ptr, 1 });

                ptr = st.top().first->left;
                if(ptr)
                    st.push({ ptr, -1 });
            }

            // if +1, traverse right
            else if(st.top().second == 1) {
                ptr = st.top().first;
                st.pop();
                st.push({ ptr, 0 });

                ptr = st.top().first->right;
                if(ptr)
                    st.push({ ptr, -1 });
            }

            // if 0, read node
            else {
                ptr = st.top().first;
                st.pop();
                vals.push_back(ptr->val);
            }
        }

        return vals;
    }
};