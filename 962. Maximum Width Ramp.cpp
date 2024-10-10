class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        stack<int> t;
        int max_width = 0;
        for(int i = 0;i < nums.size();i++){
            if(t.empty() || nums[t.top()] > nums[i]){
                t.push(i);
            }
        }
        for(int j = nums.size()-1;j >= 0;j--){
            while(!t.empty() && nums[t.top()] <= nums[j]){
                max_width = max(max_width, j - t.top());
                t.pop();
            }
        }
        return max_width;
    }
};