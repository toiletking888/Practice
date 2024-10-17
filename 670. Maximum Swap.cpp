// failed one
class Solution {
public:
    int maximumSwap(int num) {
        string s = to_string(num);
        int i = 0, j = s.length()-1;
        vector<vector<int> > max;
        vector<int> temp;
        while(i < j){
            if(s[i] - s[j] < 0){
                temp.push_back(s[j] - s[i]);
                temp.push_back(i);
                temp.push_back(j);
                max.push_back(temp);
                temp.clear();
                j--;
            }
            else{
                i++;
            }
        }
        int max_diff = -1, first_i = 0, first_j = 0;
        for(int k = 0;k < max.size();k++){
            if(max[k][0] > max_diff){
                max_diff = max[k][0];
            }
        }
        for(int k = 0;k < max.size();k++){
            if(max[k][0] == max_diff){
                first_i = max[k][1];
                first_j = max[k][2];
                break;
            }
        }
        swap(s[first_i], s[first_j]);
        int ans = stoi(s);
        return ans;
    }
};

// success one
class Solution {
public:
    int maximumSwap(int num) {
        int max_index = -1, swap1 = -1, swap2 = -1;
        string s = to_string(num);
        for(int i = s.length()-1; i >= 0;i--){
            if(max_index == -1 || s[i] > s[max_index]){
                max_index = i;
            }
            else if(s[i] < s[max_index]){
                swap1 = i;
                swap2 = max_index;
            }
        }
        if(swap1 != -1 && swap2 != -1){
            swap(s[swap1], s[swap2]);
        }
        return stoi(s);
    }
};