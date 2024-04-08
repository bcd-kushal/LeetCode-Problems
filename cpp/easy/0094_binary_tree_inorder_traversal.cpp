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
    TreeNode *inorderRecursively(TreeNode *ptr, vector<int> &store) {
        if(ptr->left)
            ptr->left = inorderRecursively(ptr->left, store);

        store.push_back(ptr->val);
            
        if(ptr->right)
            ptr->right = inorderRecursively(ptr->right, store);

        return ptr;
    }

public:
    vector<int> inorderTraversal(TreeNode* root) {
        if(!root)   return {};
        vector<int> store = {};
        inorderRecursively(root, store);
        return store;
    }
};

int main(){
    TreeNode *head = new TreeNode();
    // insert tree data here...
    Tree t;

    auto start = chrono::steady_clock::now();
    vector<int> ans = t.inorderTraversal(head);
    auto end = chrono::steady_clock::now();

    for_each(ans.begin(), ans.end(), [](int num){
        cout << num << "...";
    });
    cout << "\n...time taken: " << chrono::duration_cast<chrono::milliseconds>(end-start).count() << "ms";

    return 0;
}