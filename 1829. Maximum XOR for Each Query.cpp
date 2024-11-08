class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        vector<int> k(nums.size());
        int x = 0;
        int target = pow(2, maximumBit)-1;
        for(int i = 0;i < nums.size();i++){
            x ^= nums[i];
        }
        for(int i = 0;i < nums.size();i++){
            k[i] = x ^ target;
            x ^= nums[nums.size()-1-i];
        }
        return k;
    }
};