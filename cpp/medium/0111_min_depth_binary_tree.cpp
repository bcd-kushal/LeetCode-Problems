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

class Solution {
    
private:
    bool checkNotVisited(vector<TreeNode*> V, TreeNode* ptr) {
        for(auto i: V)
            if(ptr->val==i->val)
                return false;
        
        return true;
    }

public:
    int minDepth(TreeNode* root) {
        
        int min_nodes_depth = INT_MAX;
        int local_total_nodes = 0;
        
        if(!root)
            return 0;
        
        stack<TreeNode*> S;
        vector<TreeNode*> Visited;
        
        S.push(root);
        
        while(!S.empty()) {
            
            TreeNode *ptr = S.top();
            
            // traverse full depth
            while(ptr->left && checkNotVisited(Visited,ptr->left)){
                ptr = ptr->left;
                local_total_nodes += 1;
                S.push(ptr->left);
                ptr = ptr->left;
            }
            
            min_nodes_depth = min(min_nodes_depth,local_total_nodes);
            local_total_nodes = 0;
            
            
            ptr = S.top();
            
            while(ptr->right && checkNotVisited(Visited,ptr->right)){
                ptr = ptr->right;
                local_total_nodes += 1;
                S.push(ptr->right);
                ptr = ptr->right;
            }
            
            min_nodes_depth = min(min_nodes_depth,local_total_nodes);
            local_total_nodes = 0;

            // update stack
            S.pop();
            
            Visited.push_back(ptr);
        }
        
        return min_nodes_depth;
    }
};
