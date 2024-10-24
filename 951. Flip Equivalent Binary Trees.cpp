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
    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        queue<TreeNode*> q1, q2;
        if(!root1 && !root2){
            return true;
        }
        if(!root1 || !root2){
            return false;
        }
        if(root1->val != root2->val){
            return false;
        }
        q1.push(root1);
        q2.push(root2);
        while(!q1.empty() && !q2.empty()){
            bool checkleft = false, checkright = false, diff_left = false, diff_right = false;
            TreeNode* temp1 = q1.front();
            q1.pop();
            TreeNode* temp2 = q2.front();
            q2.pop();
            if(!temp1->left && !temp1->right && !temp2->left && !temp2->right){
                continue;
            }

            if( temp1->left && temp2->left && (temp1->left->val == temp2->left->val)){
                cout << temp1->left->val << " " << temp2->left->val;
                checkleft = true;
            }
            else if(temp1->left && temp2->right && (temp1->left->val == temp2->right->val)){
                cout << temp1->left->val << " " << temp2->right->val;
                continue;
            }
            else{
                diff_left = true;
            }

            if(!diff_left){
                if(checkleft){
                    q1.push(temp1->left);
                    q2.push(temp2->left);
                }
                else{
                    q1.push(temp1->left);
                    q2.push(temp2->right);
                }
            }

            if(temp1->right && temp2->left && (temp1->right->val == temp2->left->val)){
                cout << temp1->right->val << " " << temp2->left->val;
                checkright = true;
            }
            else if(temp1->right && temp2->right && (temp1->right->val == temp2->right->val)){
                cout << temp1->right->val << " " << temp2->right->val;
                continue;
            }
            else{
                diff_right = true;
            }

            if(!diff_right){
                if(checkright){
                    q1.push(temp1->right);
                    q2.push(temp2->left);
                }
                else{
                    q1.push(temp1->right);
                    q2.push(temp2->right);
                }
            }

            if(diff_left && diff_right){
                return false;
            }
        }
        return true;
    }
};

//top solution
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
    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        if(root1 == NULL || root2 == NULL){
            return root1 == root2;
        }
        if(root1->val != root2->val){
            return false;
        }
        return (flipEquiv(root1->left, root2->left) && flipEquiv(root1->right, root2->right)) || flipEquiv(root1->left, root2->right) && flipEquiv(root1->right, root2->left);
    }
};