#include <vector>
#include <unordered_map>
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
    int firstCol = 1, lastCol = -1;
    unordered_map<int,vector<vector<int>>> map;

    void traverseTree(TreeNode* ptr, int row, int col) {
        if(!ptr)    return;
        
        if(map.find(col)==map.end())
            map[col] = {};
        while(map[col].size() <= row)
            map[col].push_back({});
        map[col][row].push_back(ptr->val);

        if(col <= 0)    firstCol = min(firstCol, col);
        if(col >= 0)    lastCol = max(lastCol, col);

        traverseTree(ptr->left, row+1, col-1);
        traverseTree(ptr->right, row+1, col+1);
    }

public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        traverseTree(root, 0, 0);
        vector<vector<int>> cols(lastCol-firstCol+1, vector<int>());
        vector<int> temp = {};
        
        for(int i=firstCol;i<=lastCol;i+=1) {
            for(int j=0;j<map[i].size();j+=1) {
                sort(map[i][j].begin(), map[i][j].end());
                for(int k=0;k<map[i][j].size();k+=1)
                    temp.push_back(map[i][j][k]);
            }
            cols[i - firstCol] = temp;
            temp = {};
        }
        
        return cols;
    }
};