class Solution {
private: 
    int maxSum; 
    
    
    int maxLength(TreeNode *ptr){
        if(!ptr)
            return 0;
        
        
        int left = max(maxLength(ptr->left),0);
        int right = max(maxLength(ptr->right),0);
        
        maxSum = max(maxSum, ptr->val+left+right);
        
        return max(left,right)+ptr->val;      
    }
public:
    int maxPathSum(TreeNode* root) {
        maxSum = root->val;
        
        //max(ptr->right) + max(ptr->left)
        //if max(ptr->right) + max(ptr->left) + ptr->val > maxSum then maxSum = ...
        
        maxSum = max(maxSum, maxLength(root)); 
        
        return maxSum;
    }
};