//
// Created by zhangjiayuan on 23-5-18.
//

#ifndef BOOSTGEOMETRY_BINARYTREE_H
#define BOOSTGEOMETRY_BINARYTREE_H

#include <stack>
#include <algorithm>
#include <queue>
#include "Util.h"

class TreeNode {
public:
    TreeNode() {}
    TreeNode(int val) { this->val = val; }
    TreeNode(int val, TreeNode* left, TreeNode* right) {
        this->val = val;
        this->left = left;
        this->right = right;
    }
    int val;
    TreeNode* left;
    TreeNode* right;
};

class Solution {
public:
    void traversal(TreeNode* cur, std::vector<int>& vec) {
        if (cur == NULL) return;
        vec.push_back(cur->val);    // 中
        traversal(cur->left, vec);  // 左
        traversal(cur->right, vec); // 右
    }

    std::vector<int> preorderTraversal(TreeNode* root) {
        std::vector<int> result;
        traversal(root, result);
        return result;
    }

    std::vector<int> preorderTraversalIterative(TreeNode* root) {
        std::stack<TreeNode*> st;
        std::vector<int> result;
        if (root == NULL) return result;
        st.push(root);
        while (!st.empty()) {
            TreeNode* node = st.top();                       // 中
            st.pop();
            result.push_back(node->val);
            if (node->right) st.push(node->right);           // 右（空节点不入栈）
            if (node->left) st.push(node->left);             // 左（空节点不入栈）
        }
        return result;
    }
};

class Solution1 {
public:
    void traversal(TreeNode* cur, std::vector<int>& vec) {
        if (cur == NULL) return;
        traversal(cur->left, vec);  // 左
        vec.push_back(cur->val);    // 中
        traversal(cur->right, vec); // 右
    }

    std::vector<int> inorderTraversal(TreeNode* root) {
        std::vector<int> result;
        traversal(root, result);
        return result;
    }

    std::vector<int> inorderTraversalIterative(TreeNode* root) {
        std::vector<int> result;
        std::stack<TreeNode*> st;
        TreeNode* cur = root;
        while (cur != NULL || !st.empty()) {
            if (cur != NULL) { // 指针来访问节点，访问到最底层
                st.push(cur); // 将访问的节点放进栈
                cur = cur->left;                // 左
            } else {
                cur = st.top(); // 从栈里弹出的数据，就是要处理的数据（放进result数组里的数据）
                st.pop();
                result.push_back(cur->val);     // 中
                cur = cur->right;               // 右
            }
        }
        return result;
    }
};


class Solution2 {
public:
    void traversal(TreeNode* cur, std::vector<int>& vec) {
        if (cur == NULL) return;
        traversal(cur->left, vec);  // 左
        traversal(cur->right, vec); // 右
        vec.push_back(cur->val);    // 中
    }

    std::vector<int> postorderTraversal(TreeNode* root) {
        std::vector<int> result;
        traversal(root, result);
        return result;
    }

    std::vector<int> postorderTraversalIterative(TreeNode* root) {
        std::stack<TreeNode*> st;
        std::vector<int> result;
        if (root == NULL) return result;
        st.push(root);
        while (!st.empty()) {
            TreeNode* node = st.top();
            st.pop();
            result.push_back(node->val);
            if (node->left) st.push(node->left); // 相对于前序遍历，这更改一下入栈顺序 （空节点不入栈）
            if (node->right) st.push(node->right); // 空节点不入栈
        }
        std::reverse(result.begin(), result.end()); // 将结果反转之后就是左右中的顺序了
        return result;
    }
};


class Solution4 {
public:
    void order(TreeNode* cur, std::vector<std::vector<int>>& result, int depth)
    {
        if (cur == nullptr) return;
        if (result.size() == depth) result.push_back(std::vector<int>());
        result[depth].push_back(cur->val);
        order(cur->left, result, depth + 1);
        order(cur->right, result, depth + 1);
    }
    std::vector<std::vector<int>> levelOrder(TreeNode* root) {
        std::vector<std::vector<int>> result;
        int depth = 0;
        order(root, result, depth);
        return result;
    }

    std::vector<std::vector<int>> levelOrderIterative(TreeNode* root) {
        std::queue<TreeNode*> que;
        if (root != NULL) que.push(root);
        std::vector<std::vector<int>> result;
        while (!que.empty()) {
            int size = que.size();
            std::vector<int> vec;
            for (int i = 0; i < size; i++) {
                TreeNode* node = que.front();
                que.pop();
                vec.push_back(node->val);
                if (node->left) que.push(node->left);
                if (node->right) que.push(node->right);
            }
            result.push_back(vec);
        }
        return result;
    }

};



class Solution5 {
public:
    void invert(TreeNode* node) {
        if (node == nullptr) return;
        std::swap(node->left, node->right);
        invert(node->left);
        invert(node->right);
    }

    void invertBinaryTree(TreeNode* root) {
        if (root == nullptr) return;
        invert(root);
    }

    void invertBinaryTreeIterativeBFS(TreeNode* root) {
        if (root == nullptr) return;
        std::queue<TreeNode*> que;
        que.push(root);
        while (!que.empty()) {
            int size = que.size();
            for (int i = 0; i < size; i++) {
                TreeNode* node = que.front();
                que.pop();
                std::swap(node->left, node->right);
                if (node->left) que.push(node->left);
                if (node->right) que.push(node->right);
            }
        }
    }

    TreeNode* invertTreeDFS(TreeNode* root) {
        if (root == NULL) return root;
        std::stack<TreeNode*> st;
        st.push(root);
        while(!st.empty()) {
            TreeNode* node = st.top();              // 中
            st.pop();
            std::swap(node->left, node->right);
            if(node->right) st.push(node->right);   // 右
            if(node->left) st.push(node->left);     // 左
        }
        return root;
    }
};

// symmetric binary tree
class solution6 {
    bool isSymmetric(TreeNode* root) {
        if (root == nullptr) return true;
        return isCompare(root->left, root->right);
    }

    bool isCompare(TreeNode* left, TreeNode* right) {
        if (left == nullptr && right == nullptr) return true;
        if (left == nullptr || right == nullptr) return false;
        if (left->val != right->val) return false;
        return isCompare(left->right, right->left) && isCompare(left->left, right->right);
    }

    bool isSymmetricIterative(TreeNode* root) {
        if (root == nullptr) return true;
        std::queue<TreeNode*> que;
        que.push(root->left);
        que.push(root->right);
        while (!que.empty()) {
            TreeNode* leftNode = que.front();
            que.pop();
            TreeNode* rightNode = que.front();
            que.pop();
            if (!leftNode && !rightNode) {
                continue;
            }

            // 左右一个节点不为空，或者都不为空但数值不相同，返回false
            if ((!leftNode || !rightNode || (leftNode->val != rightNode->val))) {
                return false;
            }
            que.push(leftNode->left);   // 加入左节点左孩子
            que.push(rightNode->right); // 加入右节点右孩子
            que.push(leftNode->right);  // 加入左节点右孩子
            que.push(rightNode->left);  // 加入右节点左孩子
        }
        return true;
    }

};


/// 104
class solution7 {
    int greatestDepth(TreeNode* root) {
        if (root == nullptr) return 0;
        return findMax(root);
    }

    int findMax(TreeNode* node) {
        if (node == NULL) return 0;
        int leftdepth = findMax(node->left);       // 左
        int rightdepth = findMax(node->right);     // 右
        int depth = 1 + std::max(leftdepth, rightdepth); // 中
        return depth;
    }

};

#endif //BOOSTGEOMETRY_BINARYTREE_H
