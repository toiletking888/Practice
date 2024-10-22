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
    void DFS(TreeNode* root, int level, vector<long long> &sum){
        if(sum.size() <= level) sum.push_back(root->val);
        else sum[level]+=root->val;
        if(root->left) DFS(root->left, level+1, sum);
        if(root->right) DFS(root->right, level+1, sum);
    }
    long long kthLargestLevelSum(TreeNode* root, int k) {
        vector<long long> sum;
        DFS(root, 0, sum);
        if(sum.size() < k) return -1;
        sort(sum.begin(), sum.end());
        return sum[sum.size()-k];
    }
};