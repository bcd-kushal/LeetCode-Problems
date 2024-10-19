#include <stack>
#include <string>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec {
private:
    const string GO_RIGHT = "R";
    const string SEPERATOR = ",";
    const string STACK_POP = "*";

    string encoded = "";

    int preorderTraverse(TreeNode *ptr) {
        if(!ptr)    return 0;

        encoded.append(to_string(ptr->val) + SEPERATOR);

        int left = preorderTraverse(ptr->left);
        int right = 0;

        if(ptr->right) {
            if(left > 0)    encoded.append(STACK_POP + to_string(left) + SEPERATOR);

            encoded.append(GO_RIGHT + SEPERATOR);
            right = preorderTraverse(ptr->right);
            
            if(right > 0)
                return right + 1;
        }
        
        return left + 1;
    }

    int toInteger(string str, bool ignoreFirstChar) {
        int i = ignoreFirstChar ? 1 : 0;
        int num = 0;
        bool isNegative = str[i] == '-' ? true : false;

        if(isNegative)
            i += 1;

        for(;i<str.size();i+=1)
            num = num*10 + static_cast<int>(str[i]) - 48;
        
        return isNegative ? -1*num : num;
    }

public:

    // Encodes a tree to a single string. =================================================================
    string serialize(TreeNode* root) {
        if(!root)   
            return "";
        
        preorderTraverse(root);
        return encoded;
    }

    // Decodes your encoded data to tree. =================================================================
    TreeNode* deserialize(string data) {
        if(data == "")
            return nullptr;

        int value, steps, i=0;
        bool goRight = false;
        string temp = "";

        stack<TreeNode*> st;

        for(;i<data.size();i+=1)
            if(data[i] == SEPERATOR[0]) {
                value = toInteger(temp, false);
                break;
            }
            else
                temp += data[i];

        i += 1;
        temp = "";

        TreeNode *ptr = new TreeNode(value);
        TreeNode *head = ptr;

        for(;i<data.size();i+=1) {
            if(data[i] == SEPERATOR[0]) {
                if(temp == GO_RIGHT)        goRight = true;
                
                else if(temp[0] == STACK_POP[0]) {
                    steps = toInteger(temp, true);
                    while(steps > 0) {
                        ptr = st.top();
                        st.pop();
                        steps -= 1;
                    }
                    goRight = false;
                }
                
                else {
                    st.push(ptr);
                    value = toInteger(temp, false);
                    if(goRight) { 
                        ptr->right = new TreeNode(value); 
                        ptr = ptr->right; 
                    }
                    else {
                        ptr->left  = new TreeNode(value); 
                        ptr = ptr->left; 
                    }

                    goRight = false;
                }

                temp = "";
            }
            else
                temp += data[i];
        }

        return head;
    }
};
