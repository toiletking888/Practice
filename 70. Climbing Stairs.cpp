class Solution {
public:
    int climbStairs(int n) {
        int temp = 0;
        vector<int> arr;
        arr.push_back(1);
        arr.push_back(1);
        for(int i = 2;i <= n;i++){
            temp = arr[i-1]+arr[i-2];
            arr.push_back(temp);
        }
        return arr[n];
    }
};

//top solution
class Solution {
public:
    int climbStairs(int n) {
        if (n == 0 || n == 1) {
            return 1;
        }
        int prev = 1, curr = 1;
        for (int i = 2; i <= n; i++) {
            int temp = curr;
            curr = prev + curr;
            prev = temp;
        }
        return curr;
    }
};