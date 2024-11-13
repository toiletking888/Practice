class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        sort(items.begin(), items.end());
        vector<vector<int> > map;
        vector<int> ans;
        int price_temp = items[0][0];
        for(int i = 0;i < items.size()-1;i++){
            if(price_temp != items[i][0]){
                price_temp = items[i+1][0];
                map.push_back(items[i]);
            }
        }
        
        for(int i = 0;i < queries.size();i++){
            int key = queries[i];
            int left = 0;
            int right = map.size()-1;
            while(left <= right){
                int mid = left + (right - left) / 2;
                if(key == map[mid][0]){
                    ans.push_back(map[mid][1]);
                    continue;
                }
                else if(key < map[mid][0]){
                    right = mid - 1;
                }
                else if(key > map[mid][0]){
                    left = mid + 1;
                }
            }
            ans.push_back(0);
        }
        return ans;
    }
};
// top solution

class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        sort(items.begin(), items.end());
        vector<int> beautyMax(items.size());
        vector<int> ans(queries.size());
        beautyMax[0] = items[0][1];
        for(int i = 1;i < items.size();i++){
            beautyMax[i] = max(beautyMax[i-1], items[i][1]);
        }
        
        for(int i = 0;i < queries.size();i++){
            int key = queries[i];
            vector<int>&& target = {key, INT_MAX};
            int j = upper_bound(items.begin(), items.end(), target) - items.begin();
            if(j == 0) ans[i] == 0;
            else ans[i] = beautyMax[j-1];
        }
        return ans;
    }
};