/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    stack<TreeNode*> tmp;
    unordered_set<int> to_del;
    TreeNode* dfs(TreeNode* root){
        if(!root) return NULL;
        root->left = dfs(root->left);
        root->right = dfs(root->right);
        if(to_del.find(root->val)!=to_del.end()){
            if(root->left)tmp.push(root->left);
            if(root->right)tmp.push(root->right);
            return NULL;
        }
        return root;
    }
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        vector<TreeNode*> forest;
        for(auto i:to_delete){
            to_del.insert(i);
        }
        tmp.push(root);
        while(!tmp.empty()){
            TreeNode* current = tmp.top();
            tmp.pop();
            TreeNode* ans_tree = dfs(current);
            if(ans_tree) forest.push_back(ans_tree);
        }
        return forest;
    }
};