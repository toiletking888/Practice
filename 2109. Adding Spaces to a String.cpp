class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        int index = 0;
        int temp_index = spaces[index];
        string ans;
        for(int i = 0;i < s.length();i++){
            if(i == temp_index){
                ans += " ";
                if(index + 1 < spaces.size()) index++;
                temp_index = spaces[index];
            }
            ans += s[i];
        }
        return ans;
    }
};
//top solution:
