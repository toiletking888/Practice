class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        int sum = 0;
        int ans = 0;
        unordered_map<int, int> ban;
        for(int i : banned){
            ban.emplace(i, i);
        }
        for(int i = 1;i <= n;i++){
            if((sum + i <= maxSum) && (ban.find(i) == ban.end())){
                sum += i;
                ans++;
            }
        }
        return ans;
    }
};
// top
class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        // Create a set to mark banned numbers
        unordered_set<int> bannedSet(banned.begin(), banned.end());
        
        long long sum = 0; // Track cumulative sum
        int count = 0;     // Track count of valid numbers

        // Iterate through 1 to n
        for (int i = 1; i <= n; i++) {
            if (bannedSet.count(i)) continue; // Skip banned numbers
            sum += i; // Add current number to the sum
            if (sum > maxSum) break; // Stop if sum exceeds maxSum
            count++; // Increment count of valid numbers
        }

        return count; // Return the count of valid numbers
    }
};