/*
Given the root of a binary tree, determine if it is a valid binary search tree (BST).

A valid BST is defined as follows:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.


Input: root = [2,1,3]
Output: true

Input: root = [5,1,4,null,null,3,6]
Output: false
Explanation: The root node's value is 5 but its right child's value is 4.

Constraints:
The number of nodes in the tree is in the range [1, 104].
-231 <= Node.val <= 231 - 1
*/

/**
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
    TreeNode *leftMost(TreeNode *ptr){
        while(ptr->left)
            ptr = ptr->left;
        return ptr;
    }
    TreeNode *rightMost(TreeNode *ptr){
        while(ptr->right)
            ptr = ptr->right;
        return ptr;
    }

    bool inorder(TreeNode *ptr){
        if(!ptr)
            return true;

        bool result;

        if(ptr->left){
            result = inorder(ptr->left);

            if(result==false)
                return false;
        }
        //////////////////////////////
        if(ptr->left){
            if(ptr->left->val>=ptr->val)
                return false;
            if(rightMost(ptr->left)->val>=ptr->val)
                return false;
        }
        if(ptr->right){
            if(ptr->right->val<=ptr->val)
                return false;
            if(leftMost(ptr->right)->val<=ptr->val)
                return false;
        }
        ////////////////////////////////
        if(ptr->right){
            result = inorder(ptr->right);

            if(result==false)
                return false;
        }

        return true;
    }

    bool isValidBST(TreeNode* root) {
        if(!root->left && !root->right)
            return true;

        return inorder(root);
    }
};
