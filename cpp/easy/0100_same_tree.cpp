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
        bool sameNode(TreeNode *a, TreeNode *b) { 
            if(a->val != b->val)        return false;
            if(!(a->left && b->left && a->left->val==b->left->val) && !(!a->left && !b->left))          return false;
            if(!(a->right && b->right && a->right->val==b->right->val) && !(!a->right && !b->right))    return false;
            return true;
        }

    public:
        bool isSameTree(TreeNode* p, TreeNode* q) {
            if(!p && !q)                return true;
            if((!p && q) || (p && !q))  return false;

            queue<TreeNode*> Q1, Q2;

            if(sameNode(p,q)) {
                Q1.push(p);
                Q2.push(q);

                while(!Q1.empty() && !Q2.empty()) {
                    if(!sameNode(Q1.front(),Q2.front()))        return false;

                    if(Q1.front()->left) {
                        Q1.push(Q1.front()->left);
                        Q2.push(Q2.front()->left);
                    }
                    
                    if(Q1.front()->right) {
                        Q1.push(Q1.front()->right);
                        Q2.push(Q2.front()->right);
                    }

                    Q1.pop();
                    Q2.pop();
                }

                if(Q1.empty() && Q2.empty())    
                    return true;
                return false;
            }
            else
                return false;
        }
};

int main() {
    TreeNode *head1 = new TreeNode(), 
             *head2 = new TreeNode();
    Tree tree;

    auto start = chrono::steady_clock::now();
    cout << tree.isSameTree(head1, head2);
    auto end = chrono::steady_clock::now();

    cout << "\n... time taken: " << chrono::duration_cast<chrono::milliseconds>(end-start).count() << "ms";
    return 0;
}