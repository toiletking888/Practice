class Solution {
public:
    bool canMakeSubsequence(string str1, string str2) {
        int i = 0, j = 0, check = 0;
        while(i < str2.length() && j < str1.length()){
            if(str2[i] == str1[j]){
                i++;
                j++;
                continue;
            }
            if(str1[j] + 1 > 'z'){
                str1[j] = 'a';
            }
            else{
                str1[j] += 1;
            }
            if(str2[i] == str1[j]){
                i++;
                j++;
            }
            else{
                j++;
            }
        }
        if(i == str2.length()) return true;
        return false;
    }
};
//top Solution
class Solution {
public:
    bool canMakeSubsequence(string source, string target) {
        int targetIdx = 0;
        int targetLen = target.length();
        for (char currChar : source) {
            if (targetIdx < targetLen && (target[targetIdx] - currChar + 26) % 26 <= 1) {
                targetIdx++;
            }
        }
        return targetIdx == targetLen;
    }
};