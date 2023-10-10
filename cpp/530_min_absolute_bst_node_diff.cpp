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


#include <bits/stdc++.h>

class Solution {
public:

TreeNode *rightMost(TreeNode *root){
    if(!root)
        return nullptr;

    while(root->right){
        root = root->right;
    }
    return root;
}

TreeNode *leftMost(TreeNode *root){
    if(!root)
        return nullptr;

    while(root->left){
        root = root->left;
    }
    return root;
}

int getMinimumDifference(TreeNode* root){
	int curr_min = 100000,local_min=0;
	stack<TreeNode*> st;

	while(root){
		if(root->left){
            TreeNode *x = rightMost(root->left);
			local_min = abs(root->val-x->val);
			if(local_min<curr_min)
				curr_min = local_min;
		}
		if(root->right){
            TreeNode *x = leftMost(root->right);
			local_min = abs(root->val-x->val);
			if(local_min<curr_min)
				curr_min = local_min;

			st.push(root->right);
		}

		root = root->left;
		if(!root){
			if(!st.empty()){
				root = st.top();
				st.pop();
			}
			else
				break;
		}
	}

	return curr_min;
}
};
