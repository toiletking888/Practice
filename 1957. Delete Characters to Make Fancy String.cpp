class Solution {
public:
    string makeFancyString(string s) {
        string ans;
        int count = 1;
        for(int i = 0;i < s.length()-1;i++){
            if(s[i+1] == s[i]){
                if(count < 3){
                    ans += s[i];
                }
                count++;
            }
            else{
                if(count < 3){
                    ans += s[i];
                }
                count = 1;
            }
        }
        if(count <= 2){
            ans+=s[s.length()-1];
        }
        return ans;
    }
};
//top solution
class Solution {
public:
    string makeFancyString(string s) {
        string result;
        for (char c : s) {
            int n = result.size();
            if (n < 2 || !(result[n - 1] == c && result[n - 2] == c)) {
                result += c;
            }
        }
        return result;
    }
};