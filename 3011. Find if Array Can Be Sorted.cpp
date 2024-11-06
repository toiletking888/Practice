class Solution {
public:
    bool canSortArray(vector<int>& nums) {
        vector<int> already = nums;
        sort(already.begin(), already.end());
        vector<int> set_bit(nums.size());
        for(int i = 0;i < nums.size();i++){
            int temp = nums[i];
            while(temp != 0){
                if(temp %2 == 0){
                    temp /= 2;
                }
                else{
                    set_bit[i]++;
                    temp /= 2;
                }
            }
        }
        for(int i = 0;i < nums.size()-1;i++){
            for(int j = 0;j < nums.size()-i-1;j++){
                if(nums[j] > nums[j+1] && set_bit[j] == set_bit[j+1]){
                    int temp_n = nums[j];
                    nums[j] = nums[j+1];
                    nums[j+1] = temp_n;
                    int temp_b = set_bit[j];
                    set_bit[j] = set_bit[j+1];
                    set_bit[j+1] = temp_b;
                }
            }
        }
        if(already == nums){
            return true;
        }
        else{
            return false;
        }
    }
};
// top solution
class Solution {
public:
    bool canSortArray(std::vector<int>& nums) {
        int prevMax = INT_MIN;
        int currMax = nums[0];
        int currMin = nums[0];
        int setBits = countBits(nums[0]);

        for (size_t i = 1; i < nums.size(); i++) {
            if (setBits == countBits(nums[i])) {
                currMax = std::max(currMax, nums[i]);
                currMin = std::min(currMin, nums[i]);
            } else {
                if (currMin < prevMax)
                    return false;

                prevMax = currMax;
                setBits = countBits(nums[i]);
                currMin = nums[i];
                currMax = nums[i];
            }
        }

        return currMin > prevMax;
    }

private:
    int countBits(int num) {
        return std::bitset<32>(num).count();
    }
};