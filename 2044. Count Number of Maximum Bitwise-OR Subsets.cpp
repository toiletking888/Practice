//brute force
class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
        int count = 0;
        int total_subset = 1 << nums.size();
        int max = 0;
        int subset_temp = 0;
        for(int i : nums){
            max = max | i;
        }
        for(int i = 0;i < total_subset;i++){
            vector<int> subset;
            for(int j = 0;j < nums.size();j++){
                if(i & (1 << j)){
                    subset.push_back(nums[j]);
                }
            }
            for(int k : subset){
                subset_temp = subset_temp | k;
            }
            if(subset_temp == max){
                count++;
            }
            subset_temp = 0;
        }
        return count;
    }
};
// top solution:
class Solution
{
public:
    void backtrack(const vector<int> &nums, int index, int currentOR, int maxOR, int &count)
    {
        if (currentOR == maxOR)
        {
            count++;
        }

        for (int i = index; i < nums.size(); ++i)
        {
            backtrack(nums, i + 1, currentOR | nums[i], maxOR, count);
        }
    }

    int countMaxOrSubsets(vector<int> &nums)
    {
        int maxOR = 0;

        // Step 1: Compute the maximum OR
        for (int num : nums)
        {
            maxOR |= num;
        }

        int count = 0;
        // Step 2: Backtrack to count the subsets
        backtrack(nums, 0, 0, maxOR, count);

        return count;
    }
};