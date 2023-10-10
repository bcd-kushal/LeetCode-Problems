
struct TreeNode* deleteNode(struct TreeNode* root, int key){
    struct TreeNode *p=NULL, *q, *r, *s;
    q = root;
    while(q != NULL && q->val != key) {
        p = q;
        if (key < p->val) {
            q = p->left;
        } else {
            q = p->right;
        }
    }
    if (q == NULL) {
        return root;
    }
    if (q->left == NULL) {
        if (p == NULL) {
            root = q->right;
        } else if (p->right == q) {
            p->right = q->right;
        } else {
            p->left = q->right;
        }
        free(q);
        return root;
    } else if (q->right == NULL) {
        if (p == NULL) {
            root = q->left;
        } else if (p->right == q) {
            p->right = q->left;
        } else {
            p->left = q->left;
        }
        free(q);
        return root;
    }
    r = q;
    s = r->right;
    while (s->left != NULL) {
        r = s;
        s = r->left;
    }
    if (r == q) {
        if (p != NULL) {
            if (p->right == q) {
                p->right = s;
            } else {
                p->left = s;
            }
        }
        s->left = q->left;
        if (root == q) {
            root = s;
        }
        free(q);
        return root;
    }
    r->left = s->right;
    if (p != NULL) {
        if (p->right == q) {
            p->right = s;
        } else {
            p->left = s;
        }
    } else {
        root = s;
    }
    s->left = q->left;
    s->right = q->right;
    free(q);
    return root;
}