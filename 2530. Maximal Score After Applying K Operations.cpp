class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        priority_queue<int> maxHeap;
        long long score = 0;
        int temp = 0;
        for(int n: nums){
            maxHeap.push(n);
        }
        while(k > 0){
            score += maxHeap.top();
            temp = maxHeap.top();
            maxHeap.pop();
            maxHeap.push(ceil(temp/3.0));
            k--;
        }
        return score;
    }
};