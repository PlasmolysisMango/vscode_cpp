#include <stack>
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
public:
    void flatten(TreeNode* root) {
        stack<TreeNode*> st;
        if (root == nullptr) 
            return;
        st.push(root);
        TreeNode *prev = new TreeNode(), *dhead;
        dhead = prev;
        while (!st.empty()) {
            TreeNode *tmp = st.top(); st.pop();
            if (tmp) {
                if (tmp->right)
                    st.push(tmp->right);
                if (tmp->left)
                    st.push(tmp->left);
                st.push(tmp);
                st.push(nullptr);
            }
            else {
                tmp = st.top(); st.pop();
                prev->left = nullptr;
                prev->right = tmp;
                prev = tmp;
            }
        }
        delete dhead;
    }
};

int main() {
    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(2);
    Solution so;
    so.flatten(root);
    return 0;
}