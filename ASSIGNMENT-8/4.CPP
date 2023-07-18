#include <iostream>
#include <string>
#include <stack>

// Definition for a binary tree node
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

TreeNode* str2tree(const std::string& s) {
    if (s.empty()) {
        return nullptr;
    }

    std::stack<TreeNode*> stack;
    int i = 0;

    while (i < s.length()) {
        if (isdigit(s[i]) || s[i] == '-') {
            int start = i;
            while (i < s.length() && (isdigit(s[i]) || s[i] == '-')) {
                i++;
            }
            int val = std::stoi(s.substr(start, i - start));
            TreeNode* node = new TreeNode(val);
            if (!stack.empty()) {
                TreeNode* parent = stack.top();
                if (!parent->left) {
                    parent->left = node;
                } else {
                    parent->right = node;
                }
            }
            stack.push(node);
        } else if (s[i] == ')') {
            stack.pop();
        }
        i++;
    }

    return stack.top();
}

// Function to perform inorder traversal of the binary tree
void inorderTraversal(TreeNode* root) {
    if (!root) {
        return;
    }
    inorderTraversal(root->left);
    std::cout << root->val << " ";
    inorderTraversal(root->right);
}

int main() {
    std::string s = "4(2(3)(1))(6(5))";

    TreeNode* root = str2tree(s);

    std::cout << "Inorder traversal of the constructed binary tree: ";
    inorderTraversal(root);
    std::cout << std::endl;

    return 0;
}
