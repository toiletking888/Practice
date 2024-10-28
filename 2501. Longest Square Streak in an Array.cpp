class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        vector<int> top;
        vector<int> length;
        int index = 0, max = -1;
        bool next = false;
        int all_one = 0;
        for(int i = 0;i < nums.size();i++){
            for(int j = 0;j < top.size();j++){
                if(sqrt(nums[i]) == top[j]){
                    top[j] = nums[i];
                    length[j]++;
                    next = true;
                }
            }
            if(next){
                continue;
            }
            else{
                top.push_back(nums[i]);
                length.push_back(1);
                next = false;
            }
        }

        for(int i = 0;i < length.size();i++){
            if(length[i] > max){
                max = length[i];
            }
            if(length[i] == 1){
                all_one++;
            }
        }
        if(all_one == length.size()){
            return -1;
        }
        return max;
    }
};
// top solution
class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        map<int, int> streak;
        sort(nums.begin(), nums.end());
        int res = -1;
        for(int i : nums){
            int s = sqrt(i);
            if(s*s == i && streak.find(s)!= streak.end()){
                streak[i] = streak[s] + 1;
                res = max(res, streak[i]);
            }
            else{
                streak[i] = 1;
            }
        }
        return res;
    }
};