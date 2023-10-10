/*
Given the root of a binary search tree, and an integer k, return the kth smallest value (1-indexed)
of all the values of the nodes in the tree.

Input: root = [3,1,4,null,2], k = 1
Output: 1
Input: root = [5,3,6,2,4,null,null,1], k = 3
Output: 3

Constraints:
The number of nodes in the tree is n.
1 <= k <= n <= 104
0 <= Node.val <= 104
*/

/*
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        //this is similar to traversing the BST in inorder fashion
        // just keep a counter and return when counter==k
        if(!root->left && !root->right)
            return root->val;

        int root_node = root->val;
        int flag=0;
        stack<TreeNode*> st;

        if(root->left)
            while(root->left){
                st.push(root);
                root = root->left;
            }
        else{
            st.push(root);
            flag = 1;
        }

        TreeNode *ans = root;

        while(!st.empty()){
            if(k==1)
                break;

            if(root->right){
                if(flag==0)
                    st.push(root);
                root = root->right;

                while(root->left){
                    st.push(root);
                    root = root->left;
                }
                ans = root;
                k-=1;
                continue;
            }

            root = st.top();
            ans = root;
            k-=1;
            if(ans->val!=root_node)
                st.pop();
        }

        return ans->val;

    }
};
