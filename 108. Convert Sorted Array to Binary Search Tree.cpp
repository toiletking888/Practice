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
    TreeNode* CreateBST(int front, int end, vector<int> &nums){
        if(front > end){
            return NULL;
        }
        else{
            int mid = (front + end)/2;
            TreeNode* root = new TreeNode(nums[mid]);
            root->left = CreateBST(front, mid-1, nums);
            root->right = CreateBST(mid+1, end, nums);
            return root;
        }
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return CreateBST(0, nums.size()-1, nums);
    }
};